#include <stdio.h>

int main()
{
    int num,i,left[7],money[7]={0,500,100,50,10,5,1};
    int totalnum=0,leftmoney,a;
    
    scanf("%d",&num);
    for(i=1;i<=6;i++)
       scanf("%d",&left[i]);
    
    if(1000-num*25>left[1]*500+left[2]*100+left[3]*50+left[4]*10+left[5]*5+left[6]) 
       printf("-1");
    else
    {  
       leftmoney=1000-25*num;
       for(i=1;i<=6;i++)
       {
          if(i==6)
          {
             if(left[i]>leftmoney)
             {
                 totalnum+=leftmoney;
                 leftmoney=0;
                 break;
             }   
          }
          if(leftmoney==0)
             break;
          
          if(leftmoney>left[i]*money[i])
          {
             leftmoney-=left[i]*money[i];
             totalnum+=left[i];
          }
          else
          {
              a=leftmoney/money[i];
              leftmoney-=a*money[i];
              totalnum+=a;
          }
          
       }
       if(leftmoney!=0)
          printf("-1");
       else
          printf("%d",totalnum); 
    }
    return 0;
}
