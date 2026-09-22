#include <stdio.h>

int main() {
    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;

    printf("=== Municipal Employee Salary Analysis (50 Employees) ===\n");

    for (int i = 1; i <= 50; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        total = total + salary;

        if (i == 1) {
            highest = salary;
            lowest = salary;
        }

        if (salary > highest) {
            highest = salary;
        }

        if (salary < lowest) {
            lowest = salary;
        }
    }

    average = total / 50;

    printf("\n--- Salary Report ---\n");
    printf("Total Expenditure: %.2f\n", total);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);

    return 0;
}