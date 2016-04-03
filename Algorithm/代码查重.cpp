#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *fp1,*fp2,*f1end,*f2end;
    char f[2][100],a1,a2,A1[800],A2[800];
    
    int i,m=0,n=0;
    int j,f1num,f2num,avernum,c[700][700]={0};
    double percent;
    
    printf("Please input the first file name(It should be under this folder):");
    scanf("%s",f[0]);
    fp1=fopen(f[0],"r");
    printf("Please input the second file name(It should be under this folder,too):");
    scanf("%s",f[1]);
    fp2=fopen(f[1],"r");
    
    f1end=fopen(f[0],"r");
    fseek(f1end,0,SEEK_END);
    f1num=ftell(f1end);
    f2end=fopen(f[1],"r");
    fseek(f2end,1,SEEK_END);
    f2num=ftell(f2end);
    
    printf("%d %d\n",f1num,f2num);
    
    
    
    for(i=1;i<=f1num;i++)
    {
       a1=fgetc(fp1);
       if(a1!=' '&&a1!='\n'&&a1!='('&&a1!=')'&&a1!=';'&&a1!='{'&&a1!='}')
       {
          m++;
          A1[m]=a1;
          
       }
    }
    
    for(i=1;i<=f2num;i++)
    {
       a2=fgetc(fp2);
       if(a2!=' '&&a2!='\n'&&a2!='('&&a2!=')'&&a2!=';'&&a2!='{'&&a2!='}')
       {
          
          n++;
          A2[n]=a2;
       }
    }   //不知道为什么最后一行的换行删不掉，所以希望能手动删…… 
    
    for(i=1;i<=m;i++)  c[i][0]=0;
    for(j=0;j<=n;j++)  c[0][j]=0;
    for(i=0;i<=m;i++)   c[i][0]=0;
    for(i=0;i<=n;i++)   c[0][i]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
           if(A1[i]==A2[j])
              c[i][j]=c[i-1][j-1]+1;
           else if(c[i-1][j]>=c[i][j-1]) 
              c[i][j]=c[i-1][j];
           else
              c[i][j]=c[i][j-1];
        }  
    
    
    percent=(double)(c[m][n]*2.0/(m+n));
    printf("They are similar with each other at about %.2lf%%\n",percent*100.0);
    
    return 0;
}

