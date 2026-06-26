#include <stdio.h>
#include <stdbool.h>

#define MAX_OPTIONS 4
#define TOTAL_QUESTIONS 3

// Structure to define a Quiz Question object
typedef struct {
    char questionText[150];
    char options[MAX_OPTIONS][50];
    char correctOption; // Store character matching the valid choice ('A', 'B', 'C', or 'D')
} QuizQuestion;

int main() {
    int score = 0;
    char userChoice;

    // Initialize the quiz database array with structured items
    QuizQuestion bank[TOTAL_QUESTIONS] = {
        {
            "Which escape sequence is used to print a new line character in C?",
            {"\\t", "\\n", "\\a", "\\r"},
            'B'
        },
        {
            "What is the maximum index value for an array declared as 'int matrix[10]'?",
            {"10", "11", "9", "0"},
            'C'
        },
        {
            "Which function is used to terminate a C program execution instantly?",
            {"abort()", "exit()", "break", "return"},
            'B'
        }
    };

    printf("===========================================\n");
    printf("        WELCOME TO THE ACADEMY QUIZ        \n");
    printf("===========================================\n");
    printf("Instructions: Enter A, B, C, or D for each question.\n\n");

    // Main game loop running through each question
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, bank[i].questionText);
        printf("  A) %s\n", bank[i].options[0]);
        printf("  B) %s\n", bank[i].options[1]);
        printf("  C) %s\n", bank[i].options[2]);
        printf("  D) %s\n", bank[i].options[3]);
        
        // Loop to safely take and validate input
        while (true) {
            printf("Your Answer: ");
            if (scanf(" %c", &userChoice) != 1) {
                while (getchar() != '\n'); // Clear line if input broken
                continue;
            }

            // Convert lowercase input into uppercase for matching safety
            if (userChoice >= 'a' && userChoice <= 'z') {
                userChoice -= 32;
            }

            // Verify if choice is in valid multiple choice boundaries
            if (userChoice == 'A' || userChoice == 'B' || userChoice == 'C' || userChoice == 'D') {
                break; // Valid option received, break input loop
            }
            printf("❌ Invalid selection. Please select options choice A, B, C, or D.\n");
        }

        // Check if the user's answer matches the recorded correct option key
        if (userChoice == bank[i].correctOption) {
            printf("✅ Correct Answer!\n\n");
            score++;
        } else {
            printf("❌ Incorrect! The correct answer was option %c.\n\n", bank[i].correctOption);
        }
    }

    // Final grading score card generation
    printf("===========================================\n");
    printf("               QUIZ RESULTS                \n");
    printf("===========================================\n");
    printf("Total Answered Questions: %d\n", TOTAL_QUESTIONS);
    printf("Your Correct Answers:     %d\n", score);
    
    double percentage = ((double)score / TOTAL_QUESTIONS) * 100;
    printf("Final Grade Percentage:   %.1f%%\n", percentage);

    if (percentage >= 70.0) {
        printf("Status Evaluation:        PASSED! Excellent work.\n");
    } else {
        printf("Status Evaluation:        FAILED! Try studying again.\n");
    }
    printf("===========================================\n");

    return 0;
}
