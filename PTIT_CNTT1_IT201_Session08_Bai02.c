#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, high, target);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu: ");
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmpfunc);

    printf("Mang sau khi sap xep la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int k;
    scanf("%d", &k);

    int idx = binarySearch(arr, 0, n - 1, k);
    if (idx != -1) {
        printf("vi tri : %d", idx);
    } else {
        printf("khong co trong mang");
    }

    free(arr);
    return 0;
}
