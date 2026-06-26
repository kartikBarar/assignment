#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess;
    int attempts = 0;
    
    // Seed the random number generator with the current system time to ensure a unique number every game
    srand(time(NULL));
    
    // Generate a random secret number between 1 and 100
    secret_number = (rand() % 100) + 1;
    
    printf("===========================================\n");
    printf("     WELCOME TO THE NUMBER GUESSING GAME   \n");
    printf("===========================================\n");
    printf("I have picked a secret number between 1 and 100.\n");
    printf("Can you figure out what it is?\n\n");
    
    // Game loop runs until the user guesses the correct number
    do {
        printf("Enter your guess: ");
        
        // Input validation: Check if user entered a valid integer
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            
            // Clear the input buffer to prevent an infinite loop from bad input
            while (getchar() != '\n');
            continue;
        }
        
        attempts++; // Increment the attempt counter
        
        // Provide targeted feedback to the user
        if (guess > secret_number) {
            printf("Too high! Try a lower number.\n\n");
        } else if (guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } else {
            printf("\n🎉 CONGRATULATIONS! You guessed it right!\n");
            printf("The secret number was: %d\n", secret_number);
            printf("Total attempts taken: %d\n", attempts);
        }
        
    } while (guess != secret_number);
    
    printf("===========================================\n");
    printf("Thank you for playing! Have a great day!\n");
    
    return 0;
}
