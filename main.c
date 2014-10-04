#include <string.h>
#include <stdio.h>

int main() {
    char input[255];
    char *command;

    while (1) {
        printf("$> ");
        fgets(input, sizeof(input), stdin);

        command = strtok(input, " \n\t");

        while (command != NULL) {
            printf("%s", command);

            if (strcmp(command, "exit") == 0) {
                return 0;
            }
            command = strtok(NULL, " ");

            if (command != NULL) {
                printf("\n");
            }
        }
    }
}
