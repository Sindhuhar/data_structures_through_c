//Program that implements stacks as a Linked List.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
void push(struct node**,int);
int pop(struct node**);
void delstack(struct node**);

int main()
{
    struct node *s=NULL;
    int n;

    push(&s,14);
    push(&s,-3);
    push(&s,18);
    push(&s,29);
    push(&s,31);
    push(&s,16);

    n=pop(&s);
    if(n!=NULL)
        printf("Item popped: %d\n",n);

    n=pop(&s);
    if(n!=NULL)
        printf("Item popped: %d\n",n);

    n=pop(&s);
    if(n!=NULL)
        printf("Item popped: %d\n",n);

    delstack(&s);

    return 0;
}
//Adds a new node at the beginning of linked list.
void push(struct node **top,int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    if(temp==NULL)
        printf("Stack is full\n");

    temp->data=item;
    temp->link=*top;
    *top=temp;
}
//deletes a node from the beginning of linked list.
int pop(struct node **top)
{
    struct node *temp;
    int item;

    if(*top==NULL)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    temp = *top;
    item = temp->data;
    *top = (*top)->link;

    free(temp);
    return item;

}
//deallocates memory.
void delstack(struct node **top)
{
    struct node *temp;
    if(*top==NULL)
        return;
    while(*top!=NULL)
    {
        temp=*top;
        *top=(*top)->link;
        free(temp);
    }
}
