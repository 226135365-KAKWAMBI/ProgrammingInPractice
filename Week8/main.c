#include <stdio.h>
#include <string.h>

void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void clearInputBuffer();

char supplierName[100] = "";
char email[100] = "";
char phone[20] = "";
char town[50] = "";
int supplierExists = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar())!= '\n' && c!= EOF);
}

void displayMenu() {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

void addSupplier() {
    clearInputBuffer();
    printf("Enter Supplier Name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter Phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter Town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    supplierExists = 1;
    printf("Supplier added! Length (strlen): %lu\n", strlen(supplierName));
}

void displaySupplier() {
    if (!supplierExists) {
        printf("No supplier added yet!\n");
        return;
    }
    char backup[100];
    char fullInfo[200];
    strcpy(backup, supplierName); // strcpy
    strcpy(fullInfo, supplierName);
    strcat(fullInfo, " - "); // strcat
    strcat(fullInfo, town);

    printf("\n--- Supplier Details ---\n");
    printf("Name: %s (backup: %s)\n", supplierName, backup);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town: %s\n", town);
    printf("Combined: %s\n", fullInfo);
}

void searchSupplier() {
    if (!supplierExists) {
        printf("No supplier to search!\n");
        return;
    }
    char searchName[100];
    clearInputBuffer();
    printf("Enter supplier to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplierName, searchName) == 0) { // strcmp
        printf("Supplier FOUND: %s\n", supplierName);
    } else {
        printf("Supplier NOT found.\n");
    }
}

float calculateVAT(float amount) { return amount * 0.15f; }
float calculateSalary(float basic, float housing, float transport) { return basic + housing + transport; }
float calculateBudget(float revenue, float expenses) { return revenue - expenses; }

int main() {
    int choice;
    do {
        displayMenu();
        if (scanf("%d", &choice)!= 1) {
            clearInputBuffer();
            printf("Invalid! Enter 1-7.\n");
            continue;
        }
        switch(choice) {
            case 1: addSupplier(); break;
            case 2: displaySupplier(); break;
            case 3: searchSupplier(); break;
            case 4: {
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT (15%%): %.2f\n", calculateVAT(amount));
                break;
            }
            case 5: {
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
            case 6: {
                float revenue, expenses;
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenditure: ");
                scanf("%f", &expenses);
                printf("Budget Balance: %.2f\n", calculateBudget(revenue, expenses));
                break;
            }
            case 7: printf("Goodbye.\n"); break;
            default: printf("Invalid choice! Choose 1-7 only.\n"); break;
        }
    } while(choice!= 7);
    return 0;
}