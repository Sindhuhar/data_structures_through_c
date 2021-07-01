#include<stdio.h>
#define MAX 5

void insert(int*,int pos, int num);
void del(int*,int pos);
void reverse(int*);
void display(int*);
void search(int*,int num);

int main()
{
    int arr[5];
    insert(arr,1,11);
    insert(arr,2,12);
    insert(arr,3,13);
    insert(arr,4,14);
    insert(arr,5,15);

    printf("Elements of array:\n");
    display(arr);

    del(arr,5);
    del(arr,2);

    printf("After deletion:\n");
    display(arr);

    insert(arr,2,222);
    insert(arr,5,555);
    printf("After insertion:\n");
    display(arr);

    reverse (arr);
    printf("After reversing:\n");
    display(arr);

    search(arr,222);
    search(arr,666);
    return(0);

}
//Insert an element number at a given position
void insert(int*arr,int pos, int num)
{
    //Shift elements to right
    int i;
    for(i=MAX-1;i>=pos;i--)
    arr[i]=arr[i-1];
    arr[i]=num;
}
void del(int*arr,int pos)
{
    //deletes an element from the given position
    int i;
    for(i=pos;i<MAX;i++)
    arr[i-1]=arr[i];
    arr[i-1]=0;
}
void reverse(int*arr)
{
    int i;
    for(i=0;i<MAX/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[MAX-1-i];
        arr[MAX-1-i]=temp;
    }
}
//Searches array for a given element number
void search(int*arr,int num)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(arr[i]==num)
        {
            printf("Element %d is at %d th position\n",num,i+1);
            return;
        }
    }
    printf("Element %d is absent\n",num);

}
//Display contents of an array
void display(int*arr)
{
    int i;
    for(i=0;i<MAX;i++)
        printf("%d\t",arr[i]);
        printf("\n");
}



