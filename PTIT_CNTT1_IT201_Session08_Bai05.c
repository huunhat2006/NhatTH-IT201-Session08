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

int main(void) {
    int n;
    scanf("%d",&n);
    int* a = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("Moi nhap gia tri cho phan tu thu %d: ", i+1);
        scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }

    free(a);
    return 0;
}