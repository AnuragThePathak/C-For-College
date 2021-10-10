#include <stdio.h>

int main() {
    int m, n;
    printf("Enter the order of the matrix: ");
    scanf("%d %d", &m, &n);

    int arr1D[m * n];
    int arr2D[m][n];

    for (int i = 0; i < m * n; i++) {
        scanf("%d", &arr1D[i]);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr2D[i][j] = arr1D[(i * n) + j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr2D[i][j]);
        }
        printf("\n");
    }

    return 0;
}