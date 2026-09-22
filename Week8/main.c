#include <stdio.h>
#include <string.h>

// Function prototypes - Week 8 LO 2
void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);

// Global supplier storage (simple Week 7-8)
char supplierName[100] = "";
char email[100] = "";
char phone[20] = "";
char town[50] = "";
int supplierExists = 0;

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
    // Clear leftover newline from scanf
    getchar();
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
    printf("Supplier added! Name length: %lu\n", strlen(supplierName));
}

void displaySupplier() {
    if (!supplierExists) {
        printf("No supplier added yet!\n");
        return;
    }
    char backup[100];
    char fullInfo[200];

    strcpy(backup, supplierName); // strcpy demo
    strcpy(fullInfo, supplierName);
    strcat(fullInfo, " - "); // strcat demo
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
    getchar();
    printf("Enter supplier to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplierName, searchName) == 0) { // strcmp demo
        printf("Supplier FOUND: %s\n", supplierName);
    } else {
        printf("Supplier NOT found.\n");
    }
}

float calculateVAT(float amount) {
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4: {
                float amt;
                printf("Enter amount: ");
                scanf("%f", &amt);
                printf("VAT (15%%): %.2f\n", calculateVAT(amt));
                break;
            }
            case 5: {
                float b,h,t;
                printf("Enter basic, housing, transport: ");
                scanf("%f %f %f", &b, &h, &t);
                printf("Total Salary: %.2f\n", calculateSalary(b,h,t));
                break;
            }
            case 6: {
                float rev, exp;
                printf("Enter revenue and expenditure: ");
                scanf("%f %f", &rev, &exp);
                printf("Budget Balance: %.2f\n", calculateBudget(rev,exp));
                break;
            }
            case 7:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 7);
    return 0;
}