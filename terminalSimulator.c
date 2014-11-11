#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "pathBuilder.h"

int main() {
    int  pid, status;
    char input[255];                /* inserted by the user */
    char** commandWithArguments;    /* contains the words in the input */
    char* programName;              /* the command preceded by it's path */
    int numberOfWords = 0;           /* number of words in the input */
    int i = 0;

    while (1) {
        printf("$>");
        fflush(stdout);
        fgets(input, sizeof(input), stdin);
        numberOfWords = 0;
        parseString(input, &commandWithArguments, &numberOfWords);

        if (strcmp(commandWithArguments[0], "exit") == 0) {
            return 0;
        }

        programName = buildPath(commandWithArguments[0]);

        printf("%s\n", programName);
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
            for (i = 0; i < numberOfWords; i++) {
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
	// comm 3
}

