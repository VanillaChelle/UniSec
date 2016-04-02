#include <stdio.h>
#define INF 214748364
int m[201][201];
int RecurMatrixChain(int p[201],int i,int j)
{
    int k,q;
    if(i==j)  return 0;
    m[i][j]=INF;
    for(k=i;k<=j-1;k++)
    {
       q=RecurMatrixChain(p,i,k)+RecurMatrixChain(p,k+1,j)+p[i-1]*p[k]*p[j];
       if(q<m[i][j])
          m[i][j]=q;
    }
    return m[i][j];
}
int main()
{
    int n,i,p[201],ans;
    
    scanf("%d",&n);
    for(i=0;i<=n;i++)
       scanf("%d",&p[i]);
    ans=RecurMatrixChain(p,1,n);
    printf("%d",ans);
    return 0;
}
