#include<stdio.h>
#include<stdlib.h>
void even(int n)
{
    int a[50][50],i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=(i*n)+j+1;
        }
    }
    for(i=0;i<n/4;i++)
    {
        for(j=0;j<n/4;j++)
        {
            a[i][j]=(n*n+1)-a[i][j];
        }
    }
    for(i=0;i<n/4;i++)
    {
        for(j=3*n/4;j<n;j++)
        {
            a[i][j]=(n*n+1)-a[i][j];
        }
    }
    for(i=3*n/4;i<n;i++)
    {
        for(j=0;j<n/4;j++)
        {
            a[i][j]=(n*n+1)-a[i][j];
        }
    }
    for(i=3*n/4;i<n;i++)
    {
        for(j=3*n/4;j<n;j++)
        {
            a[i][j]=(n*n+1)-a[i][j];
        }
    }
    for(i=n/4;i<3*n/4;i++)
    {
        for(j=n/4;j<3*n/4;j++)
        {
            a[i][j]=(n*n+1)-a[i][j];
        }
    }
    printf("MSM:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void odd(int n)
{
    int *s,i,j,l;
    
    s=(int*)calloc(n*n,sizeof(int));
    i=n/2;
    j=n-1;
    for(l=1;l<=n*n;l++)
    {
        if(i==-1 && j==n)
        {
            i=0;
            j=n-2;
        }
        if(i==-1)
            i=n-1;
        if(j==n)
            j=0;
        if(*(s+i*n+j)!=0)
        {
            i++;
            j=j-2;
            *(s+i*n+j)=l;
            i--;
            j++;
        }
        else
        {
            *(s+i*n+j)=l;
            i--;
            j++;
        }
    }
    printf("Magic Square Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",*(s+i*n+j));
        }
        printf("\n");
    }
}
int main()
{
    int n;
    home:
    printf("Enter n:");
    scanf("%d",&n);
    if(n>2)
    {
        if(n%2==0)
            even(n);
        else
            odd(n);
    }
    else
    {
        printf("Enter valid input!\n");
        goto home;
    }
    return 0;
}
