#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include "pigify.c"
#include "pig.h"

/* Static function definitions */
static void flush_buffer(char (*)[], size_t);
static void push(char (*)[], int *, const char);
/* External function definitions */
int flush_buffer_th();
int push_th(); 

/** This is the main function in pigify()
 *
 *

int main(int argc, char *argv[]){
  
}
*/
void flush_buffer(char (*buffer)[], size_t count){
  for(size_t i = 0; i < count; ++i) {
    printf("%c", (*buffer)[i]);
    (*buffer)[i] = '\0';
  }
}

void push(char (*arr)[], int *index, const char element){
  (*arr)[(*index)++] = element; 
}

int push_th(){
  char buffer[10] = {'h','e', 'l', 'l'};
  int index = 4;
  push(&buffer, &index, 'o');
  if( index != 5 )  { printf("Index does not increment\n"); return 0; }
  if( buffer[4] != 'o' ) { printf("Element was not added correctly"); return 0; }

  return 1;
}

int flush_buffer_th(){
  // Test hook for flush_buffer
  char buffer[10] = {'h','e','l','l','o'};
  flush_buffer(&buffer, 5);
  for(int i = 0; i < 10; ++i)
    if( buffer[i] != '\0' ) return 0;

  return 1;
}
