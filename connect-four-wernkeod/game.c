#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_WIDTH 7
#define BOARD_HEIGHT 6
#define OPEN_SPACE 0
#define YELLOW -1
#define RED 1

// Constants to print in bold red text, bold yellow text, and to reset text style
#define START_RED "\033[1m\033[31m"
#define START_YELLOW "\033[1m\033[33m"
#define RESET_COLOR "\033[0m"

/*   To print text in yellow color, for example, use code with the following syntax:
printf(START_YELLOW "This text will appear in yellow.\n" RESET_COLOR);   */

// Convention for board: red spaces occupied by 1, yellow spaces occupied by -1.

//Sets all indicies of the global board to 0.
void reset_board(int board[]) {
  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int column = 0; column < BOARD_WIDTH; column++) {
      int pos = (row * 7) + column;
      board[pos] = 0;
    }
  }
}

//Changes player turn.
void change_turn(int* current_turn_pointer) {
  if (*current_turn_pointer == YELLOW) {
    *current_turn_pointer = RED;
  }
  else {
    *current_turn_pointer = YELLOW;
  }
}

//Prints turn status.
void print_turn_status(int current_turn) {
  if (current_turn == YELLOW) {
    printf("It's \"yellow\" player's turn.\n");
  }
  else {
    printf("It's \"red\" player's turn.\n");
  }
}

