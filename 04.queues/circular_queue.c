//Program that Performs the addition and deletion operation on a circular queue.
#include<stdio.h>
#define MAX 8
struct queue
{
    int arr[MAX];
    int front,rear;
};
void initq(struct queue*);
void addq(struct queue*,int);
int delq(struct queue*);
void display(struct queue*);

int main()
{
    struct queue q;
    int n;

    //initialize circular queue.
    initq(&q);

    addq(&q,14);
    addq(&q,22);
    addq(&q,13);
    addq(&q,-6);
    addq(&q,25);
    addq(&q,21);
    addq(&q,17);
    addq(&q,18);

    printf("Elements in the circular queue:\n");
    display(&q);

    n=delq(&q);
    if(n!=NULL)
        printf("Item deleted: %d\n",n);

    n=delq(&q);
    if(n!=NULL)
        printf("Item deleted: %d\n",n);

    printf("Elements in the circular queue after deletion:\n");
    display(&q);

    addq(&q,9);
    addq(&q,20);

    printf("Elements in the circular queue after addition:\n");
    display(&q);

    return 0;
}
//initializes an empty queue.
void initq(struct queue *pq)
{
    int i;
    pq->front=pq->rear=-1;
    for(i=0;i<MAX;i++)
        pq->arr[i]=0;
}
//adds an element to the queue.
void addq(struct queue *pq,int item)
{
    if((pq->rear==MAX-1 && pq->front==0) || (pq->rear+1==pq->front))
    {
        printf("Queue is empty\n");
        return;
    }
    if(pq->rear==MAX-1)
        pq->rear=0;
    else
        (pq->rear)++;
    pq->arr[pq->rear]=item;
    pq->front=0;
}
//Removes an element from the queue.
int delq(struct queue *pq)
{
    int data;

    if(pq->front==-1)
    {
        printf("Queue is empty:\n");
        return NULL;
    }
    data=pq->arr[pq->front];
    pq->arr[pq->front]=0;

    if(pq->front==pq->rear)
    {
        pq->front=-1;
        pq->rear=-1;
    }
    else
    {
        if(pq->front==MAX-1)
            pq->front=0;
        else
            (pq->front)++;
    }
    return data;
}
//Displays element in a queue.
void display(struct queue *pq)
{
    int i;
    for(i=0;i<MAX;i++)
        printf("%d\t",pq->arr[i]);
        printf("\n");
}
