#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu: ");
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (k == arr[i]) {
            count++;
            printf("Vi tri: %d", i + 1);
        }
    }
    if (count == 0) {
        printf("khong tim thay phan tu");
        free(arr);
        return 0;
    }

    free(arr);
    return 0;
}