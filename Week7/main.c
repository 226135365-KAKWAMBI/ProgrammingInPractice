#include <stdio.h>
#include <string.h>

int main() {
    char supplierName[100];
    char email[100];
    char phone[20];
    char town[50];
    char backupName[100];
    char searchName[100];
    char fullInfo[200];

    printf("=== Week 7: Supplier Management (Strings) ===\n");

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

    // 1. strlen()
    printf("\n--- Supplier Information ---\n");
    printf("Name: %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town: %s\n", town);
    printf("Length of supplier name: %lu\n", strlen(supplierName));

    // 2. strcpy()
    strcpy(backupName, supplierName);
    printf("Backup copy of name (strcpy): %s\n", backupName);

    // 3. strcat()
    strcpy(fullInfo, supplierName);
    strcat(fullInfo, " - ");
    strcat(fullInfo, town);
    printf("Full Info (strcat): %s\n", fullInfo);

    // 4. strcmp() - Search
    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplierName, searchName) == 0) {
        printf("Supplier found: %s\n", supplierName);
    } else {
        printf("Supplier not found.\n");
    }

    return 0;
}