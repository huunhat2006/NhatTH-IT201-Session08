#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quick_sort(int a[], int low, int high) {
    if(low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    int pivot = a[mid];

    int i = low;
    int j = high;
    while(i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    if (low < j) quick_sort(a, low, j);
    if (i < high) quick_sort(a, i, high);
}

int main(void) {
    int n;
    scanf("%d",&n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le");
        return 0;
    }

    int* a = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("Moi nhap gia tri cho phan tu thu %d: ", i+1);
        scanf("%d",&a[i]);
    }
    quick_sort(a, 0, n-1);
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }

    free(a);
    return 0;
}
//độ phức tạp tốt nhất O(n log n)
//độ phức tạp trung bình O(n log n)
//độ phức tạp xấu nhất O(n²)
