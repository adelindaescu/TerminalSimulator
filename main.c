#include <string.h>
#include <stdio.h>


int main() {
    char input[255];
    char* command;

    printf("$> ");
    fgets(input, sizeof(input), stdin);

    command = strtok(input, " ");

    while (command !=  NULL) {
        printf("%s\n", command);
        command = strtok(NULL, " ");
    }

    return 0;
}
