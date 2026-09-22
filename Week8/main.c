#include <stdio.h>
#include <string.h>

void displayMenu();
void addSupplier();
void calculateVAT();
void calculateSalary();

void clearBuffer() {
    int c;
    while ((c = getchar())!= '\n' && c!= EOF);
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter choice: ");
        if (scanf("%d", &choice)!= 1) {
            clearBuffer();
            continue;
        }
        clearBuffer(); // FIX: removes the \n that was causing infinite loop

        switch(choice) {
            case 1: addSupplier(); break;
            case 4: calculateVAT(); break;
            case 5: calculateSalary(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice!= 0);
    return 0;
}

void displayMenu() {
    printf("\n--- MFMS Menu ---\n");
    printf("1. Add Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("0. Exit\n");
}

void addSupplier() {
    char name[100];
    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Supplier %s added\n", name);
}

void calculateVAT() {
    // your VAT code here
    printf("VAT calculated\n");
}

void calculateSalary() {
    float basic, housing, transport;
    printf("Enter basic, housing, transport: ");
    scanf("%f %f %f", &basic, &housing, &transport);
    clearBuffer();
    float total = basic + housing + transport;
    printf("Total Salary: %.2f\n", total);
}