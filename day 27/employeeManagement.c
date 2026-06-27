#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 50
#define NAME_LEN 50
#define DESIG_LEN 30

// Define the Employee record structure
typedef struct {
    int id;
    char name[NAME_LEN];
    char designation[DESIG_LEN];
    double basicSalary;
    double allowance;
} Employee;

// Function to clear the input buffer and prevent skipping strings
void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a new employee profile
void addEmployee(Employee list[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\n❌ Error: System database is full! Cannot add more records.\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    if (scanf("%d", &emp.id) != 1 || emp.id <= 0) {
        printf("❌ Invalid ID format. Operation canceled.\n");
        flushBuffer();
        return;
    }

    // Check for ID duplication to maintain database integrity
    for (int i = 0; i < *count; i++) {
        if (list[i].id == emp.id) {
            printf("❌ Error: Employee ID %d already exists in the system.\n", emp.id);
            return;
        }
    }

    flushBuffer(); // Clean leftover newline from the buffer

    printf("Enter Employee Full Name: ");
    if (fgets(emp.name, NAME_LEN, stdin) != NULL) {
        emp.name[strcspn(emp.name, "\n")] = '\0'; // Trim trailing newline
    }

    printf("Enter Designation / Role: ");
    if (fgets(emp.designation, DESIG_LEN, stdin) != NULL) {
        emp.designation[strcspn(emp.designation, "\n")] = '\0';
    }

    printf("Enter Basic Monthly Salary ($): ");
    if (scanf("%lf", &emp.basicSalary) != 1 || emp.basicSalary < 0) {
        printf("❌ Invalid salary amount. Operation canceled.\n");
        flushBuffer();
        return;
    }

    printf("Enter Monthly Allowance ($): ");
    if (scanf("%lf", &emp.allowance) != 1 || emp.allowance < 0) {
        printf("❌ Invalid allowance amount. Operation canceled.\n");
        flushBuffer();
        return;
    }

    // Save the record into the array database
    list[*count] = emp;
    (*count)++;
    printf("✅ Success: Employee profile created successfully!\n");
}

// Function to print details and payroll breakups of all employees
void displayAll(Employee list[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: The employee database registry is empty.\n");
        return;
    }

    printf("\n====================================================================================\n");
    printf("%-7s %-22s %-18s %-12s %-11s %-12s\n", "ID", "Name", "Designation", "Basic Sal", "Allowance", "Net Salary");
    printf("------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        double netSalary = list[i].basicSalary + list[i].allowance;
        printf("%-7d %-22s %-18s $%-11.2f $%-10.2f $%-11.2f\n", 
               list[i].id, list[i].name, list[i].designation, list[i].basicSalary, list[i].allowance, netSalary);
    }
    printf("====================================================================================\n");
}

// Function to look up an employee by their ID
void searchEmployee(Employee list[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: Database is empty. Nothing to search.\n");
        return;
    }

    int targetId;
    printf("\nEnter Employee ID to search: ");
    if (scanf("%d", &targetId) != 1) {
        printf("❌ Invalid ID format.\n");
        flushBuffer();
        return;
    }

    for (int i = 0; i < count; i++) {
        if (list[i].id == targetId) {
            double netSalary = list[i].basicSalary + list[i].allowance;
            printf("\n🔍 Employee Record Found:\n");
            printf("-------------------------------------\n");
            printf("ID Number:    %d\n", list[i].id);
            printf("Full Name:    %s\n", list[i].name);
            printf("Designation:  %s\n", list[i].designation);
            printf("Basic Salary: $%.2f\n", list[i].basicSalary);
            printf("Allowance:    $%.2f\n", list[i].allowance);
            printf("Net Payroll:  $%.2f\n", netSalary);
            return;
        }
    }
    printf("❌ Error: No employee found with ID %d.\n", targetId);
}

int main() {
    Employee database[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do {
        printf("\n========== EMPLOYEE MANAGEMENT SYSTEM ==========\n");
        printf("1. Register New Employee Profile\n");
        printf("2. Display All Employee Payrolls\n");
        printf("3. Search Employee Profile by ID\n");
        printf("4. Exit System Terminal\n");
        printf("Select administrative option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Error: Non-numeric option entered. Resetting menu.\n");
            flushBuffer();
            choice = 0; // Safe fallback value to prevent loop crash
            continue;
        }

        switch (choice) {
            case 1: addEmployee(database, &employeeCount); break;
            case 2: displayAll(database, employeeCount); break;
            case 3: searchEmployee(database, employeeCount); break;
            case 4: printf("\nClosing database session. Goodbye!\n"); break;
            default: printf("\n❌ Error: Selected option out of bounds. Pick 1 to 4.\n"); break;
        }
    } while (choice != 4);

    return 0;
}
