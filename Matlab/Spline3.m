function [  ] = Spline3( X,Y,flag,a,b )
%Spilne3����������������������ֵ����
%  Ӧ�����������
%  ����X,YΪ�������δ��x��y��ֵ
%  flagֻ��Ϊ1��2��,1��ʾ��һ�ֱ߽�����������֪����һ�׵�����2��ʾ�ڶ��ֱ߽�����������֪���˶��׵���
%  a�����˵�����b����Ҷ˵���
n=length(X);
h=zeros(1,n);
u=zeros(1,n);
k=zeros(1,n);
f=zeros(1,n);
d=zeros(n,1);
C=zeros(n,n);
S=zeros(n,1);
for i=1:n-1
    h(i)=X(i+1)-X(i);
end
for i=2:n-1
    u(i)=h(i-1)/(h(i-1)+h(i));
    k(i)=1-u(i);
end
for i=2:n
    f(i)=(Y(i)-Y(i-1))/(X(i)-X(i-1));
end

for i=2:n-1
    d(i)=6*(f(i+1)-f(i))/(h(i)+h(i-1));
end

if flag==1
    u(n)=1;
    k(1)=1;
    d(1)=6*(f(2)-a)/h(1);
    d(n)=6*(b-f(n))/h(n-1);
else
    u(n)=0;
    k(1)=0;
    d(1)=2*a;
    d(n)=2*b;
end

for i=1:n
    if i==1
        C(1,1)=2;
        C(1,2)=k(1);
    elseif i==n
        C(n,n)=2;
        C(n,n-1)=u(n);
    else
       for j=i-1:i+1
           if j==i
               C(i,j)=2;
           elseif j==i-1
               C(i,j)=u(i);
           else
               C(i,j)=k(i);
           end
       end
    end
end
M=inv(C)*d

syms x;
syms S;
for i=1:n-1
    S(i)=M(i)*(X(i+1)-x)^3/(6*h(i)) + M(i+1)*(x-X(i))^3/(6*h(i)) + (Y(i)-M(i)*h(i)^2/6)*(X(i+1)-x)/h(i) + (Y(i+1)-M(i+1)*h(i)^2/6)*(x-X(i))/h(i);
end

S
end

