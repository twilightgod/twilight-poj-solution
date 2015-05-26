/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : World Cup Noise
*       ID             : 1953
*       Date           : 4/26/2009
*       Time           : 9:47:52
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 46

int f[MAXN][2];
int n,t,ca;

int main()
{
	//freopen("in_1953.txt","r",stdin);
	f[1][0]=f[1][1]=1;
	for(int i=2;i<MAXN;++i)
	{
		f[i][1]=f[i-1][0];
		f[i][0]=f[i-1][0]+f[i-1][1];
	}
	cin>>t;
	ca=0;
	while(t--)
	{
		cin>>n;
		printf("Scenario #%d:\n%d\n\n",++ca,f[n][0]+f[n][1]);
	}
	return 0;
}
