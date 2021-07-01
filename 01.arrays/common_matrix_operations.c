#include<stdio.h>
#define max 3

void creat(int[3][3]);
void display(int[3][3]);
void matadd(int[3][3],int[3][3],int[3][3]);
void matmul(int[3][3],int[3][3],int[3][3]);
void transpose(int[3][3],int[3][3]);

void main()
{
    int mat1[3][3],mat2[3][3],mat3[3][3],mat4[3][3],mat5[3][3];

    printf("Enter the elements of first array:\n");
    creat(mat1);

    printf("Enter the elements of second array:\n");
    creat(mat2);

    printf("First array:\n");
    display(mat1);

    printf("Second array:\n");
    display(mat2);

    matadd(mat1,mat2,mat3);
    printf("After addition:\n");
    display(mat3);

    matmul(mat1,mat2,mat4);
    printf("After multiplication:\n");
    display(mat4);

    transpose(mat1,mat5);
    printf("transpose of first matrix:\n");
    display(mat5);

    return 0;
}
void creat(int mat[3][3]) //Creates matrix mat.
{
    int i,j;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            printf("Enter the element:\n");
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
}
void display(int mat[3][3]) //displays the contents of matrix.
{
    int i,j;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
            printf("%d\t",mat[i][j]);
            printf("\n");
    }
}
void matadd(int mat1[3][3],int mat2[3][3],int mat3[3][3])
{
    int i,j;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
            mat3[i][j]=mat1[i][j]+mat2[i][j];
    }
}
void matmul(int mat1[3][3],int mat2[3][3],int mat4[3][3])
{
    int i,j,k;
    for(k=0;k<max;k++)
    {
        for(i=0;i<max;i++)
        {
            mat4[k][i]=0;
            for(j=0;j<max;j++)
                mat4[k][i]=mat4[k][i]+mat1[k][j]*mat2[j][i];
        }
    }
}
void transpose(int mat1[3][3],int mat2[3][3])
{
    int i,j;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
            mat2[i][j]=mat1[j][i];
    }
}
