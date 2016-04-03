#include <stdio.h>
#define INF 214748364
int m[201][201];

int LookupChain(int p[201],int i,int j)
{
    int k,q;
    if(m[i][j]<INF)   return m[i][j];
    if(i==j)   m[i][j]=0;
    else
    {
        for(k=i;k<=j-1;k++)
        {
           q=LookupChain(p,i,k)+LookupChain(p,k+1,j)+p[i-1]*p[k]*p[j];
           if(q<m[i][j])
              m[i][j]=q;
        }
    }
    return m[i][j];
    
}

int main()
{
    int n,i,j,p[201],ans;
    
    scanf("%d",&n);
    for(i=0;i<=n;i++)
       scanf("%d",&p[i]);
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          m[i][j]=INF;
    ans=LookupChain(p,1,n);
    printf("%d",ans);
    return 0;
}