//Gets user input to fill an incidice of the board with current player's token (1 for red, -1 for yellow).
void get_user_move(int board[], int red_board[], int yellow_board[], int current_turn) {

  // Create an array to hold user input
  char input[100];
  bool exit_signal = false;

  // Read user input and check for errors
  // while ((fgets(input, 100, stdin) == NULL)) {
  //   fprintf(stderr, "Failed to read input from user.\n");
  // }
  while (exit_signal == false) {

    do {
      printf("Pick a column (A-G) in which to drop your piece: ");
      fgets(input, 100, stdin);
    } while (!((input[0] >= 'a' && input[0] <= 'g' && input[1] == '\n') || 
               (input[0] >= 'A' && input[0] <= 'G' && input[1] == '\n')));

    if (current_turn == YELLOW) {

      if (input[0] == 'a' || input[0] == 'A') {
        for (int pos = 35; pos >= 0; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            yellow_board[pos] = current_turn;
            exit_signal = true;
            break;            
          }
        } 
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'b' || input[0] == 'B') {
        for (int pos = 36; pos >= 1; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            yellow_board[pos] = current_turn;
            exit_signal = true;
            break;            
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'c' || input[0] == 'C') {
        for (int pos = 37; pos >= 2; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            yellow_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'd' || input[0] == 'D') {
        for (int pos = 38; pos >= 3; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            yellow_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'e' || input[0] == 'E') {
        for (int pos = 39; pos >= 4; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            yellow_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'f' || input[0] == 'F') {
        for (int pos = 40; pos >= 5; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            yellow_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      //Checks column for open spots, bottom to top.
      if (input[0] == 'g' || input[0] == 'G') {
        for (int pos = 41; pos >= 6; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            yellow_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
    }
    else {

      if (input[0] == 'a' || input[0] == 'A') {
        for (int pos = 35; pos >= 0; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            red_board[pos] = current_turn;
            exit_signal = true;
            break;          
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'b' || input[0] == 'B') {
        for (int pos = 36; pos >= 1; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            red_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'c' || input[0] == 'C') {
        for (int pos = 37; pos >= 2; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            red_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'd' || input[0] == 'D') {
        for (int pos = 38; pos >= 3; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            red_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'e' || input[0] == 'E') {
        for (int pos = 39; pos >= 4; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            red_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'f' || input[0] == 'F') {
        for (int pos = 40; pos >= 5; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            red_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }
      if (input[0] == 'g' || input[0] == 'G') {
        for (int pos = 41; pos >= 6; pos -= 7) {
          if (board[pos] == 0) {
            board[pos] = current_turn;
            red_board[pos] = current_turn;
            exit_signal = true;
            break;
          }
        }
        //The following happens if column is full of pieces:
        continue;
      }  
    }
  }
}

//This prints the current board with Rs representing red tokens and Ys representing yellow tokens.
void print_board(int board[], int red_board[], int yellow_board[]) {
  printf(" A B C D E F G\n");
  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int column = 0; column < BOARD_WIDTH; column++) {
      int pos = (row * 7) + column;
      if (board[pos] == YELLOW) { //Checks if global board's pos indice is non-empty
        printf("|" START_YELLOW "Y" RESET_COLOR);
      }
      else if (board[pos] == RED) {
        printf("|" START_RED "R" RESET_COLOR);
      }
      else {
        printf("| ");
      }
    }
    printf("|\n");
  }
}

//Checks win statuses of rows, columns, and diagonals.
void check_win_status(int red_board[], int yellow_board[], int* win_status_pointer) {
  //Checks row win statuses. Works one row at a time, checking 4 combinations each row.
  for (int row = 0; row < 6; row++) {
    for (int column = 0; column < 4; column++) {
      int pos = (row * 7) + column;
      if (red_board[pos] == RED &&
          red_board[(pos + 1)] == RED &&
          red_board[(pos + 2)] == RED &&
          red_board[(pos + 3)] == RED) {
        *win_status_pointer = RED;
      }
      else if (yellow_board[pos] == YELLOW &&
               yellow_board[(pos + 1)] == YELLOW &&
               yellow_board[(pos + 2)] == YELLOW &&
               yellow_board[(pos + 3)] == YELLOW) {
        *win_status_pointer = YELLOW;
      }
      else {
        continue;
      }
    }
  }
  //Checks column win statuses. Works by checking one column at a time, left to right; checks columns shifted a row below after.
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 7; column++) {
      int pos = (row * 7) + column;
      if (red_board[pos] == RED &&
          red_board[(pos + 7)] == RED &&
          red_board[(pos + 14)] == RED &&
          red_board[(pos + 21)] == RED) {
        *win_status_pointer = RED;
      }
      else if (yellow_board[pos] == YELLOW &&
               yellow_board[(pos + 7)] == YELLOW &&
               yellow_board[(pos + 14)] == YELLOW &&
               yellow_board[(pos + 21)] == YELLOW) {
        *win_status_pointer = YELLOW;
      }
      else {
        continue;
      }
    }
  }
  //Checks diagonal win status, left to right.
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 7; column++) {
      int pos = (row * 7) + column;
      if (red_board[pos] == RED &&
          red_board[(pos + 7)] == RED &&
          red_board[(pos + 14)] == RED &&
          red_board[(pos + 21)] == RED) {
        *win_status_pointer = RED;
      }
      else if (yellow_board[pos] == YELLOW &&
               yellow_board[(pos + 7)] == YELLOW &&
               yellow_board[(pos + 14)] == YELLOW &&
               yellow_board[(pos + 21)] == YELLOW) {
        *win_status_pointer = YELLOW;
      }
      else {
        continue;
      }
    }
  }
  if (//Sweeps left to right checking for red higher-to-lower, left-to-right diagonal win (12 total possible win combinations).
      red_board[14] == RED && red_board[22] == RED && red_board[30] == RED && red_board[38] == RED ||
      red_board[7] == RED && red_board[15] == RED && red_board[23] == RED && red_board[31] == RED ||
      red_board[15] == RED && red_board[23] == RED && red_board[31] == RED && red_board[39] == RED ||
      red_board[0] == RED && red_board[8] == RED && red_board[16] == RED && red_board[24] == RED ||
      red_board[8] == RED && red_board[16] == RED && red_board[24] == RED && red_board[32] == RED ||
      red_board[16] == RED && red_board[24] == RED && red_board[32] == RED && red_board[40] == RED ||
      red_board[1] == RED && red_board[9] == RED && red_board[17] == RED && red_board[25] == RED ||
      red_board[9] == RED && red_board[17] == RED && red_board[25] == RED && red_board[33] == RED ||
      red_board[17] == RED && red_board[25] == RED && red_board[33] == RED && red_board[41] == RED ||
      red_board[2] == RED && red_board[10] == RED && red_board[18] == RED && red_board[26] == RED ||
      red_board[10] == RED && red_board[18] == RED && red_board[26] == RED && red_board[34] == RED ||
      red_board[3] == RED && red_board[11] == RED && red_board[19] == RED && red_board[27] == RED ||
      //Sweeps left to right checking for red higher-to-lower, right-to-left diagonal win (12 total possible win combinations).
      red_board[3] == RED && red_board[9] == RED && red_board[15] == RED && red_board[21] == RED ||
      red_board[4] == RED && red_board[10] == RED && red_board[16] == RED && red_board[22] == RED ||
      red_board[10] == RED && red_board[16] == RED && red_board[22] == RED && red_board[28] == RED ||
      red_board[5] == RED && red_board[11] == RED && red_board[17] == RED && red_board[23] == RED ||
      red_board[11] == RED && red_board[17] == RED && red_board[23] == RED && red_board[29] == RED ||
      red_board[17] == RED && red_board[23] == RED && red_board[29] == RED && red_board[35] == RED ||
      red_board[6] == RED && red_board[12] == RED && red_board[18] == RED && red_board[24] == RED ||
      red_board[12] == RED && red_board[18] == RED && red_board[24] == RED && red_board[30] == RED ||
      red_board[18] == RED && red_board[24] == RED && red_board[30] == RED && red_board[36] == RED ||
      red_board[13] == RED && red_board[19] == RED && red_board[25] == RED && red_board[31] == RED ||
      red_board[19] == RED && red_board[25] == RED && red_board[31] == RED && red_board[37] == RED ||
      red_board[20] == RED && red_board[26] == RED && red_board[32] == RED && red_board[38] == RED) {
        *win_status_pointer = RED;
      }
  else if (
      //Sweeps left to right checking for yellow higher-to-lower, left-to-right diagonal win (12 total possible win combinations).
      yellow_board[14] == YELLOW && yellow_board[22] == YELLOW && yellow_board[30] == YELLOW && yellow_board[38] == YELLOW ||
      yellow_board[7] == YELLOW && yellow_board[15] == YELLOW && yellow_board[23] == YELLOW && yellow_board[31] == YELLOW ||
      yellow_board[15] == YELLOW && yellow_board[23] == YELLOW && yellow_board[31] == YELLOW && yellow_board[39] == YELLOW ||
      yellow_board[0] == YELLOW && yellow_board[8] == YELLOW && yellow_board[16] == YELLOW && yellow_board[24] == YELLOW ||
      yellow_board[8] == YELLOW && yellow_board[16] == YELLOW && yellow_board[24] == YELLOW && yellow_board[32] == YELLOW ||
      yellow_board[16] == YELLOW && yellow_board[24] == YELLOW && yellow_board[32] == YELLOW && yellow_board[40] == YELLOW ||
      yellow_board[1] == YELLOW && yellow_board[9] == YELLOW && yellow_board[17] == YELLOW && yellow_board[25] == YELLOW ||
      yellow_board[9] == YELLOW && yellow_board[17] == YELLOW && yellow_board[25] == YELLOW && yellow_board[33] == YELLOW ||
      yellow_board[17] == YELLOW && yellow_board[25] == YELLOW && yellow_board[33] == YELLOW && yellow_board[41] == YELLOW ||
      yellow_board[2] == YELLOW && yellow_board[10] == YELLOW && yellow_board[18] == YELLOW && yellow_board[26] == YELLOW ||
      yellow_board[10] == YELLOW && yellow_board[18] == YELLOW && yellow_board[26] == YELLOW && yellow_board[34] == YELLOW ||
      yellow_board[3] == YELLOW && yellow_board[11] == YELLOW && yellow_board[19] == YELLOW && yellow_board[27] == YELLOW ||
      //Sweeps left to right checking for yellow higher-to-lower, right-to-left diagonal win (12 total possible win combinations).
      yellow_board[3] == YELLOW && yellow_board[9] == YELLOW && yellow_board[15] == YELLOW && yellow_board[21] == YELLOW ||
      yellow_board[4] == YELLOW && yellow_board[10] == YELLOW && yellow_board[16] == YELLOW && yellow_board[22] == YELLOW ||
      yellow_board[10] == YELLOW && yellow_board[16] == YELLOW && yellow_board[22] == YELLOW && yellow_board[28] == YELLOW ||
      yellow_board[5] == YELLOW && yellow_board[11] == YELLOW && yellow_board[17] == YELLOW && yellow_board[23] == YELLOW ||
      yellow_board[11] == YELLOW && yellow_board[17] == YELLOW && yellow_board[23] == YELLOW && yellow_board[29] == YELLOW ||
      yellow_board[17] == YELLOW && yellow_board[23] == YELLOW && yellow_board[29] == YELLOW && yellow_board[35] == YELLOW ||
      yellow_board[6] == YELLOW && yellow_board[12] == YELLOW && yellow_board[18] == YELLOW && yellow_board[24] == YELLOW ||
      yellow_board[12] == YELLOW && yellow_board[18] == YELLOW && yellow_board[24] == YELLOW && yellow_board[30] == YELLOW ||
      yellow_board[18] == YELLOW && yellow_board[24] == YELLOW && yellow_board[30] == YELLOW && yellow_board[36] == YELLOW ||
      yellow_board[13] == YELLOW && yellow_board[19] == YELLOW && yellow_board[25] == YELLOW && yellow_board[31] == YELLOW ||
      yellow_board[19] == YELLOW && yellow_board[25] == YELLOW && yellow_board[31] == YELLOW && yellow_board[37] == YELLOW ||
      yellow_board[20] == YELLOW && yellow_board[26] == YELLOW && yellow_board[32] == YELLOW && yellow_board[38] == YELLOW) {
        *win_status_pointer = YELLOW;
      }
}


int main() {
  int current_turn = YELLOW;
  int* current_turn_pointer = &current_turn;
  int win_status = 0;
  int* win_status_pointer = &win_status;
  int red_board[42];
  int yellow_board[42];
  int board[42];
  reset_board(red_board);
  reset_board(yellow_board);
  reset_board(board);

  print_board(board, red_board, yellow_board);
  for (int turn_count = 0; turn_count < 42; turn_count++) {
    print_turn_status(current_turn);
    get_user_move(board, red_board, yellow_board, current_turn);
    print_board(board, red_board, yellow_board);
    change_turn(current_turn_pointer);
    check_win_status(red_board, yellow_board, win_status_pointer);
    if (win_status == RED) {
      printf("Red wins.\n");
      break;
    }
    else if (win_status == YELLOW) {
      printf("Yellow wins.\n");
      break;
    }
    else if (turn_count == 41) {
      printf("Nobody won.\n");
      break;
    }
    else {
      continue;
    }
  }

  return 0;
}
