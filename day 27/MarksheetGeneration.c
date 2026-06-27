#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 50
#define NAME_LEN 50
#define ROLL_LEN 15

// Structure to define Student Academic Records
typedef struct {
    char rollNumber[ROLL_LEN];
    char name[NAME_LEN];
    int math;
    int science;
    int english;
    int computer;
    int history;
} StudentMarks;

// Utility function to flush the input buffer cleanly
void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to calculate a letter grade and remarks based on percentage
void calculateGradeAndRemarks(double percentage, char *grade, char *remarks) {
    if (percentage >= 90.0) {
        strcpy(grade, "A+");
        strcpy(remarks, "Outstanding Performance");
    } else if (percentage >= 80.0) {
        strcpy(grade, "A");
        strcpy(remarks, "Excellent Work");
    } else if (percentage >= 70.0) {
        strcpy(grade, "B");
        strcpy(remarks, "Very Good");
    } else if (percentage >= 60.0) {
        strcpy(grade, "C");
        strcpy(remarks, "Good / Above Average");
    } else if (percentage >= 50.0) {
        strcpy(grade, "D");
        strcpy(remarks, "Satisfactory / Pass");
    } else {
        strcpy(grade, "F");
        strcpy(remarks, "Failed / Needs Improvement");
    }
}

// Function to add a student mark record with guardrails
void addStudentMarks(StudentMarks list[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\n❌ Error: Database storage limits reached. Cannot register more marksheets.\n");
        return;
    }

    StudentMarks student;
    
    printf("\nEnter Unique Roll Number: ");
    if (scanf("%14s", student.rollNumber) != 1) {
        printf("❌ Invalid Roll Number format.\n");
        flushInputBuffer();
        return;
    }

    // Check for duplicate Roll Number tracking to safeguard data integrity
    for (int i = 0; i < *count; i++) {
        if (strcmp(list[i].rollNumber, student.rollNumber) == 0) {
            printf("❌ Error: A marksheet record already exists for Roll Number %s.\n", student.rollNumber);
            flushInputBuffer();
            return;
        }
    }

    flushInputBuffer(); // Flush stream buffer before fetching spaces in full name

    printf("Enter Student Full Name: ");
    if (fgets(student.name, NAME_LEN, stdin) != NULL) {
        student.name[strcspn(student.name, "\n")] = '\0';
    }

    // Array pointers pointing to subject components for cleaner validation loops
    int *subjects[] = {&student.math, &student.science, &student.english, &student.computer, &student.history};
    char *subjectNames[] = {"Mathematics", "Science      ", "English      ", "Computer Sci ", "History      "};

    printf("\nEnter obtained marks out of 100:\n");
    for (int i = 0; i < 5; i++) {
        while (true) {
            printf("  %s: ", subjectNames[i]);
            if (scanf("%d", subjects[i]) != 1 || *subjects[i] < 0 || *subjects[i] > 100) {
                printf("  ⚠️ Invalid input! Marks must be an integer between 0 and 100.\n");
                flushInputBuffer();
            } else {
                break;
            }
        }
    }
    flushInputBuffer();

    // Commit completely configured record token to the tracking list
    list[*count] = student;
    (*count)++;
    printf("\n✅ Success: Marks successfully recorded for %s!\n", student.name);
}

// Function to generate an official, formatted report card marksheet
void generateMarkSheet(StudentMarks list[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: The database is currently empty. Cannot compile marksheets.\n");
        return;
    }

    char targetRoll[ROLL_LEN];
    printf("\nEnter Student Roll Number to generate Marksheet: ");
    scanf("%14s", targetRoll);
    flushInputBuffer();

    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].rollNumber, targetRoll) == 0) {
            // Business logic calculation
            int total = list[i].math + list[i].science + list[i].english + list[i].computer + list[i].history;
            double percentage = total / 5.0;

            // Determine if student failed any specific individual subject (Passing threshold = 40)
            bool failedSubject = (list[i].math < 40 || list[i].science < 40 || list[i].english < 40 || 
                                  list[i].computer < 40 || list[i].history < 40);

            char grade[5];
            char remarks[40];
            calculateGradeAndRemarks(percentage, grade, remarks);

            // Override grade to F if they failed any subject regardless of higher percentage averages
            if (failedSubject) {
                strcpy(grade, "F");
                strcpy(remarks, "Failed in one or more subjects");
            }

            // Print the structural Report Card Marksheet block
            printf("\n====================================================\n");
            printf("              BOARD OF EDUCATION REPORT             \n");
            printf("                OFFICIAL MARKSHEET                  \n");
            printf("====================================================\n");
            printf(" Roll Number   : %-15s\n", list[i].rollNumber);
            printf(" Student Name  : %-30s\n", list[i].name);
            printf("----------------------------------------------------\n");
            printf(" SUBJECTS                        MAX MARKS  OBTAINED \n");
            printf("----------------------------------------------------\n");
            printf("  1. Mathematics                    100         %d\n", list[i].math);
            printf("  2. Science                        100         %d\n", list[i].science);
            printf("  3. English                        100         %d\n", list[i].english);
            printf("  4. Computer Science               100         %d\n", list[i].computer);
            printf("  5. History                        100         %d\n", list[i].history);
            printf("----------------------------------------------------\n");
            printf(" AGGREGATE SUMMARY                                  \n");
            printf("----------------------------------------------------\n");
            printf("  Grand Total Marks Obtained :  %d / 500\n", total);
            printf("  Final Calculated Percentage:  %.2f%%\n", percentage);
            printf("  Assigned Alphabetical Grade:  %-4s\n", grade);
            printf("  Academic Result Status     :  %-10s\n", failedSubject ? "FAIL" : "PASS");
            printf("  Administrative Remarks     :  %s\n", remarks);
            printf("====================================================\n");
            return;
        }
    }
    printf("❌ Error: No registered student matched Roll Number %s.\n", targetRoll);
}

int main() {
    StudentMarks reportDatabase[MAX_STUDENTS];
    int trackingCount = 0;
    int interactiveChoice;

    do {
        printf("\n========== MARKSHEET MANAGEMENT SYSTEM ==========\n");
        printf("1. Record New Student Subject Marks\n");
        printf("2. Compile & Print Formatted Marksheet Report\n");
        printf("3. Terminate Application Session\n");
        printf("Select administrative option (1-3): ");

        if (scanf("%d", &interactiveChoice) != 1) {
            printf("\n❌ Error: Non-numeric action token input. Resetting console loop.\n");
            flushInputBuffer();
            interactiveChoice = 0; // Guard against menu infinite execution trace loops
            continue;
        }

        switch (interactiveChoice) {
            case 1: addStudentMarks(reportDatabase, &trackingCount); break;
            case 2: generateMarkSheet(reportDatabase, trackingCount); break;
            case 3: printf("\nClosing automated marksheet reporting compilation workspace. Goodbye!\n"); break;
            default: printf("\n❌ Error: Selected option index out of boundaries. Pick 1 to 3.\n"); break;
        }
    } while (interactiveChoice != 3);

    return 0;
}
