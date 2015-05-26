/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The 3n + 1 problem
*       ID             : 1207
*       Date           : 11/18/2008
*       Time           : 14:19:2
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 10001

int times[MAXN];
int i,j,a,b,m,n;

int main()
{
	//freopen("in_1207.txt","r",stdin);
	for(i=1;i<MAXN;++i)
	{
		times[i]=1;
		n=i;
		while(n!=1)
		{
			n=n%2==1?3*n+1:(n>>1);
			times[i]++;
		}
	}
	while(cin>>a>>b)
	{
		cout<<a<<' '<<b<<' ';
		if(a>b)
		{
			a^=b;
			b^=a;
			a^=b;
		}
		m=1;
		for(i=a;i<=b;++i)
		{
			if(m<times[i])
			{
				m=times[i];
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
