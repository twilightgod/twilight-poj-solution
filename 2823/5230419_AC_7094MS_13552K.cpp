/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sliding Window
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2823
*       ID             : 2823
*       Date           : 5/27/2009
*       Time           : 16:31:27
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 1000000

int num[MAXN];

struct cmp0
{
	bool operator()(int a,int b)
	{
		return num[a]>num[b];
	}
};

struct cmp1
{
	bool operator()(int a,int b)
	{
		return num[a]<num[b];
	}
};

priority_queue<int,vector<int>,cmp0 > q0;
priority_queue<int,vector<int>,cmp1 > q1;
int n,k;

inline void put(int x){
	if(x< 0){
		putchar('-');
		x = -x;
	}
	if(x == 0){
		putchar('0');
		return;
	}
	char s[20];
	int bas = 0;
	for(;x;x/=10)s[bas++] = x%10+'0';
	for(;bas--;)putchar(s[bas]);
	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2823.txt","r",stdin);
#endif
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&num[i]);
	}
	for(int i=0;i<k-1;++i)
	{
		q0.push(i);
	}
	for(int i=k-1;i<n;++i)
	{
		q0.push(i);
		while(i-q0.top()+1>k)
		{
			q0.pop();
		}
		put(num[q0.top()]);
		putchar(' ');
	}
	printf("\n");
	for(int i=0;i<k-1;++i)
	{
		q1.push(i);
	}
	for(int i=k-1;i<n;++i)
	{
		q1.push(i);
		while(i-q1.top()+1>k)
		{
			q1.pop();
		}
		put(num[q1.top()]);
		putchar(' ');
	}
	printf("\n");
	return 0;
}
