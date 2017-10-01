/*
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/// Macro with 100 slots for characters, 3 slots for pig-latin endings
#define BUFFER_LENGTH 103



/* Static Functions Declarations */
static void pigify(char (*)[]); 
/* External Function Declarations */
int is_vowel(char, int);
// End of function declarations //


/** Rearranges the indices of an array
 *
 *
 */
void pigify(char (*arr)[]) {
  char local_arr[BUFFER_LENGTH], ay[3], yay[4];
  int count = 0;
  strcpy(ay, "ay");
  strcpy(yay, "yay");
  for (int i = 0; i < BUFFER_LENGTH; i++) {
    if ((*arr)[i] == '\0') break;
    int valid = is_vowel((*arr)[i], i);
    if (valid == 0) {
      if (i == 0) {
	strcat((*arr), yay);
	break;
      }
      else if (i > 1) {
	for (int j = 0; j < BUFFER_LENGTH; j++) { if (local_arr[j] == '\0') break; else count++; }
	for (int k = 0; k < BUFFER_LENGTH; k++) { 
	  (*arr)[k] = (*arr)[k+count];
	  (*arr)[k+count] = '\0';
	}
	strcat((*arr), local_arr);
	strcat((*arr), ay);
  break;
      }
    }
    else {
      local_arr[i] = (*arr)[i];
    }
  }
}

int is_vowel(char ch, int count) {
 ch = tolower(ch);
 switch(ch){
 case 'a': case 'e': case 'i': case 'o': case 'u': return 0;
 case 'y': if (count > 0) return 0;
 default: return 1;
 }
}
