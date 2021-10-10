#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int* arr, int n) {
    clock_t start = clock();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    clock_t end = clock();
    printf("Total elapsed time in bubble sort is: %f\n", (double)(end -start)/(double)CLOCKS_PER_SEC);
}

void selectionSort(int* arr, int n) {
    clock_t start = clock();

    for (int i = 0; i < n - 1; i++) {
        int end = n - i - 1;

        int max = end;
        for (int j = 0; j < end; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }

        int temp = arr[end];
        arr[end] = arr[max];
        arr[max] = temp;
    }

    clock_t end = clock();
    printf("Total elapsed time in selection sort is: %f\n", (double)(end -start)/(double)CLOCKS_PER_SEC);
}

int main() {
    int select;
    printf("Input 1 for random array, 2 for sorted: ");
    scanf("%d", &select);

    int n;
    printf("Input number of elements: ");
    scanf("%d", &n);

    int arr1[n];
    int arr2[n];

    if (select == 1) {
        for (int i = 0; i <= n; i++) {
            int x = rand() % n + 1;
            arr1[i] = x;
            arr2[i] = x;
        }
    }

    if (select == 2) {
        for (int i = 0; i < n; i++) {
            arr1[i] = i;
            arr2[i] = i;
        }
    }

    selectionSort(arr1, n);
    bubbleSort(arr2, n);

//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr1[i]);
//    }
//    printf("\n");
//
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr2[i]);
//    }
//    printf("\n");
    return 0;
}