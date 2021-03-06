#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "parser.h"
#include "pathBuilder.h"
#include "internalCommands/cd.h"                 

int main() {
    int  pid, status;
    char cwd [1024];
    int* numberOfCommands = 0;
    char* word;
    //char input[255];                /* inserted by the user */
    char* input;
    char** commandWithArguments;    /* contains the words in the input */
    char* programName;              /* the command preceded by it's path */
    int numberOfWords = 0;           /* number of words in the input */
    int i = 0;

    while (1) {
        //printf("$>");
        fflush(stdout);
        getcwd(cwd, sizeof(cwd));
        //fgets(input, sizeof(input), stdin);
        printf("%s",cwd);
        input = readline("$> ");             
        if (strlen(input) > 0) {
                add_history(input);
				}
        numberOfWords = 0;

        word = strtok(input, "|");
        while (word != NULL) {
            numberOfWords++;
            parseString(word, &commandWithArguments, &numberOfWords);


        /* no command was inserted */
        if (commandWithArguments[0] == NULL) {
            free(commandWithArguments);
            continue;
        }

        if (strcmp(commandWithArguments[0], "exit") == 0) {
            return 0;
        }
        if (strncmp(commandWithArguments[0],"cd", 2) == 0) {
            changeDirectory(numberOfWords - 1, commandWithArguments);
            continue;
        }                                                                                 
        programName = buildPath(commandWithArguments[0]);
        //printf("%s", commandWithArguments);
        pid = fork();
        if (pid == 0) {
            /* child */
            if(execv(programName, commandWithArguments)<0)
                printf("%s: command is not supported or does not exist.\n",word);
        }
        else {
            /* parent */
            waitpid(pid, &status, WUNTRACED);

            if (programName != NULL) {
                free(programName);
            }

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
            word=strtok(NULL, "|");
    }
    }
}
