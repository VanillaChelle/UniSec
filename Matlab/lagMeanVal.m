function [  ] = lagMeanVal( a,b )
%   证明拉格朗日中值定理
%   如果函数出错，可能是区间内有两个点满足要求，解决方法为适当减小区间
%   输出c的值为所求点的横坐标
%   ans为所求点的纵坐标
%   所画出的绿色线为所求直线
%   黄色线为区间两点连线
%   蓝色曲线为原函数曲线
syms x;
diff('2*sin(x)+0.5*cos(x)+x+5',x);  %这两行在命令行求得该函数导数为2*cos(x) - 0.5*sin(x) + 1

ffff=@(x)(2*sin(x)+0.5*cos(x)+x+5);
fa=ffff(a);
fb=ffff(b);
k=(fb-fa)/(b-a);
f11=@(x)(2*cos(x) - 0.5*sin(x) + 1-k);
c=fzero(f11,[a b])
ffff(c)
c1=ffff(c)-k*c;

x=0:0.01:2*pi;
y=k*x+c1;
plot(x,2*sin(x)+0.5*cos(x)+x+5,'b');
hold on;
plot([a b],[fa fb],'y');
hold on;
plot(x,y,'g');



end

