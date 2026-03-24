#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define INVALID 5


// Randomly choose ROCK, PAPER, or SCISSORS and return it
int computer_choose_rps() {
  int value = rand() % 3;
  if (value == 0) {
    return ROCK;
  } else if (value == 1) {
    return PAPER;
  } else {
    return SCISSORS;
  }
}


// Ask the user to choose ROCK, PAPER, or SCISSORS and return the choice
int user_choose_rps() {
  // Use scanf to read in an integer
  int user_value;
  int num_values_read = scanf("%d", &user_value);

  // Clear any remaining input from the user
  while (getchar() != '\n') {}

  // Print the value, if there was one
  if (num_values_read == 1) {
    if (user_value == 1) {
      return ROCK;
    } else if (user_value == 2) {
      return PAPER;
    } else if (user_value == 3) {
      return SCISSORS;
    }
    else {
    return INVALID;
  }}
  
  else {
    return INVALID;
  }}


// Determines if the user and computer tie.
bool is_tie(int user_choice, int computer_choice) {
  if (user_choice == computer_choice) {
    return true;
  }
  else {
    return false;
  }
}


// Determines if the user wins.
bool is_win(int user_choice, int computer_choice) {
  if (user_choice == ROCK && computer_choice == SCISSORS) {
    return true;
  }
  else if (user_choice == PAPER && computer_choice == ROCK) {
    return true;
  }
  else if (user_choice == SCISSORS && computer_choice == PAPER) {
    return true;
  }
  else {
    return false;
  }}


/*This prompts the user to either keep playing or quit.
We know this was supposed to return a boolean value, but to make sure the user made valid input,
it seemed easier to return a 1, 2, or "INVALID" value, similar to boolean true and false. */
int user_prompt_again() {

  printf("Do you want to play again?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  printf("Enter the number for your choice: ");

  // Use scanf to read in an integer
  int user_persistence;
  int num_values_read = scanf("%d", &user_persistence);

  // Clear any remaining input from the user
  while (getchar() != '\n') {}

  // Print the value, if there was one
  if (num_values_read == 1) {
    if (user_persistence == 1) {
      return 1;
    } 
    else if (user_persistence == 2) {
      return 2;
    } 
    else {
    return INVALID;
    }}
  
  else {
    return INVALID;
  }
}



int main() {

  int user_persistence = 1;
  int user_win_count = 0;
  int computer_win_count = 0;
  int tie_count = 0;

  while (user_persistence == 1) {
  // This prompts the user to choose rock, paper, or scissors.
  printf("\nWhat move do you want to play?\n");
  printf("1. Rock\n");
  printf("2. Paper\n");
  printf("3. Scissors\n");
  printf("Enter the number for your choice: ");

  int user_choice = user_choose_rps();

  while (user_choice == INVALID) {
    printf("Please type an integer, 1-3: ");
    user_choice = user_choose_rps();
  }

  // This prints the user's choice.
  if (user_choice == ROCK) {
    printf("\nYou chose rock.\n");
  }
  else if (user_choice == PAPER) {
    printf("\nYou chose paper.\n");
  }
  else {
  printf("\nYou chose scissors.\n");
  }

  int computer_choice = computer_choose_rps();

  if (computer_choice == ROCK) {
    printf("The computer chose rock.\n");
  } 
  else if (computer_choice == PAPER) {
    printf("The computer chose paper.\n");
  } 
  else {
    printf("The computer chose scissors.\n");
  }

  //Check who wins the game.hoice
  if (is_win(user_choice, computer_choice)) {
    printf("You win!\n\n");
    user_win_count++;
  }
  else if (is_tie(user_choice, computer_choice)) {
    printf("It is a tie.\n\n");
    tie_count++;
  }
  else {
    printf("The computer wins!\n\n");
    computer_win_count++;
  }

  printf("Wins: %d\n", user_win_count);
  printf("Ties: %d\n", tie_count);\
  printf("Losses: %d\n\n", computer_win_count);


  //Asks the user if they want to play again.
  user_persistence = user_prompt_again();
  
  while (user_persistence == INVALID) {
    printf("\nPlease enter an integer, 1-2.\n");
    user_persistence = user_prompt_again();
  }
 
}}
