#include <stdio.h>

int main()
{
    double revenue;
    double expenses;
    double balance;

    // For extension exercise
    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("----------------------------\n");

    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);

    printf("Enter Number of Departments: ");
    scanf("%d", &departments);

    printf("Enter Total Payroll: ");
    scanf("%lf", &payroll);

    printf("Enter Procurement Cost: ");
    scanf("%lf", &procurement);

    printf("Enter Total Assets Value: ");
    scanf("%lf", &assets);

    balance = revenue - expenses;

    printf("\n--- BUDGET SUMMARY ---\n");
    printf("Revenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance: %.2f\n", balance);

    if (balance > 0) {
        printf("Status: Surplus of %.2f\n", balance);
    } else if (balance < 0) {
        printf("Status: Deficit of %.2f\n", -balance);
    } else {
        printf("Status: Budget is Balanced\n");
    }

    printf("\n--- MUNICIPAL FINANCIAL SUMMARY ---\n");
    printf("Departments: %d\n", departments);
    printf("Payroll: %.2f\n", payroll);
    printf("Procurement: %.2f\n", procurement);
    printf("Assets: %.2f\n", assets);

    return 0;
}