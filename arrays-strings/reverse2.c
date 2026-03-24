#include <stdio.h>
#define LENGTH 100
int main() {
  
  char reversed_message[LENGTH] = {' '};
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
  
  for (int i = (counter - 1), i2 = 0; i > -1; i--, i2++) {
    reversed_message[i2] = user_input[i];
  }
  printf("%s", reversed_message);
  printf("\n");
  return 0;
}
