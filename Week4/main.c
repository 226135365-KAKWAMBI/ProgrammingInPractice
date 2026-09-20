#include <stdio.h>

int main() {
    char supplierName[50];
    float price, budget;
    int registered, documentsComplete;

    printf("=== TENDER EVALUATION SYSTEM ===\n");

    printf("Enter supplier name: ");
    scanf("%49s", supplierName);

    printf("Enter tender price: ");
    scanf("%f", &price);

    printf("Enter available budget: ");
    scanf("%f", &budget);

    printf("Is supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered);

    printf("Are all documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documentsComplete);

    printf("\n--- Evaluation Result ---\n");
    printf("Supplier: %s\n", supplierName);

    // Page 19: Combining logical and relational operators
    if (registered == 1 && documentsComplete == 1 && price <= budget) {
        printf("Status: Qualified\n");

        // Bonus: Preferred supplier if price is very competitive (< 90% of budget)
        if (price <= budget * 0.9) {
            printf("Note: Preferred Supplier - Competitive pricing!\n");
        }
    } else {
        printf("Status: Disqualified\n");
        // Show reason
        if (registered == 0) {
            printf("Reason: Not registered\n");
        }
        if (documentsComplete == 0) {
            printf("Reason: Incomplete documents\n");
        }
        if (price > budget) {
            printf("Reason: Price exceeds budget (%.2f > %.2f)\n", price, budget);
        }
    }

    return 0;
}