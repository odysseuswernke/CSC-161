#include <stdio.h>
#include <stdint.h>

union number {
  uint32_t i_value;
  float f_value;
};

int main() {
  union number num;
  num.i_value = 0b11000000011100000000000000000000;

  printf("num.i_value is %u\n", num.i_value);
  printf("num.f_value is %.50f\n", num.f_value);

  return 0;
}
