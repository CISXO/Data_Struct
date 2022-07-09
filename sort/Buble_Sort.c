
#include <stdio.h>

void Buble_Sort(int a[], int NUM) {
    int temp;
    for(int i=0; i<NUM; i++) {
        for(int j=1; j<NUM-i; j++) {
            if(a[j-1]>a[j]) {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
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
    
    Buble_Sort(a, NUM);
    
    for(int i=0;i<NUM;i++) {
        printf("a[%d]: %d  ",i, a[i]);
    }
    
    return 0;
}

