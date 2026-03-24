#include <stdio.h>

// TODO: Define a new divide function here



int divide(int dividend, int divisor, int* quotient, int* remainder) {
  // Check for division by zero
  if (divisor == 0) {
    return -1;
  }
  *quotient = dividend / divisor;
  *remainder = dividend % divisor;
  return 0;
}



int main() {
  int x = 80;
  int y = 0;
  int answer;
  int remainder;
  if (divide(x, y, &answer, &remainder)) {
    printf("Error: attempted to divide by zero.\n");
  } else {
   printf("x/y is %d. remainder is %d\n", answer, remainder);
  }

}
