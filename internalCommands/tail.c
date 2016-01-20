/*******************************************************************************
 **
 ** Module Name: tail.c
 **
 ** Project Name: UNIX CSHell
 **
 ********************************************************************************
 **
 ** Created By: adelin.daescu
 **
 ** Description: Implementation of the UNIX tail command;
 **
 ********************************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>


int main(int argc, char ** argv) {
    int o;
    long countlines= 0;
    char cbyte;
    FILE *file;
    int nlines = 10; // default 10 lines

    /*
     * Define text help and
     * version commands;
     */
    char * const help = "Usage: tail [PATH]\n Show file contents.\n\nParameters:\n\t-h, shows this help\n\t-u, shows version and author\n\t-c, number of lines to show\n";
    char * const author = " Author: Adelin Daescu\n Version: 1\n";

    // Reseting getopt internal index;
    optind = 0;

    while ((o = getopt(argc, argv, "huc")) != -1) {
        switch(o) {
            case 'h':
                fprintf(stdout, "%s\n",help);
                return 0;
                break;
            case 'u':
                fprintf(stdout, "%s\n", author);
                return 0;
                break;
            case 'c':
                if (optarg) {
                     nlines = (int)optarg;
                }
                break;
            case '?':
                return 1;
            default:
                abort();
        }
    }

    if(strcmp(argv[argc-1], "tail") == 0) {
        fprintf(stderr, "Tail needs at least one parameter\n");

        return 1;
    }

    const char *filePath = argv[argc-1];

    file = fopen(filePath, "r");

    if(file == NULL)
    {
        fprintf(stderr,"Error opening file: %s\n", filePath);
        return 1;
    }

    off_t fposition;
    fseek(file, 0, SEEK_END);
    fposition = ftell(file);
    off_t index = fposition;
    off_t end = fposition;

    for(index; index >= 0; index--)
    {
        cbyte= fgetc(file);
        if (cbyte == '\n' && (end - index) > 1)
        {
            countlines ++;
            if(countlines == nlines)
            {
                break;
            }
        }
        fposition--;
        fseek(file, fposition, SEEK_SET);
    }

    int fd;
    fd = fileno(file);
    int nread;
    char buffer[4096];
    lseek(fd, (fposition + 1), SEEK_SET);

    while((nread = read(fd, buffer, 4096)) > 0)
    {
        write(STDOUT_FILENO, buffer, nread);
    }

    fclose(file);

    return 0;
}
