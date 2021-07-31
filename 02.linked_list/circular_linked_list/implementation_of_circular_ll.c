#include<stdio.h>
#include<conio.h>
/*Circular linked list declaration*/
struct cl_node
{
int INFO;
struct cl_node *NEXT;
};
struct cl_node *FIRST = NULL;
struct cl_node *LAST = NULL;
/*Declaring function prototypes for list operations*/
void insert(int);
int delete(int);
void print(void);
struct cl_node *search (int);

void main()
{
int num1, num2, choice;
struct cl_node *location;
/*Displaying a menu of choices for performing list operations*/
while(1)
{
clrscr();
printf("\n\nSelect an option\n");
printf("\n1 - insert");
printf("\n2 - Delete");
printf("\n3 - Search");
printf("\n4 - Print");
printf("\n5 - Exit");
printf("\n\nEnter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
{
printf("\nEnter the element to be inserted into the circular linked list: ");
scanf("%d",&num1);
insert(num1); /*Calling the insert() function*/
printf("\n%d successfully inserted into the linked list!",num1);
getch();
break;
}
case 2:
{
printf("\nEnter the element to be deleted from the circular linked list: ");
scanf("%d",&num1);
num2=delete(num1); /*Calling the delete() function */
if(num2==-9999)
printf("\n\t%d is not present in the list\n\t",num1);
else
printf("\n\tElement %d successfully deleted from the list\n\t",num2);
getch();
break;
}

case 3:
{
printf("\nEnter the element to be searched: ");
scanf("%d",&num1);
location=search(num1); /*Calling the search()function*/
if(location==NULL)
printf("\n\t%d is not present in the list\n\t",num1);
else
printf("\n\tElement %d is present before element %d in the circular linked list\n\t",num1,(location->NEXT)->INFO);
getch();
break;
}

case 4:
{
print(); /*Printing the list elements*/
getch();
break;
}
case 5:
{
exit(1);
break;
}
default:
{
printf("\nIncorrect choice. Please try again.");
getch();
break;

}
}
}
}
/*Insert function*/
void insert(int value)
{
/*Creating a new node*/
struct cl_node *PTR = (struct cl_node*)malloc(sizeof(struct cl_node));
/*Storing the element to be inserted in the new node*/
PTR->INFO = value;
/*Linking the new node to the circular linked list*/
if(FIRST==NULL)
{
FIRST = LAST = PTR;
PTR->NEXT=FIRST;
}
else
{
LAST->NEXT = PTR;
PTR->NEXT = FIRST;
LAST = PTR;
}
}
/*Delete function*/
int delete(int value)
{
struct cl_node *LOC,*TEMP;
int i;
i=value;
LOC=search(i); /*Calling the search() function*/
if(LOC==NULL) /*Element not found*/
return(-9999);
if(LOC==FIRST)
{
if(FIRST==LAST)
FIRST=LAST=NULL;
else
{
FIRST=FIRST->NEXT;
LAST->NEXT=FIRST;

}
return(value);
}
for(TEMP=FIRST;TEMP->NEXT!=LOC;TEMP=TEMP->NEXT)
;
if(LOC==LAST)
{
LAST=TEMP;
TEMP->NEXT=FIRST;
}
else
TEMP->NEXT=LOC->NEXT;
return(LOC->INFO);
}
/*Search function*/
struct cl_node *search (int value)
{
struct cl_node *PTR;
if(FIRST==NULL) /*Checking for empty list*/
return(NULL);
if(FIRST==LAST && FIRST->INFO==value) /*Checking if there is only one
element in the list*/
return(FIRST);
/*Searching the linked list*/
for(PTR=FIRST;PTR!=LAST;PTR=PTR->NEXT)
if(PTR->INFO==value)
return(PTR); /*Returning the location of the searched element*/
if(LAST->INFO==value)
return(LAST);
else
return(NULL); /*Returning NULL value indicating unsuccessful search*/

}
/*print function*/
void print()
{
struct cl_node *PTR;
if(FIRST==NULL) /*Checking whether the list is empty*/
{
    printf("\n\tEmpty List!!");
return;
}
printf("\nCircular linked list elements:\n");
if(FIRST==LAST) /*Checking if there is only one element in the list*/
{
printf("\t%d",FIRST->INFO);
return;
}
/*Printing the list elements*/
for(PTR=FIRST;PTR!=LAST;PTR=PTR->NEXT)
printf("\t%d",PTR->INFO);
printf("\t%d",LAST->INFO);
}




