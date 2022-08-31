#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateAverageCaseInput(int *arr, int n);

void generateBestCaseInput(int *arr, int n);

void generateWorstCaseInput(int *arr, int n);

void sort(int *arr, int n);

int main() {

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    clock_t start, end;

//    Average case
    generateAverageCaseInput(arr, n);

    start = clock();
    sort(arr, n);
    end = clock();
    printf("Total time taken for Average Case is : %f\n",
           (double) (end - start) / (double) CLOCKS_PER_SEC);

//    Best case
    generateBestCaseInput(arr, n);

    start = clock();
    sort(arr, n);
    end = clock();
    printf("Total time taken for Best Case is : %f\n",
           (double) (end - start) / (double) CLOCKS_PER_SEC);

//    Worst case
    generateWorstCaseInput(arr, n);
    start = clock();
    sort(arr, n);
    end = clock();

    printf("Total time taken for Worst Case is : %f\n",
           (double) (end - start) / (double) CLOCKS_PER_SEC);

    return 0;
}

void sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {

        for (int j = i; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } else break;
        }

    }
}

void generateWorstCaseInput(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i - 1;
}

void generateAverageCaseInput(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % n;
}

void generateBestCaseInput(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i;
}
