/*
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/// Macro with 100 slots for characters, 3 slots for pig-latin endings
#define BUFFER_LENGTH 103

/* External Functions Declarations */
void pigify(char (*)[]);
void anglofy(char (*)[]);
int is_vowel(char, int);
// End of function declarations //


/** Rearranges the entered array (representing a word in English) to represent a word in Pig Latin.
 *
 * The Algorithm is as follows: 
 *
 * Iterate through each index in the array:
 * If the current index is the null character ('\0') then break out of the for loop.
 * If the current index isn't the null character, then call the helper function is_vowel().
 * This function takes in a character and a count (representing the char's place in the array). If it's an a,e,i,o,u, or a y - provided the y isn't the first char in the array, then return 0
 * indicating that the given character is a vowel, otherwise return 1 meaning the character isn't a vowel. 
 * If the character isn't a vowel, then add it to the array local_arr. This array represents all the consonants in the word that come before the first vowel. After the first vowel is found, these will 
 * be concatenated to the end of the array before adding the Pig Latin ending ("yay" or "ay").
 * If the character is a vowel, then check if it's the first index of the word. 
 * If the vowel is the first index in the word, concatenate the string "yay" (represented by the array yay).
 * If the vowel isn't the first index in the word, find the length of local_arr (the amount of letters to be moved to the back of the array).
 * Use this value to "shift" the letters in the array down by the value. This is done by iterating through the indicies in the word array and setting the value of each index equal to the value at 
 * that index + the value representing the number of letters in local_arr and setting the value at index + length of local_arr to null. 
 * After all the shifting has been completed, concatenate the input arr with local_arr to have the removed letters placed on the end of the word. This is followed by concatenating the "ay" string
 * on to the end of the arr vis a vis the ay array. 
 * 
 * This produces the correctly "pigified" word.
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

void anglofy(char (*arr)[]) {
  for (int i = 0; i < BUFFER_LENGTH; i++) { if (arr[i+3] == '\0') char third = arr[i]; int index = i; }
  if (third == 'y') { for (int k = index; k < index + 3; k++) arr[k] = '\0'; }
  else {
    for (int j = index; j < index + 3; j++) arr[j] = '\0';
    for (int l = 0; l < BUFFER_LENGTH-1; l++) arr[l] = arr[l+1];
    arr[0] = third;
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
