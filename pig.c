#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pigify.h"
#include "pig.h"

/** This program reads input flags if any are entered and if not calls the translation function 
 * to translate from English to Pig Latin.
 */

int main(int argc, char *argv[]){
  if (argc > 1) {
    if ( ((strcmp(argv[1], "-?")) == 0) || ((strcmp(argv[1], "-h")) == 0) ) {
	printf("Welcome to pig! Pig is a c program that converts words in English to Pig Latin. To use it just run the program and start typing!\n");
	return 0;
      }
    else {
      printf("Unknown flag! Please rerun the program.\n");
      return 0;
    }
  }
