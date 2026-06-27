#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STAFF 50
#define NAME_LEN 50

// Structure to define Employee Salary Breakdown Components
typedef struct {
    int empId;
    char name[NAME_LEN];
    double basicSalary;
    double hra;       // House Rent Allowance
    double da;        // Dearness Allowance
    double pf;        // Provident Fund (Deduction)
} SalaryRecord;

// Utility function to flush the input buffer cleanly
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to calculate components and add a salary record
void addSalaryRecord(SalaryRecord list[], int *count) {
    if (*count >= MAX_STAFF) {
        printf("\n❌ Error: Database limit reached. Cannot register more records.\n");
        return;
    }

    SalaryRecord rec;
    printf("\nEnter Employee ID: ");
    if (scanf("%d", &rec.empId) != 1 || rec.empId <= 0) {
        printf("❌ Invalid ID format. Operation canceled.\n");
        flushInput();
        return;
    }

    // Check for ID duplication to maintain database unique integrity
    for (int i = 0; i < *count; i++) {
        if (list[i].empId == rec.empId) {
            printf("❌ Error: Salary record for Employee ID %d already exists.\n", rec.empId);
            return;
        }
    }

    flushInput(); // Flush newline out of stream before grabbing text input

    printf("Enter Employee Name: ");
    if (fgets(rec.name, NAME_LEN, stdin) != NULL) {
        rec.name[strcspn(rec.name, "\n")] = '\0'; // Remove newline character
    }

    printf("Enter Base Monthly Salary ($): ");
    if (scanf("%lf", &rec.basicSalary) != 1 || rec.basicSalary < 0) {
        printf("❌ Invalid base salary entry. Operation canceled.\n");
        flushInput();
        return;
    }

    // Standardized Payroll Structure Calculations:
    // HRA = 20% of Basic, DA = 10% of Basic, PF Deduction = 12% of Basic
    rec.hra = rec.basicSalary * 0.20;
    rec.da = rec.basicSalary * 0.10;
    rec.pf = rec.basicSalary * 0.12;

    list[*count] = rec;
    (*count)++;
    printf("✅ Success: Payroll configuration logged successfully!\n");
}

// Function to print tabular summary sheets of all employee salaries
void viewSalarySheet(SalaryRecord list[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: The payroll registry sheet is currently empty.\n");
        return;
    }

    double totalExpenditure = 0;
    printf("\n========================================================================================\n");
    printf("%-7s %-20s %-12s %-10s %-10s %-10s %-12s\n", "ID", "Employee Name", "Base Sal", "HRA(20%)", "DA(10%)", "PF(12%)", "Net Salary");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        double grossEarnings = list[i].basicSalary + list[i].hra + list[i].da;
        double netSalary = grossEarnings - list[i].pf;
        totalExpenditure += netSalary;

        printf("%-7d %-20s $%-11.2f $%-9.2f $%-9.2f $%-9.2f $%-11.2f\n",
               list[i].empId, list[i].name, list[i].basicSalary, list[i].hra, list[i].da, list[i].pf, netSalary);
    }
    printf("========================================================================================\n");
    printf("Total Monthly Institutional Payroll Expenditure: $%.2f\n", totalExpenditure);
    printf("========================================================================================\n");
}

// Function to generate an itemized salary slip for a specific employee ID
void generatePaySlip(SalaryRecord list[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: Database is empty. Cannot generate payslips.\n");
        return;
    }

    int targetId;
    printf("\nEnter Employee ID to generate Pay Slip: ");
    if (scanf("%d", &targetId) != 1) {
        printf("❌ Invalid ID choice formatting.\n");
        flushInput();
        return;
    }

    for (int i = 0; i < count; i++) {
        if (list[i].empId == targetId) {
            double gross = list[i].basicSalary + list[i].hra + list[i].da;
            double net = gross - list[i].pf;

            printf("\n============================================\n");
            printf("         MONTHLY ITEMIZED PAY SLIP          \n");
            printf("============================================\n");
            printf("Employee ID   : %d\n", list[i].empId);
            printf("Staff Name    : %s\n", list[i].name);
            printf("--------------------------------------------\n");
            printf("EARNINGS                        AMOUNTS ($) \n");
            printf("  Basic Base Monthly Pay          %.2f\n", list[i].basicSalary);
            printf("  House Rent Allowance (HRA)      %.2f\n", list[i].hra);
            printf("  Dearness Allowance (DA)         %.2f\n", list[i].da);
            printf("  [GROSS EARNINGS TOTAL]          %.2f\n", gross);
            printf("--------------------------------------------\n");
            printf("DEDUCTIONS                      AMOUNTS ($) \n");
            printf("  Provident Fund (PF)             %.2f\n", list[i].pf);
            printf("  [TOTAL DEDUCTIONS ACCUMULATED]  %.2f\n", list[i].pf);
            printf("--------------------------------------------\n");
            printf("NET TAKE-HOME SALARY PAYOUT   : $%.2f\n", net);
            printf("============================================\n");
            return;
        }
    }
    printf("❌ Error: No registered employee matched ID %d.\n", targetId);
}

int main() {
    SalaryRecord database[MAX_STAFF];
    int staffCount = 0;
    int choice;

    do {
        printf("\n========== CORAL SALARY SYSTEM INTERFACE ==========\n");
        printf("1. Add Employee Salary Profile\n");
        printf("2. View Institutional Salary Sheet Summary\n");
        printf("3. Generate Itemized Pay Slip by Employee ID\n");
        printf("4. Exit Management Session Terminal\n");
        printf("Select administrative option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Error: Non-numeric action token input. Resetting console loop.\n");
            flushInput();
            choice = 0; // Guard against menu execution trace crash loops
            continue;
        }

        switch (choice) {
            case 1: addSalaryRecord(database, &staffCount); break;
            case 2: viewSalarySheet(database, staffCount); break;
            case 3: generatePaySlip(database, staffCount); break;
            case 4: printf("\nClosing administrative payroll backend database. Goodbye!\n"); break;
            default: printf("\n❌ Error: Selected option index out of boundaries. Pick 1 to 4.\n"); break;
        }
    } while (choice != 4);

    return 0;
}
