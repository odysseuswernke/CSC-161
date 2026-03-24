#include <stdio.h>
#define LENGTH 100
int main() {
  
  char user_input[LENGTH] = {' '};
  printf("Enter a message: ");
   // Clear any remaining input from the user
  int counter = 0;
  while ((counter < 100)) {

    char temp = getchar();
    if (temp == '\n') {
      break;
    } else {
      user_input[counter] = temp;
    }
    counter++;
  }
  
  for (int i = (counter); i > -1; i--) {
    printf("%c", user_input[i]);
  }
  printf("\n");
  return 0;
}
