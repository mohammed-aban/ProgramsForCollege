#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the computer's choice randomly
int get_computer_choice() {
    return rand() % 3; // 0: Rock, 1: Paper, 2: Scissors
}

// Function to determine the winner
int determine_winner(int player, int computer) {
    if (player == computer) {
        return 0; // Tie
    } else if ((player == 0 && computer == 2) ||
               (player == 1 && computer == 0) ||
               (player == 2 && computer == 1)) {
        return 1; // Player wins
    } else {
        return -1; // Computer wins
    }
}

// Function to display choice as a string
void display_choice(int choice) {
    if (choice == 0) {
        printf("Rock");
    } else if (choice == 1) {
        printf("Paper");
    } else if (choice == 2) {
        printf("Scissors");
    }
}

int main() {
    int playerChoice, computerChoice;
    int wins = 0, losses = 0, ties = 0;
    char playAgain;

    srand(time(0)); // Seed the random number generator
    

    printf("Welcome to Rock-Paper-Scissors!\n");

    do {
        printf("\nChoose your move:\n");
        printf("0: Rock\n1: Paper\n2: Scissors\n");
        printf("Enter your choice: ");
        scanf("%d", &playerChoice);

        if (playerChoice < 0 || playerChoice > 2) {
            printf("Invalid choice. Please choose 0, 1, or 2.\n");
            continue;
        }

        computerChoice = get_computer_choice();

        printf("You chose: ");
        display_choice(playerChoice);
        printf("\nComputer chose: ");
        display_choice(computerChoice);
        printf("\n");

        int result = determine_winner(playerChoice, computerChoice);
        if (result == 0) {
            printf("It's a tie!\n");
            ties++;
        } else if (result == 1) {
            printf("You win!\n");
            wins++;
        } else {
            printf("You lose!\n");
            losses++;
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    // Display the results
    printf("\nGame Summary:\n");
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
    printf("Ties: %d\n", ties);

    printf("Thanks for playing Rock-Paper-Scissors!\n");
    return 0;
}
