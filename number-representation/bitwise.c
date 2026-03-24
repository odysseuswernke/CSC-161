#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool bit_test(uint32_t value, uint8_t index) {
  value = value >> index;
  return (value & 1);
}

uint32_t bit_set(uint32_t value, uint8_t index) {
  // TODO: implement me
  return 0;
}

uint32_t bit_clear(uint32_t value, uint8_t index) {
  // TODO: implement me
  return 0;
}

int main() {
  // Test bit_test
  uint32_t value = 129;
  printf("Bit 0 of %u is %s\n", value, bit_test(value, 0) ? "set" : "not set");
  printf("Bit 3 of %u is %s\n", value, bit_test(value, 3) ? "set" : "not set");
  printf("Bit 7 of %u is %s\n", value, bit_test(value, 7) ? "set" : "not set");

  // Test bit_set
  printf("The value %u with bit 3 set is %u\n", value, bit_set(value, 3));
  printf("The value %u with bit 0 set is %u\n", value, bit_set(value, 0));
  printf("The value %u with bit 9 set is %u\n", value, bit_set(value, 9));

  // Test bit_clear
  printf("The value %u with bit 0 cleared is %u\n", value, bit_clear(value, 0));
  printf("The value %u with bit 5 cleared is %u\n", value, bit_clear(value, 5));
  printf("The value %u with bit 7 cleared is %u\n", value, bit_clear(value, 7));

  return 0;
}
