/*
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pigify.h"

/* External Functions Declarations */
void pigify(char (*)[]);
void anglofy(char (*)[]);
int is_vowel(char, int);
void push(char (*)[], int *, const char);
void flush_buffer(char(*)[], const size_t);
int push_th();
int flush_buffer_th();
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

/** Rearranges the elements in an array to undo the Pig Latin translation.
 *
 * The algorithm is as follows:
 * 
 * First find the index of the third to last character in the array and its corresponding value. We do this because the Pig Latin ending will either be the three letters "yay" or a non-y letter followed
 * by "ay". 
 * We find this by looping through the indicies of the array until the value of the current index + 3 is equal to the null character ('\0'). This provides us with the third to last character because 
 * all indicies in the array after the last character will be null. We store this character in a char variable "third" and the index in an int variable "index".
 * Next, to figure out how to unpigify the word, we figure out which of the two cases the current word falls under. The two cases are if the third to last letter is a 'y' (making the ending "yay") which 
 * means the word had a vowel as its first letter or if the third to last letter isn't a 'y' (making the ending "ay") then there were some unknown number of consonants that came before the first vowel. 
 * If the word falls under the first case, then to unpigify it we simply remove the last three indicies by looping from index to index + 3 and setting those values to the null character. 
 * If the word falls under the second case, then to unpigify it we first remove the ending, which will be a non-y letter followed by "ay". To unpigify after removing the ending we need to put the former
 * third to last letter (stored in "third") at the front (Note: we realize that this won't always produce an accurate translation into English as that will only work if the original English word had 
 * only one consonant before the first value. However this still accurately unpigifies a word as it removes the pig latin ending and attempts to rearrange the letters to form an English word. Since we 
 * don't know how many letters came before the first vowel this will give us a close approximation and follows the integrity of the assignment as we were told to not worry about whether or not the 
 * unpigify produces an English word so long as it properly removes the Pig Latin aspect of the word).
 * This is done in the same manner as removing the "yay" ending described in the first case. After this we shift all the values at each index to the right by one to leave a space at the front of the 
 * array for the former third to last letter. After all values are properly shifted we place the "third" value in the first index (0th) of the array. 
 *
 * This produces an accurate removal of the Pig Latin translation. 
 *
 */
void anglofy(char (*arr)[]) {
  char third = '\0';
  int index;
  for (int i = 0; i < BUFFER_LENGTH; i++) {
    if ((*arr)[i+3] == '\0'){
      third = (*arr)[i];
      index = i;
      break;
    }
  }
  if (third == 'y') {
    for (int k = index; k < index + 3; k++)
      (*arr)[k] = '\0';
  }
  else {
    for (int j = index; j < index + 3; j++) (*arr)[j] = '\0';
    for (int l = index; l > 0; --l) (*arr)[l] = (*arr)[l -1];
    (*arr)[0] = third;
  }
}

/** Validates whether a given char is a vowel. 
 * This is done by checking if the char is an a, e, i, o, or u or if it is a y
 * and not the first char in the array (signified by count being > 0). If it is a vowel then 
 * the function returns 0 indicating true and if not it return 1 indicating false. 
 */
int is_vowel(char ch, int count) {
 ch = tolower(ch);
 switch(ch){
 case 'a': case 'e': case 'i': case 'o': case 'u': return 0;
 case 'y': if (count > 0) return 0;
 default: return 1;
 }
}


/** Flushes a given buffer.
 * This method flushes an input buffer given the array and its associated count representing the size of the array. We loop through the indicies from 0 to count, print the value at each index, and then 
 * set the corresponding value to be the null character as flushed arrays have null characters for all of their indicies. 
 */ 
void flush_buffer(char (*buffer)[], size_t count){
  for(size_t i = 0; i < count; ++i) {
    printf("%c", (*buffer)[i]);
    (*buffer)[i] = '\0';
  }
}

/** Pushes an element to a specified index in a given array.
 * Given the input element, corresponding index, and array, we set the array's value at the index to be the element.
 */
void push(char (*arr)[], int *index, const char element){
  (*arr)[(*index)++] = element; 
}

/** Test hook.
 * Tests the functionality of the push() method. 
 */
int push_th(){
  char buffer[10] = {'h','e', 'l', 'l'};
  int index = 4;
  push(&buffer, &index, 'o');
  if( index != 5 )  { printf("Index does not increment\n"); return 0; }
  if( buffer[4] != 'o' ) { printf("Element was not added correctly"); return 0; }

  return 1;
}

/** Test hook.
 * Tests the functionality of the flush_buffer() method. 
 */
int flush_buffer_th(){
  // Test hook for flush_buffer
  char buffer[10] = {'h','e','l','l','o'};
  flush_buffer(&buffer, 5);
  for(int i = 0; i < 10; ++i)
    if( buffer[i] != '\0' ) return 0;

  return 1;
}
