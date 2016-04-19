#include <stdio.h>
#include <stdlib.h>
int time=0;

typedef struct{
        char name[50];
        int pre;
        int sta;
        int fin;
        int parent;
        int color;//  white=0,gray=1,darkgray=2;
        int nle[500];
}Lesson;
void DFSVisit(Lesson a[501],int u)
{
    
    int pnum,nlenum,i,now;
    
    a[u].color=1;
    time++;
    a[u].sta=time;
    nlenum=a[u].nle[0];
    for(i=1;i<=nlenum;i++)
    {
        now=a[u].nle[i];
        if(a[now].color==0)
        {
             a[now].parent=u;
             DFSVisit(a,now);
        }
    }
    a[u].color=2;
    time++;
    a[u].fin=time;
}

void DFS(Lesson a[501],int n)
{
     int i;
     for(i=1;i<=n;i++)
     {
         a[i].color=0;
         a[i].parent=0;
     }
     for(i=1;i<=n;i++)
        if(a[i].color==0)
           DFSVisit(a,i);
}

int main()
{
    int i,j,n,nlenum,k;
    Lesson a[501];
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)   {scanf("%s",&a[i].name);a[i].nle[0]=0;}
    for(i=1;i<=n;i++)
    {
       printf("Please input the number of No.%d lesson's pre-lesson:",i);
       scanf("%d",&a[i].pre);
       
       
       if(a[i].pre==0)
       {
          continue;
       }

       for(j=1;j<=a[i].pre;j++)
       {
          printf("The pre-lesson numbers are:");
          scanf("%d",&k);
          
          (a[k].nle[0])++;
          nlenum=(a[k].nle[0]);
          a[k].nle[nlenum]=i;
          //printf("%d 's nextlesson :%d.\n",k,a[k].nle[nlenum]);
       }
       
    }
    DFS(a,n);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        k=a[i].nle[0];
        printf("%d has %d of next.   ",i,k);
        printf("%d 's next are:",i);
        for(j=1;j<=k;j++)
           printf("%d ",a[i].nle[j]);
        printf("\n");
    } 
    for(i=1;i<=n;i++)
    {
         printf("\n%d 's start time: %d,finish time:%d.",i,a[i].sta,a[i].fin); 
    }
    return 0;
}
 
