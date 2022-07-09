
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a= *b;
    *b = temp;
}

void max_heap(int a[], int NUM, int i) {
    int node = i;
    int left_child = i*2 +1;
    int right_child = i*2 +2;
    
    if(left_child < NUM && a[node] < a[left_child]) {
        node = left_child;
    }
    if(right_child < NUM && a[node] < a[right_child]) {
        node = right_child;
    }
    if(i != node) {
        swap(&a[node], &a[i]);
        max_heap(a, NUM, node);
    }
    
}

void min_heap(int a[], int NUM, int i) {
    int node = i;
    int left_child = i*2 +1;
    int right_child = i*2 +2;
    
    if(left_child < NUM && a[node] > a[left_child]) {
        node = left_child;
    }
    if(right_child < NUM && a[node] > a[right_child]) {
        node = right_child;
    }
    if(i != node) {
        swap(&a[node], &a[i]);
        min_heap(a, NUM, node);
    }
    
}


void heap_sort(int a[], int n) {
    
    for(int i= (n/2)-1; i>=0; i--) {
        min_heap(a, n, i);
    }
}

void delete_heap(int a[], int n) {
    printf("%d ",a[0]);
    a[0] = a[n-1];
    heap_sort(a, n-1);
}

int main() {
    int NUM;
    printf("정렬할 숫자를 입력:");
    scanf("%d",&NUM);
    
    int a[NUM];
    
    for(int i=0; i<NUM; i++) {
        a[i]= (rand()%99 +1);
    }
    //max_heapfy 상태
    heap_sort(a, NUM);
    
    for (int i = 0; i < NUM; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    for(int i=NUM; i> 0; i--) {
        delete_heap(a,i);
    }
    


    return 0;
}

