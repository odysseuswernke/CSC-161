#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define MAZE_SIZE 23
#define FRAME_RATE 60
#define MESSAGE_0 "__"
#define MESSAGE_1 "##"
#define MESSAGE_LENGTH 2

/**
 * Sleep for a given number of milliseconds
 * \param   ms  The number of milliseconds to sleep for
 */
void sleep_ms(size_t ms) {
  struct timespec ts;
  size_t rem = ms % 1000;
  ts.tv_sec = (ms - rem) / 1000;
  ts.tv_nsec = rem * 1000000;

  // Sleep repeatedly as long as nanosleep is interrupted
  while (nanosleep(&ts, &ts) != 0) {
  }
}

void print_maze(int maze[MAZE_SIZE * MAZE_SIZE]) {
  for (int row = 0; row < MAZE_SIZE; row++) {
    for (int column = 0; column < MAZE_SIZE; column++) {
      if (maze[row * MAZE_SIZE + column] == 0) {
        mvaddch(row, column, ' ');
      }
      else {
        mvaddch(row, column, ACS_CKBOARD);
      }
    }
  }
}

int main() {
  // Set up ncurses
  initscr();             // Initialize the standard window
  noecho();              // Don't display keys when they are typed
  nodelay(stdscr, true); // Set up non-blocking input with getch()
  keypad(stdscr, true);  // Allow arrow keys
  curs_set(false);       // Hide the cursor

  // Create a sample maze array
  int maze[MAZE_SIZE * MAZE_SIZE] = {
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
      1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,
      1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
      1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
      1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
      1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,
      1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
      1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
      1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
      1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1,
      1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
      1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1,
      1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
      1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1,
      1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  // TODO: Complete parts A, B, C, and D

  int message_x = 1;
  int message_y = 1;

  // Start the game loop
  bool running = true;
  while (running) {
    // Check for user input
    int input;
    while ((input = getch()) != ERR) {
      // Exit when the user types q
      if (input == 'q') {
        running = false;
      }
      else if (input == KEY_UP) {
        message_y--;
      }
      else if (input == KEY_DOWN) {
        message_y++;
      }
      else if (input == KEY_LEFT) {
        message_x--;
      }
      else if (input == KEY_RIGHT) {
        message_x++;
      }
    }

    // TODO: update state

    // Move the message in bounds on the y axis
    if (message_y < 0) {
      message_y = 0;
    }
    else if (message_y == MAZE_SIZE) {
      // The getmaxy function returns one more line than we can actually see,
      // so limit message_y to one less than max_y
      message_y = MAZE_SIZE - 1;
    }

    // Move the message in bounds on the x axis
    if (message_x < 0) {
      message_x = 0;
    }
    else if (message_x + MESSAGE_LENGTH > MAZE_SIZE) {
      // Keep the entire message on screen by factoring in the message length
      message_x = MAZE_SIZE - MESSAGE_LENGTH;
    }

    // Display output
    clear();
    print_maze(maze);
    // Check if message is touching a wall
    if (maze[message_y * MAZE_SIZE + message_x] == 0 && maze[(message_y * MAZE_SIZE + message_x) + (MESSAGE_LENGTH - 1)] == 0) {
      mvprintw(message_y, message_x, MESSAGE_0);
    }
    else {
      mvprintw(message_y, message_x, MESSAGE_1);
    }
    refresh();
    sleep_ms(1000 / FRAME_RATE);
  }

  // Shut down
  endwin();
}
