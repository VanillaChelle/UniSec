#include <stdio.h>
#define INF 2147483647
typedef struct{
        int weit;
        double value;
        double aver;
}Obj;
void Merge(Obj a[1001],int p,int q,int r)
{
     int n1,n2,i,j,k;
     Obj L[1001],R[1001];
     
     n1=q-p+1;
     n2=r-q;
     for(i=1;i<=n1;i++)   L[i]=a[p+i-1];
     for(j=1;j<=n2;j++)   R[j]=a[q+j];
     L[n1+1].aver=INF;
     R[n2+1].aver=INF;
     i=1;j=1;
     for(k=p;k<=r;k++)
     {
         if(i>n1)  {a[k]=R[j]; j++;}
         else if(j>n2)  {a[k]=L[i]; i++;}
         else if(L[i].aver<=R[j].aver)
         {
            a[k]=R[j];
            j++;
         }
         else
         {
             a[k]=L[i];
             i++;
         }
     }
}
void MergeSort(Obj a[1001],int p,int r)
{
     int q;
     if(p<r)
     {
        q=(p+r)/2;
        MergeSort(a,p,q);
        MergeSort(a,q+1,r);
        Merge(a,p,q,r);
     }
}
int main()
{
    int m,n,i,j;
    double key,totalvalue=0.0,x,totalw;
    Obj a[1001],k;   
    
    scanf("%d%d",&m,&n); 
    
    for(i=1;i<=n;i++)
    {
       scanf("%d%lf",&a[i].weit,&a[i].value);  
       a[i].aver=a[i].value/(double)a[i].weit;                   
    }
    
    MergeSort(a,1,n);

    i=1;
    totalw=m;
    while(totalw>0&&i<=n)
    {
        if((double)totalw/(double)a[i].weit<1.0)
           x=(double)totalw/(double)a[i].weit;
        else
           x=1.0;
        totalw-=x*a[i].weit;
        totalvalue+=x*a[i].value;
        i++;
    }
    
    printf("%.6lf",totalvalue);
    
    return 0;
}
