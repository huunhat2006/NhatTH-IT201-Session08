#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) {
        L[i] = a[left+i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid+1+j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
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
    merge_sort(a, 0, n-1);
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }

    free(a);
    return 0;
}
//độ phức tạp tốt nhất, trung bình, xấu nhất: O(n log n)
