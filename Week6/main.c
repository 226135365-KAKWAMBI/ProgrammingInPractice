#include <stdio.h>

int main() {
    float salaries[50];
    float total = 0;
    float average;
    float highest, lowest;
    float searchSalary;
    int found = 0;

    printf("=== Week 6: Municipal Salary Management System (Arrays) ===\n");

    // 1. Capture 50 salaries into array
    for (int i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        total += salaries[i];
    }

    // 2. Display all salaries
    printf("\n--- All Salaries ---\n");
    for (int i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    // 3. & 4. Total and Average
    average = total / 50;

    // 5. & 6. Highest and Lowest - init with first element
    highest = salaries[0];
    lowest = salaries[0];
    for (int i = 1; i < 50; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    printf("\n--- Salary Report ---\n");
    printf("Total Expenditure: %.2f\n", total);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);

    // 7. Search - Linear search
    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);
    for (int i = 0; i < 50; i++) {
        if (salaries[i] == searchSalary) {
            printf("Found %.2f at position %d (Employee %d)\n", searchSalary, i, i+1);
            found = 1;
            break; // use break as per Week 5 LO 7
        }
    }
    if (!found) {
        printf("Salary %.2f not found.\n", searchSalary);
    }

    // 8. & 9. Sort lowest to highest - Bubble Sort
    for (int i = 0; i < 50 - 1; i++) {
        for (int j = 0; j < 50 - i - 1; j++) {
            if (salaries[j] > salaries[j+1]) {
                float temp = salaries[j];
                salaries[j] = salaries[j+1];
                salaries[j+1] = temp;
            }
        }
    }

    // 10. Display sorted
    printf("\n--- Sorted Salaries (Lowest to Highest) ---\n");
    for (int i = 0; i < 50; i++) {
        printf("%.2f\n", salaries[i]);
    }

    return 0;
}