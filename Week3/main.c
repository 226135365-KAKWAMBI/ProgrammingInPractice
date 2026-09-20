#include <stdio.h>

int main() {
    float basicSalary, housing, transport, tax;
    float grossSalary, netSalary;

    printf("=== EMPLOYEE SALARY CALCULATOR ===\n");

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    // Arithmetic + assignment operators
    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\n--- Salary Summary ---\n");
    printf("Gross Salary: %.2f\n", grossSalary);
    printf("Net Salary: %.2f\n", netSalary);

    // Relational + if...else (Page 21 requirement)
    if (netSalary >= 20000) {
        printf("Income Category: High Income\n");
    } else {
        printf("Income Category: Standard Income\n");
    }

    return 0;
}