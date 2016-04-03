#include <stdio.h>
typedef struct{
        char name[100];
        double sta;
        double end;
}Obj;
int main()
{
    Obj g[1001],k;
    int num,i,j,ansnum=1,m,ans[1001];
    
    double sec,key;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        scanf("%s",g[i].name);
        scanf("%lf:%lf",&g[i].sta,&sec);
        g[i].sta+=sec/100.0;    //sec number saved as what they look like not what they really are.
        scanf("%lf:%lf",&g[i].end,&sec);
        g[i].end+=sec/100.0;
    }
    
    for(i=2;i<=num;i++)
    {
        key=g[i].end;
        k=g[i];
        j=i-1;
        while(j>0&&g[j].end>key)
        {
            g[j+1]=g[j];
            j=j-1;
        }
        g[j+1]=k;
    }
    
    /*for(i=1;i<=num;i++)
    {
        printf("%s %.2lf %.2lf\n",g[i].name,g[i].sta,g[i].end);
    }*/
    
    ans[1]=1;
    i=1;
    for(m=2;m<=num;m++)
    {
        if(g[m].sta>=g[i].end)
        {
            ansnum++;
            ans[ansnum]=m;
            i=m;
        }
    }
    printf("%d\n",ansnum);
    for(i=1;i<ansnum;i++)
       printf("%s ",g[(ans[i])].name);
    printf("%s",g[(ans[i])].name);
    
    
    return 0;
}
