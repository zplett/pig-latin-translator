#include <stdio.h>

#define BUFFER_LENGTH 102

void pigify(static char (*)[]); 
int is_vowel(char, int);

int main() {
  
}

void pigify(static char (*arr)[]) {
  char local_arr[BUFFER_LENGTH], ay[2], yay[3];
  int count = 0;
  strcopy(ay, "ay");
  strcopy(yay, "yay");
  for (i = 0; i < BUFFER_LENGTH; i++) {
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
 switch(ch):
 case 'a': case 'e': case 'i': case 'o': case 'u': return 0;
 case 'y': if (count > 0) return 0;
 default: return 1;
}
