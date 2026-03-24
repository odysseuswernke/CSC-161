#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/* First, the basics: you’ll be implement a single player version of Yahtzee. 
The game will last for six turns, and each turn follows the same progression:

1. The player rolls five six-sided dice.
2. The player can choose any subset of the five dice to re-roll. 
   The player could choose to re-roll all the dice, none of the dice, or any number in-between.
3. The player can again choose a subset of the five dice to re-roll.
4. The player chooses an unused line on the score sheet to use for this turn. 
   The game calculates the score for the roll and enters it in the chosen line.
*/


void roll_five_dice(int current_dice[5]) {
   for (int i = 0; i < 5; i++) {
    current_dice[i] = (rand() % 6) + 1;
   }
}

void print_current_dice(int current_dice[5]) {
    for (int i = 0; i < 5; i++) {
        printf("Die %d: %d\n", (i + 1), current_dice[i]);
    }
}

//This prompts the user to reroll dice.
void get_dice_rerolls(int current_dice[5]) {
    for (int i = 0; i < 5; i++) {
        int user_choice;
        int num_values_scanned;

        do {
            printf("Reroll die %d? (y = 1, n = 0): ", (i + 1));
            num_values_scanned = scanf("%d", &user_choice);
            // Clear any remaining input from the user
            while (getchar() != '\n') {}
        }
        while (!(num_values_scanned == 1 && (user_choice == 0 || user_choice == 1)));
        
        if (user_choice == 1) {
            current_dice[i] = (rand() % 6) + 1;
        }

    }
}

//This allows user to deposit score into a score bank.
void deposit_score(int current_dice[5], int score_bank[6], int bank_deposit_tracker[6]) {
    int user_choice;
    int num_values_scanned;
    int user_roll_score = 0;
    int exit_signal = 0;

    while (exit_signal == 0) {
        do {
            printf("What score bank would you like to deposit to, 1-6?: ");
            num_values_scanned = scanf("%d", &user_choice);
            // Clear any remaining input from the user
            while (getchar() != '\n') {}
        }
        while (!(num_values_scanned == 1 && (user_choice <= 6 && user_choice >= 1)));

        //bank_deposit_tracker contains 1s (deposits) and 0s (open banks).
        if (bank_deposit_tracker[(user_choice - 1)] == 0) {
            for (int i = 0; i < 5; i++) {
                if (current_dice[i] == user_choice) {
                user_roll_score += current_dice[i];
                }
            }
            bank_deposit_tracker[(user_choice - 1)] = 1;
            exit_signal = 1;
        }
        else {
            printf("You have already deposited score in bank %d.\n", user_choice);
            continue;
        }
    }  

    score_bank[(user_choice - 1)] = user_roll_score;
    
}

//This prints the six score banks.
void print_score_bank(int score_bank[6]) {

    for (int i = 0; i < 6; i++) {
        printf("%ds Score Bank: %d\n", (i + 1), score_bank[i]);
    }
}


int main(void) {
   srand(time(NULL));
   int current_dice[5];
   int score_bank[6] = {0};
   int bank_deposit_tracker[6] = {0};
   printf("\nYahtzee: \n\n");
   printf("Rules: Play six rounds, with three turns each. Each turn, roll a subset of five dice\n"
          "to get as many matching dice as possible. At the end of each round, bank whichever\n"
          "sum of matching dice you prefer. There are six banks total, and each bank can be deposited\n"
          "into once. Good luck!\n\n");

   //There are six rounds in a game.
   for (int round = 1; round < 7; round++) {
        roll_five_dice(current_dice);
        
        //There are three turns in each round.
        for (int turn = 1; turn < 4; turn++) {
            printf("\nRound %d, turn %d:\n", round, turn);
            print_current_dice(current_dice);
            get_dice_rerolls(current_dice);
        }
        printf("\nRound-ending dice:\n");
        print_current_dice(current_dice);
        printf("\nCurrent score banks:\n");
        print_score_bank(score_bank);
        deposit_score(current_dice, score_bank, bank_deposit_tracker);
        printf("\nNew score banks:\n");
        print_score_bank(score_bank);
   }
}