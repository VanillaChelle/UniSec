#include <stdio.h>

int Findmax(int a[101][101],int N,int ai,int aj)
{
    int i,j,sum=0,max=-10000000,b[101],result=0;
    
    for(i=1;i<=N;i++)
    {
       sum=0;
       for(j=ai;j<=aj;j++)
          sum+=a[j][i];
       b[i]=sum;
    }
    //for(i=1;i<=N;i++) printf("%d ",b[i]);   printf("\n");
    for(i=1;i<=N;i++)
    {
       if(result>0)
          result+=b[i];
       else
          result=b[i];
       
       if(max<result)
          max=result;
    }
    return max;
}

void Find(int N)
{
    int a[101][101],i,j,max=-10000000,re;
    
    for(i=1;i<=N;i++)
       for(j=1;j<=N;j++)
          scanf("%d",&a[i][j]);
    
    for(i=1;i<=N;i++)
       for(j=i;j<=N;j++)
       {
          re=Findmax(a,N,i,j);
          if(max<re)
             max=re;
       }
       
    printf("%d",max);
    
}

int main()
{
    int N;
    scanf("%d",&N);
    Find(N);
    return 0;
}
