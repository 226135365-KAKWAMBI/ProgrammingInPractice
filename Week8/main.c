#include <stdio.h>
#include <string.h>

void displayMenu();
void addSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
void clearInputBuffer();

char supplierName[100] = "";
int supplierExists = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar())!= '\n' && c!= EOF);
}

void displayMenu() {
    printf("\n--- MFMS Menu ---\n");
    printf("1. Add Supplier\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Salary\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

void addSupplier() {
    clearInputBuffer();
    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';
    supplierExists = 1;
    printf("Supplier '%s' added\n", supplierName);
}

float calculateVAT(float amount) {
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

int main() {
    int choice;
    do {
        displayMenu();

        if (scanf("%d", &choice)!= 1) {
            clearInputBuffer();
            printf("Invalid! Please enter 1-4\n");
            continue;
        }

        switch(choice) {
            case 1:
                addSupplier();
                break;
            case 2: {
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT (15%%): %.2f\n", calculateVAT(amount));
                break;
            }
            case 3: {
                float basic, housing, transport;
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                printf("Total Salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;
            }
            case 4:
                printf("Exiting MFMS. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Choose 1-4 only.\n");
                break;
        }
    } while(choice!= 4);

    return 0;
}