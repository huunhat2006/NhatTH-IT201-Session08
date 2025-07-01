#include <stdio.h>
#include <stdlib.h>

void selection_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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
    selection_sort(a,n);
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }

    free(a);
    return 0;
}