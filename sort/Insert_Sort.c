#include <stdio.h>


void insert_Sort(int a[], int NUM) {
    int key,j;
    for(int i=1; i<NUM; i++) {
        j=i;
    key= a[i];
        while(j!=0) {
            if(key<a[j-1]) {
                for(int i=0;i<NUM;i++) {
                   printf("%d, ",a[i]);
              }
                printf("\n");
                a[j]=a[j-1];
                a[j-1]=key;
            }
            j--;
        }
        
    }
    
}

int main() {
    int NUM;
    printf("정렬할 숫자를 입력:");
    scanf("%d",&NUM);
    
    int a[NUM];
    
    for(int i=0; i<NUM; i++) {
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    
    insert_Sort(a, NUM);
    
    for(int i=0;i<NUM;i++) {
        printf("a[%d]: %d  ",i, a[i]);
    }
    
    return 0;
}

