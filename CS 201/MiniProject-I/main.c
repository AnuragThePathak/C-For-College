/*
* Anurag Pathak
* Registration No. 2012018
* MiniProject-1
* CS 201, 
* Data Structures, 
* Department of Computer Science and Engineering, 
* National Institute of Technology Silchar
*/


#include<stdio.h>

#define MAX 4500

char answer[MAX], temp1[MAX], temp2[MAX];

void addition() {
    int x = 0;
    for (int i = MAX - 1; i >= 0; i--) {
        int digit = (temp1[i] - '0') + (temp2[i] - '0') + x;
        answer[i] = (digit % 10) + '0';
        x = digit / 10;
    }
}


void fibonacci(int n) {
    if (n == 1 || n == 0) {
        printf("%d", n);
        return;
    }
    for (int i = 2; i <= n; i++) {
        addition();
        for (int j = 0; j < MAX; j++) {
            temp1[j] = temp2[j];
            temp2[j] = answer[j];

        }
    }
    int firstDigit = 0;
    for (int i = 0; i < MAX; i++) {
        if (firstDigit == 0 && answer[i] == '0') {
            continue;
        }

        if (firstDigit == 0 && answer[i] != '0') {
            firstDigit = 1;
        }
        printf("%c", answer[i]);
    }

}


int main() {
    int n;
    printf("Enter the index of the fibonacci number to be found: ");
    scanf("%d", &n);

    for (int i = 0; i < MAX; i++) {
        temp1[i] = '0';
        temp2[i] = '0';
        answer[i] = '0';
    }
    temp2[MAX - 1] = '1';
    printf("The %dth fibonacci number is : ", n);
    fibonacci(n);
    printf("\n");

    return 0;
}
