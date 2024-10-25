#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ANSI color codes
#define RESET_COLOR   "\x1b[0m"
#define RED_COLOR     "\x1b[31m"
#define GREEN_COLOR   "\x1b[32m"
#define YELLOW_COLOR  "\x1b[33m"
#define BLUE_COLOR    "\x1b[34m"

int main() {
    int number, guess, attempts = 0;
    srand(time(0)); // Seed the random number generator
    number = rand() % 100 + 1; // Random number between 1 and 100

    printf(YELLOW_COLOR "Welcome to the Number Guessing Game!\n" RESET_COLOR);
    printf(BLUE_COLOR "Guess a number between 1 and 100.\n" RESET_COLOR);

    do {
        printf(GREEN_COLOR "Enter your guess: " RESET_COLOR);
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf(RED_COLOR "Too high! Try again.\n" RESET_COLOR);
        } else if (guess < number) {
            printf(RED_COLOR "Too low! Try again.\n" RESET_COLOR);
        } else {
            printf(YELLOW_COLOR "Congratulations! You guessed the correct number in %d attempts.\n" RESET_COLOR, attempts);
        }

    } while (guess != number);

    return 0;
}
