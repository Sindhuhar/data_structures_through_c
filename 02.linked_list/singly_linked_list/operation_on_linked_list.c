//Implementation of various linked list operation.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
void append(struct node**, int);
void addatbeg(struct node**, int);
void addafter(struct node*,int,int);
void display(struct node*);
int count(struct node*);
void del(struct node**, int);

int main()
{
    struct node *p;
    p=NULL;  //Empty linked list

    printf("Number of elements in the linked list=%d\n",count(p));
    append(&p,14);
    append(&p,30);
    append(&p,25);
    append(&p,42);
    append(&p,17);
    display(p);

    addatbeg(&p,99);
    addatbeg(&p,88);
    addatbeg(&p,77);
    display(p);

    addafter(p,3,41);
    addafter(p,6,89);
    addafter(p,10,60);
    display(p);

    printf("Number of elements in the linked list=%d\n",count(p));

    del(&p,99);
    del(&p,42);
    del(&p,10);
    display(p);

    printf("Number of elements in the linked list=%d\n",count(p));
    return 0;
}
//Adds a node at the end of a linked list.
void append(struct node **q, int num)
{
    struct node *temp,*r;
    if(*q==NULL) //if the list is empty, create first node.
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=num;
        temp->link=NULL;
        *q=temp;
    }
    else
    {
        temp = *q;
        //go to last node
        while(temp->link != NULL)
            temp=temp->link;

        //add node at the end
        r=(struct node*)malloc(sizeof(struct node));
        r->data=num;
        r->link=NULL;
        temp->link=r;
    }
}
//Adds node at the beginning of the linked list
void addatbeg(struct node **q, int num)
{
    struct node *temp;
    //add new node.
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->link=*q;
    *q=temp;
}
//adds a new node after the specified number of nodes
void addafter(struct node *q,int loc,int num)
{
    struct node *temp,*r;
    int i;
    temp=q;
    //skip to desired portion.
    for(i=1;i<loc;i++)
    {
        temp=temp->link;
        //if end of the linked list id encountered.
        if(temp==NULL)
        {
            printf("There are less than %d elements in the list\n",loc);
            return ;
        }
    }
    //insert new node.
    r=(struct node*)malloc(sizeof(struct node));
    r->data=num;
    r->link=temp->link;
    temp->link=r;
}
//Displays the contents of the linked list.
void display(struct node *q)
{
    while(q != NULL)
    {
        printf("%d\t",q->data);
        q=q->link;
    }
    printf("\n");
}
//counts the number of nodes present in the linked list.
int count(struct node *q)
{
    int c=0;
    //traverse the entire linked list.
    while(q != NULL)
    {
        q=q->link;
        c++;
    }
    return c;
}
//deletes the specified node from the linked list
void del(struct node **q,int num)
{
    struct node *old,*temp;
    temp = *q;
    while(temp!=NULL)
    {
        if(temp->data == num)
        {
            //if node to be deleted is the first node in the linked list.
            if(temp==*q)
                *q=temp->link; //deletes the intermediate nodes in the linked list.
            else
                old->link=temp->link;
            free(temp); //free the memory occupied by the node.
            return ;
        }
        //traverse the linked list till the last node is reached.
        else
        {
            old=temp; //old points to the previous node.
            temp=temp->link; //go to the next node.
        }
    }
    printf("Element %d not found\n",num);
}




