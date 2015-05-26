/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Triangular Sums
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3086
*       ID             : 3086
*       Date           : 5/27/2009
*       Time           : 17:3:25
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
using namespace std;

#define MAXN 302

int T[MAXN];
int W[MAXN];
int n,t,ca;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3086.txt","r",stdin);
#endif
	T[1]=1;
	for(int i=2;i<=301;++i)
	{
		T[i]=T[i-1]+i;
	}
	W[1]=T[2];
	for(int i=2;i<=300;++i)
	{
		W[i]=W[i-1]+i*T[i+1];
	}
	ca=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<++ca<<' '<<n<<' '<<W[n]<<endl;
	}
	return 0;
}
