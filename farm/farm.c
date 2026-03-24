#include <stdio.h>
#include "chicken.h"
#include "cow.h"
#include "sheep.h"

int main() {
  printf("Welcome to the farm simulator!\n");
  printf("This farm has:\n");
  printf("  - ten chickens\n");
  printf("  - four cows\n");
  printf("  - eight sheep\n");
  printf("Please enjoy.\n\n");

  chicken_sound(11);
  cow_sound(4);
  sheep_sound(8);

  return 0;
}
