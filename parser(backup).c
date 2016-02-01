#include <string.h>
#include <stdlib.h>

int parseString(char* input, char*** words, int* size) {
    char *word;

    *words = malloc(sizeof(char*));
    word = strtok(input, " \n\t");

    while (word != NULL) {
        (*words)[*size] = malloc(strlen(word) + 1);
        strcpy((*words)[*size], word);
        (*size)++;
        *words = realloc(*words, ((*size) + 1) * sizeof(char*));
        word = strtok(NULL, " \n\t");
    }

    /* null terminated */
    (*words)[*size] = malloc(sizeof(char) + 1);
    (*words)[*size] = '\0';
    (*size)++;

    return 0;
}

