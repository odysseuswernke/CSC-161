#include <stdio.h>
#include <stdint.h>

int main() {
  uint16_t i = 0b0111111111111110;
  int16_t j = 0b1000000000000000;
  printf("j has decimal value %d\n", j);
  printf("\n%u\n", i);
  int32_t i1 = 1, i2 = 1;
  printf("%d\n", (i1 & i2));
  return 0;
}
