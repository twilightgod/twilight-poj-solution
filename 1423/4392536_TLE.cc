/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Big Number
*       ID             : 1423
*       Date           : 11/18/2008
*       Time           : 21:39:50
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

double ans[10000001];
int i,n,test;

int main()
{
	//freopen("in_1423.txt","r",stdin);
	ans[0]=0;
	for(i=2;i<=10000000;++i)
	{
		ans[i]=ans[i-1]+log10((double)i);
	}
	cin>>test;
	while(test--)
	{
		cin>>n;
		cout<<(int)floor((double)ans[n])+1<<endl;
	}
	return 0;
}
