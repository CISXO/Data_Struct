#include <stdio.h>

int stack[100];
int top=0;

void push(int a) {
	stack[top]= a;
	top++;

}

int pop() {
	top--;
	return stack[top];
}

int main() {

int s = 4;
push(s);
s++;
push(s);
s++;
printf("%d",pop());



return 0; 
 }


