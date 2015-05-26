/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Parkside's Triangle
*       ID             : 3173
*       Date           : 5/8/2009
*       Time           : 21:8:53
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 20

int a[MAXN][MAXN];
int n,s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3173.txt","r",stdin);
#endif
	cin>>n>>s;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			a[i][j]=s;
			if(++s==10)
			{
				s=1;
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			cout<<"  ";
		}
		for(int j=i;j<n;++j)
		{
			cout<<a[j][i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
