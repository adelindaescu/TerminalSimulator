/*******************************************************************************
 **
 ** Module Name: uniq.c
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
   char currentline[1024], previousline[1024];
   int line, ch, o, lines = 0, sw = 0, i;
   FILE *file;

   /*
    * Define text help and
    * version commands;
    */
   char * const help = "Usage: uniq [PARAMS] [PATH]\n Show file contents.\n\nParameters:\n\t-h, shows this help\n\t-a, shows version and author\n\t-n, number of lines to show\n";
   char * const author = " Author: Adelin Daescu\n Version: 1\n";

   while ((o = getopt(argc, argv, "ahuid")) != -1) {
       switch(o) {
               fprintf(stdout, "%s\n",help);
               return 0;
          case 'a':
               fprintf(stdout, "%s\n", author);
               return 0;
          case 'i':
                sw = 1;
                break;
          case 'd':
                sw = 2;
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
   //return to the beginning of the file.
   fseek(file, 0, SEEK_SET);
   if(sw == 0){ //if no params
   fgets(previousline,sizeof(file),file);
   previousline[strlen(previousline) - 1] = '\0'; // initialize previousline with first line
   printf("%s\n",previousline);
   //printf("prevline: %s\n",previousline);
   while (fgets(currentline, sizeof(file), file) != NULL)
   {
     currentline[strlen(currentline) - 1] = '\0'; // eat the newline fgets() stores
     if(strcmp(previousline,currentline)==0)
     //printf("%s\n",currentline);
     printf("");
     else
      printf("%s\n",currentline);
      strcpy(previousline,currentline);
    }
  }
  else if (sw == 1) //if -i (lowercase)
  {
    { //if no params
    fgets(previousline,sizeof(file),file);
    for (i=0;i<=strlen(previousline);i++)
    previousline[i] = tolower(previousline[i]);
    previousline[strlen(previousline) - 1] = '\0'; // initialize previousline with first line
    printf("%s\n",previousline);
    //printf("prevline: %s\n",previousline);
    while (fgets(currentline, sizeof(file), file) != NULL)
    {
      for (i=0;i<=strlen(currentline);i++)
      currentline[i] = tolower(currentline[i]);
      currentline[strlen(currentline) - 1] = '\0'; // eat the newline fgets() stores
      if(strcmp(previousline,currentline)==0)
        //printf("%s\n",currentline);
        printf("");
      else
        printf("%s\n",currentline);
      strcpy(previousline,currentline);
     }
    }
    }
    else if( sw == 2)
    {
      { //if no params
      fgets(previousline,sizeof(file),file);
      previousline[strlen(previousline) - 1] = '\0'; // initialize previousline with first line
      printf("%s\n",previousline);
      //printf("prevline: %s\n",previousline);
      while (fgets(currentline, sizeof(file), file) != NULL)
      {
        currentline[strlen(currentline) - 1] = '\0'; // eat the newline fgets() stores
        if(strcmp(previousline,currentline) == 0)
        printf("%s\n",currentline);
         strcpy(previousline,currentline);
       }
   }
    }
    printf("File has %d lines.\n",lines);
    fclose(file);
    return 0;
  }
