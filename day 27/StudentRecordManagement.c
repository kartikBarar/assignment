#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DEPT_LEN 20

// Define the structural layout of a single student record
typedef struct {
    int rollNumber;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    float gpa;
} Student;

// Helper function to thoroughly clear the standard input buffer stream
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to safely add a new student record
void addStudent(Student list[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\n❌ Error: System storage capacity full! Cannot add more records.\n");
        return;
    }

    Student s;
    printf("\nEnter unique Roll Number: ");
    if (scanf("%d", &s.rollNumber) != 1 || s.rollNumber <= 0) {
        printf("❌ Invalid Roll Number. Operation canceled.\n");
        clearBuffer();
        return;
    }

    // Check if the roll number already exists to enforce database integrity
    for (int i = 0; i < *count; i++) {
        if (list[i].rollNumber == s.rollNumber) {
            printf("❌ Error: A student with Roll Number %d already exists.\n", s.rollNumber);
            return;
        }
    }

    clearBuffer(); // Clear newline left behind by scanf before grabbing text strings

    printf("Enter Full Name: ");
    if (fgets(s.name, NAME_LEN, stdin) != NULL) {
        s.name[strcspn(s.name, "\n")] = '\0'; // Trim trailing newline
    }

    printf("Enter Department: ");
    if (fgets(s.department, DEPT_LEN, stdin) != NULL) {
        s.department[strcspn(s.department, "\n")] = '\0';
    }

    printf("Enter Cumulative GPA (0.0 to 4.0): ");
    if (scanf("%f", &s.gpa) != 1 || s.gpa < 0.0 || s.gpa > 4.0) {
        printf("❌ Invalid GPA value typed. Operation canceled.\n");
        clearBuffer();
        return;
    }

    // Insert the constructed record into the management array
    list[*count] = s;
    (*count)++;
    printf("✅ Success: Student record registered successfully!\n");
}

// Function to display all existing records formatted as a clean table
void displayAll(Student list[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: The student database registry is currently empty.\n");
        return;
    }

    printf("\n====================================================================\n");
    printf("%-10s %-25s %-15s %-5s\n", "Roll No", "Full Name", "Department", "GPA");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-15s %-5.2f\n", list[i].rollNumber, list[i].name, list[i].department, list[i].gpa);
    }
    printf("====================================================================\n");
}

// Function to look up a student using their unique Roll Number
void searchStudent(Student list[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: Database is empty. Nothing to search.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to lookup: ");
    if (scanf("%d", &roll) != 1) {
        clearBuffer();
        return;
    }

    for (int i = 0; i < count; i++) {
        if (list[i].rollNumber == roll) {
            printf("\n🔍 Record Found:\n");
            printf("-------------------------\n");
            printf("Roll Number: %d\n", list[i].rollNumber);
            printf("Full Name:   %s\n", list[i].name);
            printf("Department:  %s\n", list[i].department);
            printf("Current GPA: %.2f\n", list[i].gpa);
            return; // Terminate execution early once matched
        }
    }
    printf("❌ Error: No student found with Roll Number %d.\n", roll);
}

// Function to update the GPA of an existing student
void updateGPA(Student list[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: Database is empty. Nothing to modify.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number of the student to modify: ");
    if (scanf("%d", &roll) != 1) {
        clearBuffer();
        return;
    }

    for (int i = 0; i < count; i++) {
        if (list[i].rollNumber == roll) {
            float newGPA;
            printf("Current record matches: %s (Current GPA: %.2f)\n", list[i].name, list[i].gpa);
            printf("Enter updated GPA: ");
            if (scanf("%f", &newGPA) != 1 || newGPA < 0.0 || newGPA > 4.0) {
                printf("❌ Invalid GPA value. Update aborted.\n");
                clearBuffer();
                return;
            }
            list[i].gpa = newGPA;
            printf("✅ Success: GPA update committed successfully!\n");
            return;
        }
    }
    printf("❌ Error: No student found with Roll Number %d.\n", roll);
}

int main() {
    Student database[MAX_STUDENTS];
    int studentCount = 0;
    int optionChoice;

    do {
        printf("\n========== STUDENT RECORD MANAGEMENT SYSTEM ==========\n");
        printf("1. Create / Add Student Profile\n");
        printf("2. Display All Student Profiles\n");
        printf("3. Query Profile by Roll Number\n");
        printf("4. Modify Existing Profile GPA\n");
        printf("5. Exit System Terminal\n");
        printf("Select administrative option (1-5): ");

        if (scanf("%d", &optionChoice) != 1) {
            printf("\n❌ Error: Non-numeric action input. Resetting terminal branch.\n");
            clearBuffer();
            optionChoice = 0; // Prevent loop lockup conditions
            continue;
        }

        switch (optionChoice) {
            case 1: addStudent(database, &studentCount); break;
            case 2: displayAll(database, studentCount); break;
            case 3: searchStudent(database, studentCount); break;
            case 4: updateGPA(database, studentCount); break;
            case 5: printf("\nShutting down database environment session. Goodbye!\n"); break;
            default: printf("\n❌ Error: Selected option out of bounds. Pick 1 to 5.\n"); break;
        }
    } while (optionChoice != 5);

    return 0;
}
