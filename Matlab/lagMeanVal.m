function [  ] = lagMeanVal( a,b )
%   ֤������������ֵ����
%   �����������������������������������Ҫ�󣬽������Ϊ�ʵ���С����
%   ���c��ֵΪ�����ĺ�����
%   ansΪ������������
%   ����������ɫ��Ϊ����ֱ��
%   ��ɫ��Ϊ������������
%   ��ɫ����Ϊԭ��������
syms x;
diff('2*sin(x)+0.5*cos(x)+x+5',x);  %����������������øú�������Ϊ2*cos(x) - 0.5*sin(x) + 1

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

