//Program that implements queue as an array.
#include<stdio.h>
#define MAX 10

struct queue
{
    int arr[MAX];
    int front,rear;
};
void initq(struct queue *);
void addq(struct queue*,int);
int delq(struct queue*);

int main()
{
    struct queue q;
    int n;

    initq(&q);

    addq(&q,34);
    addq(&q,12);
    addq(&q,54);
    addq(&q,32);

    n=delq(&q);
    if(n!=NULL)
    printf("Item Deleted : %d\n",n);

    n=delq(&q);
    if(n!=NULL)
    printf("Item Deleted : %d\n",n);

    n=delq(&q);
    if(n!=NULL)
    printf("Item Deleted : %d\n",n);

    n=delq(&q);
    if(n!=NULL)
    printf("Item Deleted : %d\n",n);

    n=delq(&q);
    if(n!=NULL)
    printf("Item Deleted : %d\n",n);

    return 0;
}
//Initializes the queue.
void initq(struct queue *pq)
{
    pq->front=-1;
    pq->rear=-1;
}
//Adds an element to the queue.
void addq(struct queue *pq,int item)
{
    if(pq->front==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    pq->rear++;
    pq->arr[pq->rear]=item;

    if(pq->front=-1)
        pq->front=0;
}
//Removes an element from the queue.
int delq(struct queue*pq)
{
    int data;
    if(pq->front==-1)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    data=pq->arr[pq->front];
    pq->arr[pq->front]=0;

    if(pq->front==pq->rear)
        pq->front=pq->rear=-1;
    else
        pq->front++;
        return data;
}
