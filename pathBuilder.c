#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* buildPAth(char* programName) {
    char* pathAndName;
    pathAndName = malloc(sizeof(programName) + sizeof("/bin/"));
    strncpy(pathAndName, "/bin/", sizeof("/bin/"));
    strncat(pathAndName, programName, strlen(programName));
    return pathAndName;
}