#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/** Valley girl function
 * Puts different phrases into stdout on interval
 */
void valley(int count){
  if(count%7 == 0) printf("like ");
  else if(count%18 == 0) printf("like wow! ");
  else if(count%10 == 0) printf("totally like ");
}

// Main function for valley girl
int main(){
  for(int c = getchar(), count = 0; c != EOF; c = getchar(), ++count){
    if(isspace(c)) { printf(" "); valley(count); }
    else
      printf("%c", c);
  }
}

