//Program to reverse a linked list.

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void addatbeg(struct node**,int);
void reverse(struct node**);
void display(struct node*);
int count(struct node*);

int main()
{
    struct node *p;
    p=NULL;

    addatbeg(&p,7);
    addatbeg(&p,74);
    addatbeg(&p,53);
    addatbeg(&p,32);
    addatbeg(&p,22);
    addatbeg(&p,3);
    display(p);

    reverse(&p);
    display(p);

    return 0;
}
//adds a new node at the beginning of the linked list.
void addatbeg(struct node **q,int num)
{
    struct node *temp;
    //add new node.
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->link = *q;
    *q=temp;
}
void reverse(struct node **x)
{
    struct node *q,*r,*s;
    q = *x;//q also starts pointing to the first node.
    r=NULL;
    //Traverse the entire linked list.
    while(q != NULL)
    {
        s=r;
        r=q;
        q=q->link;
        r->link=s;
    }
    *x=r;
}
//Display the contents of the linked list.
void display(struct node *q)
{
    //traverse the entire linked list.
    while(q != NULL)
    {
        printf("%d\t",q->data);
        q=q->link;
    }
    printf("\n");
}
