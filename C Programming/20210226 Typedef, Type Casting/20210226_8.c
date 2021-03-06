/* Write a program to create a stack (LIFO) similar to the one in lecture 18, 
which, however, can be implemented with dynamic with dynamic memory allocation 
according to the user's wishes with the functions malloc (), and free (). */

#include <stdio.h>
#include <stdlib.h>

int MAXSIZE = 16;
int *stack;

int top = -1;

int isempty();
int isfull();
int peek();
int pop();
int push(int data);

int main(){
    stack = (int*)malloc(sizeof(int) * MAXSIZE);

    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);
    pop();
    pop();


    printf("Element at top of the stack: %d\n" ,peek());
    printf("Elements: \n");

    while(!isempty()){
        int data = pop();
        printf("%d\n",data);
    }
    printf("Stack full: %s\n" , isfull()?"true":"false");
    printf("Stack empty: %s\n" , isempty()?"true":"false");
    return 0;
}

int isempty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(){
    if(top == MAXSIZE){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(){
    return stack[top];
}

int pop(){
    int data;
    if(!isempty()){
        data = stack[top];
        top = top - 1;
        return data;
    } 
    else{
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data){
    if(!isfull()){
        top = top + 1;
        stack[top] = data;
    } 
    else{
    printf("Could not insert data, Stack is full.\n");
    }
}

/* Prints Element at top of the stack: 1
          Elements: 
          1
          9
          5
          3
          Stack full: false
          Stack empty: true */
