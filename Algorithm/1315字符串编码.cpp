#include <stdio.h>
#define INF 2147483647
typedef struct{
        int weit;
        int parent;
        int lchild;
        int rchild;
        int depth;
}Node;
void AddDepth(Node a[20001],int root,int lc,int rc)
{
    a[lc].depth=a[root].depth+1;
    a[rc].depth=a[root].depth+1;
    if(a[lc].lchild!=-1)
      AddDepth(a,lc,a[lc].lchild,a[lc].rchild);
    if(a[rc].lchild!=-1)
      AddDepth(a,rc,a[rc].lchild,a[rc].rchild);
}
int main()
{
    int i=1,j,num=0,min1,min2,min1num,min2num,total=0,t[53]={0};//放26个大小写字母权值 
    char ch;
    Node a[20001];
    ch=getchar();
    
    while(ch!='\n')
    {
       if(ch>=97)
       {
          t[ch-97+27]++;
          if(t[ch-97+27]==1)
             num++;
       }
       else
       {
          t[ch-64]++;
          if(t[ch-64]==1)
             num++;
       }
       ch=getchar();
    }
    j=1;
    for(i=1;i<=num;i++)
    {
       while(t[j]==0)
          j++;
       a[i].weit=t[j];
       j++;
    }
    //for(i=1;i<=52;i++)    if(t[i]!=0)  if(i<=26) printf("%c: %d\n",64+i,t[i]);  else  printf("%c: %d\n",96+i-26,t[i]);
    //for(i=1;i<=num;i++)   printf("%d ",a[i].weit); 
    
    for(i=1;i<=2*num-1;i++)   //初始化 
    {
       a[i].parent=-1;
       a[i].lchild=-1;
       a[i].rchild=-1;
    }
    
    for(i=1;i<=num-1;i++)
    {
       min1=min2=INF;
       min1num=min2num=0;
       for(j=1;j<=num+i-1;j++)
       {
           if(a[j].parent!=-1)   continue;
           if(a[j].weit<min1)
           {
               min2=min1;
               min2num=min1num;
               min1=a[j].weit;
               min1num=j;
           }
           else if(a[j].weit<min2)
           {
                min2=a[j].weit;
                min2num=j;
           }
       }
       a[num+i].weit=a[min1num].weit+a[min2num].weit;
       a[num+i].lchild=min1num;
       a[num+i].rchild=min2num;
       a[min1num].parent=num+i;
       a[min2num].parent=num+i;
    }
    //for(i=num+1;i<=2*num-1;i++)   printf("No.%d个父节点为%d,lchaild为%d,rchild为%d\n",i-num,a[i].weit,a[i].lchild,a[i].rchild);
    
    if(num==1)
    {
       printf("%d",a[1].weit);
       return 0;
    } 
    a[2*num-1].depth=0;
    AddDepth(a,2*num-1,a[2*num-1].lchild,a[2*num-1].rchild);
    //for(i=1;i<=num;i++)   printf("No.%d个节点深度为%d\n",i,a[i].depth);
    for(i=1;i<=num;i++)
       total+=a[i].depth*a[i].weit;
    printf("%d",total);
    return 0;
}
