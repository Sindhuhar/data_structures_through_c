//Program that implements a stack using an array.
#include<stdio.h>
#define MAX 10

struct stack
{
    int arr[MAX];
    int top;
};

void initstack(struct stack*);
void push(struct stack*, int item);
int pop(struct stack*);

int main()
{
    struct stack s;
    int n;

    initstack(&s);
    push(&s,2);
    push(&s,-4);
    push(&s,8);
    push(&s,11);

    n=pop(&s);
    if(n!=NULL);
    printf("Item popped: %d\n",n);

    n=pop(&s);
    if(n!=NULL);
    printf("Item popped: %d\n",n);

    n=pop(&s);
    if(n!=NULL);
    printf("Item popped: %d\n",n);

    n=pop(&s);
    if(n!=NULL);
    printf("Item popped: %d\n",n);

    n=pop(&s);
    if(n!=NULL);
    printf("Item popped: %d\n",n);

    return 0;
}
//initialize the stack
void initstack(struct stack *s)
{
    s->top=-1;
}
//adds an element to the stack.
void push(struct stack *s , int item)
{
    if(s->top==MAX-1)
    {
        printf("Stack is full\n");
        return ;
    }
    s->top++;
    s->arr[s->top]=item;
}
//Removes an element from the stack.
int pop(struct stack *s)
{
    int data;
    if(s->top==-1)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    data=s->arr[s->top];
    s->top--;
    return data;
}
