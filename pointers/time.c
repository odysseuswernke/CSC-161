#include <stdio.h>

/**
 * Take in a total number of seconds and split it up into parts
 * 
 * \param total_seconds The input number of seconds
 * \param days    Output: the number of whole days in total_seconds
 * \param hours   Output: the number of whole hours in total_seconds
 * \param minutes Output: the number of whole minutes in total_seconds
 * \param seconds Output: the remaining seconds
 */
void split_time(int total_seconds, int* days, int* hours, int* minutes, int* seconds) {
  *days = total_seconds / 86400;
  total_seconds %= 86400;
  *hours = total_seconds / 3600;
  total_seconds %= 3600;
  *minutes = total_seconds / 60;
  total_seconds %= 60;
  *seconds = total_seconds;
  
}

int main() {
  
  int total_seconds = 86438;
  int days;
  int hours;
  int minutes;
  int seconds;

  split_time(total_seconds, &days, &hours, &minutes, &seconds);
  printf("In %d total seconds, there are %d days, %d hours, %d minutes, and %d seconds.\n", total_seconds, days, hours, minutes, seconds);
}
