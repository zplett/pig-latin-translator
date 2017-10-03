#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pigify.h"


/** This program reads input flags if any are entered and if not calls the translation frunction to
 * undo Pig Latin translation. 
 */
int main(int argc, char *argv[]) {
  if (argc > 1) {
    if ( ((strcmp(argv[1], "-?")) == 0 ) || ((strcmp(argv[1], "-h")) == 0) ) {
      printf("Welcome to unpig! Unpig is a c program that reads in words in Pig Latin and removes the Pig Latin aspect of the word. To use it just run the program and start typing!\n");
      return 0;
    }
    else {
      printf("Unknown flag! Please rerun the program.\n");
      return 0;
    }
  }
  structure(&anglofy);
}
