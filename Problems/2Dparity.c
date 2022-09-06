#include<stdio.h>
int main()
{
        int a,b,i,j,count;
        printf("Enter number of original data:");
        scanf("%d",&a);
        printf("Enter bit length:");
        scanf("%d",&b);
        count=0;
        int d[a][b];
        int c[a+1][b+1];
        for(i=0;i<a+1;i++)
        {
                for(j=0;j<b+1;j++)
                {
                        c[i][j]=0;
                }
        }
        for(i=0;i<a;i++)
        {
                for (j=0;j<b;j++)
                {
                        printf("Enter data %d:",i);
                        scanf("%d",&d[i][j]);
                        c[i][j]=d[i][j];
                }


        }
        for (i=0;i<a;i++)
        {
                for(j=0;j<b;j++)
                {
                        printf("%d\t",d[i][j]);
                }
                printf("\n");
        }
        for(i=0;i<a;i++)
        {
                for(j=0;j<b;j++)
                {
                        if(c[i][j]==1)
                        {
                                count=count+1;
                        }
                }
                if(count%2==0)
                {
                        c[i][b+1]=0;
                        count=0;
                }
                else
                {
                        c[i][b+1]=1;
                        count=0;
                }
        }
        for(i=0;i<b;i++)
        {
                for(j=0;j<a;j++)
                {
                        if(d[j][i]==1)
                        {
                                count=count+1;
                        }
                }
                if(count%2==0)
                {
                        c[a+1][i]=0;
                        count=0;
                }
                else
                {
                        c[a+1][i]=1;
                        count=0;
                }
        }
        printf("\n");
        for (i=0;i<a+1;i++)
        {
                for(j=0;j<b+1;j++)
                {
                        printf("%d\t",c[i][j]);
                }
                printf("\n");
        }
}

