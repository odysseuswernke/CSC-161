#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INPUT_LENGTH 10

//Need to implement user input validation in cells and valid choices.

//This prints the current board.
void print_board(char board[]) {
  int i = 0;
  while (i < 9) {
    if (i % 3 == 0) {
      printf("\n------\n%c|", board[i]);
    }
    else {
      printf("%c|", board[i]);
    }
    i++;
  }
  printf("\n");
}

//This gets user input for the user's choice on the board.
int get_move(char board[], char* current_turn_pointer) {
  int value;
  do {
    // As the user to type a number
    printf("Enter the number of the cell to place an \"%c\":\n", *current_turn_pointer);

    // Create an array to hold user input
    char input[INPUT_LENGTH];

    // Read user input and check for errors
    if (fgets(input, INPUT_LENGTH, stdin) == NULL) {
      fprintf(stderr, "Failed to read input from user.\n");
      exit(EXIT_FAILURE);
    }

    // Convert the input to an integer
    value = atoi(input);

  } while (!(value <= 9 && value >= 1) || board[(value - 1)] == 'x' || board[(value - 1)] == 'o');
  return value;
}

void switch_turn(char* current_turn_pointer) {
  if (*current_turn_pointer == 'x') {
    *current_turn_pointer = 'o';
  }
  else {
    *current_turn_pointer = 'x';
  }
}

//This checks rows, columns, and diagonals for wins.
bool check_win(char board[], char* current_turn_pointer){
  //if 3 in a row
  if(
    //rows
     ((board[0]==board[1]) && (board[1]==board[2])) ||
     ((board[3]==board[4]) && (board[4]==board[5])) ||
     ((board[6]==board[7]) && (board[7]==board[8])) ||
     //columns
     ((board[0]==board[3]) && (board[3]==board[6])) ||
     ((board[1]==board[4]) && (board[4]==board[7])) ||
     ((board[2]==board[5]) && (board[5]==board[8])) ||
     //diagonals
     ((board[0]==board[4]) && (board[4]==board[8])) ||
     ((board[2]==board[4]) && (board[4]==board[6]))){
      return true;
     }
     return false;
}

//This checks whether or not the user wants to keep playing.
int check_user_persistence(void) {
  int value;
  do {
    // Show a prompt message
    printf("Do you want to play again? (yes = 1, no = 0): ");

    // Use scanf to read in an integer
    int num_values_read = scanf("%d", &value);

    // Clear any remaining input from the user
    while (getchar() != '\n') {}

    // Print the value, if there was one
    if (num_values_read == 1) {
      printf("You typed %d\n", value);
    } else {
      printf("You didn't type an integer.\n");
    }
  } while (!(value == 1 || value == 0));

  return value;
}



int main() {

    // TODO: Implement tic-tac-toe here
  char current_turn = 'x';
  char* current_turn_pointer = &current_turn;
  int user_persistence = 1;

  do {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int turn = 0; turn < 9; turn++) {
      printf("\nIt's player %c's turn.", current_turn);
      print_board(board);
      int choice = get_move(board, current_turn_pointer);
      //0-based index. We subtract 1 from user choice to change index.
      board[(choice - 1)] = current_turn;
      switch_turn(current_turn_pointer);

      if (check_win(board, current_turn_pointer) == true) {
        printf("Player %c has won.\n", current_turn);
        break;
      }
      else {
        continue;
      }
    }

    if (check_win(board, current_turn_pointer) == false) {
      printf("This game was a tie.\n");
    }

    user_persistence = check_user_persistence();
  } while (user_persistence == 1);

  return 0;
}