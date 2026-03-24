#include <stdio.h>
#include <string.h>

enum c4_result {
  C4_YELLOW_WINS,
  C4_RED_WINS,
  C4_TIE
};

struct c4_game {
  char* yellow_name;
  char* red_name;
  int move_count;
  enum c4_result result;
};

//Return the average moves in each game.
float average_move_count(struct c4_game games[], int num_games) {
  float move_count_sum = 0;
  for (int i = 0; i < num_games; i++) {
    move_count_sum += games[i].move_count;
  }
  return (move_count_sum / num_games);
}

//Return the yellow player's win rate.
float yellow_win_rate(struct c4_game games[], int num_games) {
  float y_win_count = 0;
  for (int i = 0; i < num_games; i++) {
    y_win_count += (games[i].result == C4_YELLOW_WINS); 
  }
  return (y_win_count / num_games);
}

//Return the red player's win rate.
float red_win_rate(struct c4_game games[], int num_games) {
  float r_win_count = 0;
  for (int i = 0; i < num_games; i++) {
    r_win_count += (games[i].result == C4_RED_WINS); 
  }
  return (r_win_count / num_games);
}

//Return the tie rate.
float tie_rate(struct c4_game games[], int num_games) {
  float tie_count = 0;
  for (int i = 0; i < num_games; i++) {
    tie_count += (games[i].result == C4_TIE); 
  }
  return (tie_count / num_games);
}

//Return the name of the player who won the game which had the most moves.
char* longest_game_winner(struct c4_game games[], int num_games) {
  int max_move_count = -1;
  char* player = "";
  for (int i = 0; i < num_games; i++) {
    if (max_move_count <= games[i].move_count) {
      max_move_count = games[i].move_count;
      if (games[i].result == C4_YELLOW_WINS) {
        player = games[i].yellow_name;
      }
      else if (games[i].result == C4_RED_WINS) {
        player = games[i].red_name;
      }
      else {
        player = "TIE";
      }
    }
  }
  return player;
}

struct c4_stats {
  int total_moves;
  float average_moves;
  char* longest_game_winner;
  char* shortest_game_winner;
  float yellow_win_rate;
  float red_win_rate;
  float tie_rate;
};

//Return the sum of the move count of each game.
int sum_move_count(struct c4_game games[], int num_games) {
  int move_count_sum = 0;
  for (int i = 0; i < num_games; i++) {
    move_count_sum += games[i].move_count;
  }
  return move_count_sum;
}

//Return the name of the player who won the game with the least moves.
char* shortest_game_winner(struct c4_game games[], int num_games) {
  int min_move_count = 100000;
  char* player = "";
  for (int i = 0; i < num_games; i++) {
    if (min_move_count >= games[i].move_count) {
      min_move_count = games[i].move_count;
      if (games[i].result == C4_YELLOW_WINS) {
        player = games[i].yellow_name;
      }
      else if (games[i].result == C4_RED_WINS) {
        player = games[i].red_name;
      }
      else {
        player = "TIE";
      }
    }
  }
  return player;
}

struct c4_stats compute_c4_stats(struct c4_game games[], int num_games) {
  struct c4_stats stats;
  stats.total_moves =  sum_move_count(games, num_games);
  stats.average_moves = average_move_count(games, num_games);
  stats.longest_game_winner = longest_game_winner(games, num_games);
  stats.shortest_game_winner = shortest_game_winner(games, num_games);
  stats.yellow_win_rate = yellow_win_rate(games, num_games);
  stats.red_win_rate = red_win_rate(games, num_games);
  stats.tie_rate = tie_rate(games, num_games);
  return stats;
}

struct c4_game game1 = {
  .yellow_name = "Duc",
  .red_name = "Ody",
  .move_count = 6,
  .result = C4_YELLOW_WINS
};

struct c4_game game2 = {
  .yellow_name = "Duc",
  .red_name = "Ody",
  .move_count = 8,
  .result = C4_TIE
};

struct c4_game game3 = {
  .yellow_name = "Duc",
  .red_name = "Ody",
  .move_count = 10,
  .result = C4_TIE
};

struct c4_game game4 = {
  .yellow_name = "Duc",
  .red_name = "Ody",
  .move_count = 12,
  .result = C4_RED_WINS
};

struct c4_game game5 = {
  .yellow_name = "Duc",
  .red_name = "Ody",
  .move_count = 14,
  .result = C4_YELLOW_WINS
};



void compute_c4_stats_nocopy(struct c4_game games[], int num_games, struct c4_stats* stats) {
  stats->total_moves =  sum_move_count(games, num_games);
  stats->average_moves = average_move_count(games, num_games);
  stats->longest_game_winner = longest_game_winner(games, num_games);
  stats->shortest_game_winner = shortest_game_winner(games, num_games);
  stats->yellow_win_rate = yellow_win_rate(games, num_games);
  stats->red_win_rate = red_win_rate(games, num_games);
  stats->tie_rate = tie_rate(games, num_games);
}


int main() {
  struct c4_game games[5] = {game1, game2, game3, game4, game5};
  float avg_move_count = average_move_count(games, 5);
  float y_win_rate = yellow_win_rate(games, 5);
  char* longest_game_winner_name = longest_game_winner(games, 5);
  printf("%f\n", avg_move_count);
  printf("%f\n", y_win_rate);
  printf("%s\n", longest_game_winner_name);
  struct c4_stats c4_statistics = compute_c4_stats(games, 5);
  printf("total moves: %d\n", c4_statistics.total_moves);
  printf("average moves: %f\n", c4_statistics.average_moves);
  printf("longest game winner: %s\n", c4_statistics.longest_game_winner);
  printf("shortest game winner: %s\n", c4_statistics.shortest_game_winner);
  printf("yellow win rate: %f\n", c4_statistics.yellow_win_rate);
  printf("red win rate: %f\n", c4_statistics.red_win_rate);
  printf("tie rate: %f\n", c4_statistics.tie_rate);

  compute_c4_stats_nocopy(games, 3, &c4_statistics);
  printf("total moves: %d\n", c4_statistics.total_moves);
  printf("average moves: %f\n", c4_statistics.average_moves);
  printf("longest game winner: %s\n", c4_statistics.longest_game_winner);
  printf("shortest game winner: %s\n", c4_statistics.shortest_game_winner);
  printf("yellow win rate: %f\n", c4_statistics.yellow_win_rate);
  printf("red win rate: %f\n", c4_statistics.red_win_rate);
  printf("tie rate: %f\n", c4_statistics.tie_rate);
}
