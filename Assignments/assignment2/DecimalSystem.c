#include<stdio.h>

int main() {
    while (1) {
        int choice;
        printf("Select a choice: \n 1.Addition \n 2.Multiplication \n 3.Exit \n");
        scanf("%d", &choice);

        if (choice == 1) {
            long int num1, num2;
            printf("Enter the first decimal number: ");
            scanf("%ld", &num1);

            printf("Enter the second decimal number: ");
            scanf("%ld", &num2);
            long long int sum = num1 + num2;
            printf("Sum is: %lld \n\n", sum);

        } else if (choice == 2) {
            long int num1, num2;
            printf("Enter the first decimal number: ");
            scanf("%ld", &num1);

            printf("Enter the second decimal number: ");
            scanf("%ld", &num2);

            long long int product = num1 * num2;
            printf("Product is: %lld \n\n", product);

        } else {
            printf("Exiting..\n");
            break;
        }
    }

    return 0;
}