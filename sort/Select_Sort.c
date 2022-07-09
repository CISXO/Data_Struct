
#include <stdio.h>

int min_(int a[], int i, int NUM) {
    int min=a[i];
    int key=i;
    for(; i<NUM ;i++) {
        if(min>a[i]) {
            min=a[i];
            key=i;
        }
    }
    return key;
}

void Selection_sort(int a[], int NUM) {
    int key=0;
    int temp;
    for(int i=1; i<NUM; i++) {
        
    key= min_(a,i,NUM);
        if(a[i-1]>a[key]) {
            temp=a[i-1];
            a[i-1]=a[key];
            a[key]=temp;
            
        }
        printf("%d번째 순서: [",i);
        for(int i=0;i<NUM-1;i++) {
            printf("%d, ",a[i]);
        }
        printf("%d]", a[NUM-1]);
        printf("\n");
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
    Selection_sort(a,NUM);
    
    for(int i=0;i<NUM;i++) {
        printf("a[%d]: %d  ",i, a[i]);
    }
    
    return 0;
}

