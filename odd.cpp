#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,*s,i,j,l;
    printf("Enter odd number:");
    scanf("%d",&n);
    if(n%2==0)
        printf("Not an odd number!!\n");
    else
    {
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
    return 0;
}
