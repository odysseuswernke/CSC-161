#include <stdio.h>

/**
 * Exchange the values in two locations
 * \param p A pointer to one value
 * \param q A pointer to another value
 * \post The values at p and q have been exchanged
 */
void exchange(double* p, double* q) {
  double p_before = *p;
  double q_before = *q;
  *p = q_before;
  *q = p_before;
}

int main() {
  double p = 123.45;
  double q = 543.21;
  exchange(&p, &q);
  printf("p: %f, q: %f\n", p, q);
}
