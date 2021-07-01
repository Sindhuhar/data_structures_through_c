//Inserting an element in an array

#include<stdio.h>
#define max 100

void main()
{
    int p[max],i,n,k,j;

    printf("Enter the length of array:\n");
    scanf("%d",&n);

    printf("Enter %d elements of array\n",n);
    for(i=0;i<=n-1;i++)
        scanf("%d",&p[i]);

    printf("\nThe array is:\n");
        for(i=0;i<=n-1;i++)
            printf("%d\n",p[i]);

    printf("Enter the position where to insert: \n");
    scanf("%d",&k);
    k--; //The position is always one value higher than the subscript,so it is decremented by one

    for(j=n-1;j>=k;j--)
        p[j+1]=p[j];

    printf("Enter the value to insert: \n");
    scanf("%d",&p[k]);

    printf("Array after insertion of element: \n");
        for(i=0;i<=n;i++)
            printf("%d\n",p[i]);


}
