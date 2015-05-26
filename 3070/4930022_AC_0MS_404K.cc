/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Fibonacci
*       ID             : 3070
*       Date           : 4/6/2009
*       Time           : 21:56:41
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<fstream>
using namespace std;
#define MAXLEN 100
#define m 10000

struct mat
{
	int _11,_12,_21,_22;
};

int i,len;
long long n;
bool bin[MAXLEN];
mat ms[MAXLEN];

//矩阵乘法
mat matmul(int a,int b)
{
	mat c;
	c._11=((ms[a]._11*ms[b]._11)%m+(ms[a]._12*ms[b]._21)%m)%m;
	c._12=((ms[a]._11*ms[b]._12)%m+(ms[a]._12*ms[b]._22)%m)%m;
	c._21=((ms[a]._21*ms[b]._11)%m+(ms[a]._22*ms[b]._21)%m)%m;
	c._22=((ms[a]._21*ms[b]._12)%m+(ms[a]._22*ms[b]._22)%m)%m;
	return c;
}

int main()
{
	//freopen("in_3070.txt","r",stdin);
	//计算M^(2^i)
	ms[1]._11=ms[1]._12=ms[1]._21=1;
	ms[1]._22=0;
	for(i=2;i<=MAXLEN;++i)
	{
		ms[i]=matmul(i-1,i-1);
	}
	//读入
	while(scanf("%I64d",&n)&&n!=-1)
	{
		//将n转为二进制
		len=0;
		while(n!=0)
		{
			len++;
			bin[len]=(n%2==0)?false:true;
			n>>=1;
		}
		//ms[0]保存结果,初值为单位阵
		ms[0]._11=ms[0]._22=1;
		ms[0]._12=ms[0]._21=0;
		for(i=1;i<=len;++i)
		{
			if(bin[i])
			{
				ms[0]=matmul(0,i);
			}
		}
		printf("%d\n",ms[0]._12);
	}
	return 0;
}
	