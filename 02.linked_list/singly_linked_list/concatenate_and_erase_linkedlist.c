//Program to concatenate and erase the linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void append(struct node**, int);
void concat(struct node**,struct node**);
void display(struct node*);
int count(struct node*);
struct node*erase(struct node*);

int main()
{
    struct node *first,*second;
    first=second=NULL; //empty linked list.

    append(&first,1);
    append(&first,2);
    append(&first,3);
    append(&first,4);

    printf("First list:\n");
    display(first);

    printf("Number of elements in the first linked list=%d\n",count(first));

    append(&second,5);
    append(&second,6);
    append(&second,7);
    append(&second,8);

    printf("Second list:\n");
    display(second);

    printf("Number of elements in second linked list=%d\n",count(second));

    //Result obtained after the concatenation is in the first linked list.

    concat(&first,&second);
    printf("concatenated list:\n");
    display(first);

    printf("Number of elements present before erasing=%d\n",count(first));

    first=erase(first);

    printf("number of elements present after erasing=%d\n",count(first));
    return 0;
}
//adds a node at the end of the linked list.
void append(struct node **q, int num)
{
    struct node *temp;
    temp = *q;

    if(*q==NULL)  //if the list is empty,create first node.
    {
        *q=(struct node*)malloc(sizeof(struct node));
        temp = *q;
    }
    else
    {
        //go to last node.
        while(temp->link != NULL)
        temp=temp->link;

        //add node at the end.

        temp->link=(struct node*)malloc(sizeof(struct node));
        temp=temp->link;
    }
    //assign data to the last node.
    temp->data=num;
    temp->link=NULL;
}
//concatenate two linked list.
void concat(struct node **p,struct node **q)
{
    struct node *temp;
    //if the first linked list is empty.
    if (*p == NULL)
        *p = *q;
    else
    {
        //if both linked list are non empty.
        if(*q != NULL)
        {
            temp = *p; //points to the starting of the first linked list.

            //traverse the entire linked list.
            while(temp->link != NULL)
                temp=temp->link;

                temp->link = *q; //concatenate the second list after the first.
        }
    }
}
    //displays the contents of the linked list.
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
    //counts the number of elements of node present in the lined list.
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

//erase all the nodes from a linked list.
struct node *erase(struct node *q)
{
    struct node *temp;

    //traverse till the end,erasing each node.
    while(q != NULL)
    {
        temp=q;
        q=q->link;
        free(temp); //free the memory occupied by the node.
    }
    return NULL;
}
