#include <assert.h>
#include <stdio.h>
#include "pigify.h"

/** Testing Pigify function
 * 
 */
void test_pigify(){
  char arr[BUFFER_LENGTH] = {'h','e','l','l','o'};
  char ref[BUFFER_LENGTH] = {'e','l','l','o','h','a','y'};
  pigify(&arr);
  assert( arr[0] == 'e' );
  for(int i = 0; arr[i] != '\0'; ++i) { assert ( arr[i] == ref[i]); } 
}

void test_anglofy(){
  char arr[BUFFER_LENGTH]= {'e','l','l','o','h','a','y'};
  char ref[BUFFER_LENGTH] = {'h','e','l','l','o'};
  anglofy(&arr);
  for(int i = 0; arr[i] != '\0'; ++i) {  assert ( arr[i] == ref[i] ); }
}

void test_hooks(){
  assert( flush_buffer_th() == 1 );
  assert( push_th() == 1 );
}

int main(){
  test_pigify();
  test_anglofy();
  test_hooks();

  printf("All test cases passed!\n");
}
