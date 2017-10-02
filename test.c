#include <assert.h>
#include "pigify.c"
#include "pig.h"

/** Testing Pigify function
 * 
 */
void test_pigify(){
  char arr[BUFFER_LENGTH] = {'h','e','l','l','o'};
  char ref[BUFFER_LENGTH] = {'e','l','l','o','h','a','y'};
  pigify(&arr);
  assert( arr[0] == 'e' );
  for(int i = 0; arr[i] != '\0'; ++i) assert ( arr[i] == ref[i]); 
}

void test_hooks(){
  assert( flush_buffer_th() == 1 );
  assert( push_th() == 1 );
}

int main(){
  test_pigify();

  printf("All test cases passed!\n");
}
