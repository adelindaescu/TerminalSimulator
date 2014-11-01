#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

char* buildPAth(char* programName) {
    char* pathAndName;
    struct stat info;
    char* localCommandPath;

    localCommandPath = malloc(strlen(programName) + sizeof("internalCommands/"));
    strncpy(localCommandPath, "internalCommands/", sizeof("internalCommands/"));
    strncat(localCommandPath, programName, strlen(programName));

    if (lstat(localCommandPath, &info) != 0) {
        // file does not exist in local directory
        if (errno == ENOENT) {
            // search file in /bin
            pathAndName = malloc(strlen(programName) + sizeof("/bin/"));
            strncpy(pathAndName, "/bin/", sizeof("/bin/"));
            strncat(pathAndName, programName, strlen(programName));
            return pathAndName;
        }
        else {
            return NULL;
        }
    }

    /* the file exists, search file in local directory */
    pathAndName = malloc(strlen(programName) + sizeof("internalCommands/"));
    strncpy(pathAndName, "internalCommands/", sizeof("internalCommands/"));
    strncat(pathAndName, programName, strlen(programName));
    return pathAndName;
}
