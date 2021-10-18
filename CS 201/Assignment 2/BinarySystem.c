#include <stdio.h>

int binaryProduct(long bin1, long bin2) {
    int i = 0, remainder = 0, sum[20];
    int binaryprdct = 0;

    while (bin1 != 0 || bin2 != 0) {
        sum[i++] = (bin1 % 10 + bin2 % 10 + remainder) % 2;
        remainder = (bin1 % 10 + bin2 % 10 + remainder) / 2;
        bin1 = bin1 / 10;
        bin2 = bin2 / 10;
    }

    if (remainder != 0) {
        sum[i++] = remainder;
    }
    --i;

    while (i >= 0) {
        binaryprdct = binaryprdct * 10 + sum[i--];
    }

    return binaryprdct;
}

int main() {
    long bin1, bin2, multiply = 0;
    int i = 0, remainder = 0, sum[20], digit, factor = 1;

    while (1) {
        printf("Enter the Choice :\n");
        printf("1.Addition\n2.Multiplication\n3.Exit\n");

        int select;

        scanf("%d", &select);
        if (select == 1) {
            printf("Enter the first binary number: ");
            scanf("%ld", &bin1);
            printf("Enter the second binary number: ");
            scanf("%ld", &bin2);

            while (bin1 != 0 || bin2 != 0) {
                sum[i++] = (bin1 % 10 + bin2 % 10 + remainder) % 2;
                remainder = (bin1 % 10 + bin2 % 10 + remainder) / 2;
                bin1 = bin1 / 10;
                bin2 = bin2 / 10;
            }

            if (remainder != 0) {
                sum[i++] = remainder;
            }
            i--;

            printf("Sum of two binary numbers: ");
            while (i >= 0) {
                printf("%d", sum[i--]);
            }

            printf("\n\n");

        } else if (select == 2) {
            printf("Enter the first binary number: ");
            scanf("%ld", &bin1);
            printf("Enter the second binary number: ");
            scanf("%ld", &bin2);

            while (bin2 != 0) {
                digit = bin2 % 10;
                if (digit == 1) {
                    bin1 = bin1 * factor;
                    multiply = binaryProduct(bin1, multiply);
                } else {
                    bin1 = bin1 * factor;
                }

                bin2 = bin2 / 10;
                factor = 10;
            }

            printf("Product of two binary numbers: %ld\n", multiply);
            printf("\n");

        } else if (select == 3) {
            printf("Exiting...\n");
            break;
        }
    }


    return 0;
}