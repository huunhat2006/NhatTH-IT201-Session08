#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[],int n) {
    for(int i=1;i<n;i++) {
        int key=a[i];
        int j=i-1;
        while(j >=0 && a[j] > key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int binarySearch(int a[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (a[mid] == target) {
        return mid;
    } else if (a[mid] > target) {
        return binarySearch(a, low, mid - 1, target);
    } else {
        return binarySearch(a, mid + 1, high, target);
    }
}

int main(void) {
    int n;
    scanf("%d",&n);
    int* a = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("Moi nhap gia tri cho phan tu thu %d: ", i+1);
        scanf("%d",&a[i]);
    }
    printf("Mang truoc khi sap xep la:\n");
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");

    insertion_sort(a,n);

    printf("Mang sau khi sap xep la:\n");
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");

    int valueLinearSearch;
    printf("Moi nhap gia tri de tim kiem tuyen tinh: ");
    scanf("%d",&valueLinearSearch);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (valueLinearSearch == a[i]) {
            count++;
            printf("Vi tri: %d\n", i + 1);
        }
    }
    if (count == 0) {
        printf("khong tim thay phan tu\n");
    }

    int valueBinarySearch;
    printf("Moi nhap gia tri de tim kiem nhi phan: ");
    scanf("%d",&valueBinarySearch);

    int idx = binarySearch(a, 0, n - 1, valueBinarySearch);
    if (idx != -1) {
        printf("vi tri : %d", idx + 1);
    } else {
        printf("khong co trong mang");
    }
    free(a);
    return 0;
}