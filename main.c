#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

int main() {
    int  pid, status;
    char input[255];
    char** commandWithArguments;
    char* programName;
    int size = 0, i = 0;

    while (1) {
        printf("$>");
        fflush(stdout);
        fgets(input, sizeof(input), stdin);
        size = 0;
        parseString(input, &commandWithArguments, &size);

        if (strcmp(commandWithArguments[0], "exit") == 0) {
            return 0;
        }

        programName = malloc(sizeof(commandWithArguments[0]) + sizeof("/bin/"));
        strncpy(programName, "/bin/", sizeof("/bin/"));
        strncat(programName, commandWithArguments[0], strlen(commandWithArguments[0]));

        pid = fork();
        if (pid == 0) {
            /* child */
            execv(programName, commandWithArguments);
        }
        else {
            /* parent */
            waitpid(pid, &status, WUNTRACED);

            free(programName);

            /* free memory for each word in the array */
            for (i = 0; i < size; i++) {
                if (commandWithArguments[i] != NULL) {
                    free(commandWithArguments[i]);
                }
            }

            /* free memory for the array of words */
            if (commandWithArguments != NULL) {
                free(commandWithArguments);
            }

        }
    }
}
