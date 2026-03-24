#include <stdio.h>

/**
 * Find the larger of two numbers and write the answer to result
 * \param m A number
 * \param n A number
 * \param result location for the larger of m and n
 */
void set_max(int m, int n, int* result) {
  if (m > n) {
    *result = m;
  } 
  else if (m == n) {
    *result = m;
  }
  else {
    *result = n;
  }
}

int main() {
  int m = 5;
  int n = 7;
  int max;

set_max(m, n, &max);
  printf("%d\n", max);
}
