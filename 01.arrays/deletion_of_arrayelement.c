#include<stdio.h>

void main()
{
    int i,n,p[100],a;

    printf("Enter the length of array: \n");
    scanf("%d",&n);

    printf("Enter the %d elements of the array: \n",n);
        for(i=0;i<=n-1;i++)
            scanf("%d",&p[i]);

    printf("The array is: \n");
        for(i=0;i<=n-1;i++)
            printf("%d\n",p[i]);

    printf("Enter the position to delete: \n");
        scanf("%d",&a);
        a--;

    for(i=a;i<=n-1;i++)
    {
        p[i]=p[i+1]; //All values from the bottom of the array are shifted up till the location of the element to be deleted
    }
    p[n-1]=0;//Vacant position is created at the bottom of the array is set to zero

    printf("Array after deleting the element is \n");
        for(i=0;i<=n-2;i++)
            printf("%d\n",p[i]);
}
