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
 ** Description: Implementation of the UNIX uniq command;
 **
 ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int main(int argc, char ** argv) {
   char cline, previousline[1024];
   int line, ch, o, lines = 0;
   FILE *file;

   /*
    * Define text help and
    * version commands;
    */
   char * const help = "Usage: uniq [PATH]\n Show file contents.\n\nParameters:\n\t-h, shows this help\n\t-a, shows version and author\n\t-n, number of lines to show\n";
   char * const author = " Author: Adelin Daescu\n Version: 1\n";

   while ((o = getopt(argc, argv, "ahuid")) != -1) {
       switch(o) {
               fprintf(stdout, "%s\n",help);
               return 0;
          case 'a':
               fprintf(stdout, "%s\n", author);
               return 0;
          case 'i':
                break;
          case 'd':
                break;
          case 'u':
                break;
          case '?':
               return 1;
          default:
               abort();
       }
   }

   const char *filePath = argv[argc-1];
  file = fopen(filePath, "r");
   if(file == NULL)
   {
       fprintf(stderr,"Error opening file: %s\n", filePath);
       return 1;
   }
   while(!feof(file))
   {
     ch = fgetc(file);
     if(ch == '\n')
     {
       lines++;
     }
   }

   fseek(file, 0, SEEK_SET);

   while (fgets(previousline, sizeof(file), file) != NULL)
   {
     previousline[strlen(previousline) - 1] = '\0'; // eat the newline fgets() stores
     printf("%s\n", previousline);
}
    printf("File has %d lines.\n",lines);
    return 0;
  }
