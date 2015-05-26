/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Cow Bowling
*       ID             : 3176
*       Date           : 12/3/2008
*       Time           : 13:26:48
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 350

int a[MAXN][MAXN];
int f[MAXN][MAXN];
int n;

int main()
{
	//freopen("in_3176.txt","r",stdin);
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			for (int j=0;j<=i;++j)
			{
				cin>>a[i][j];
			}
		}
		for (int j=0;j<n;++j)
		{
			f[n-1][j]=a[n-1][j];
		}
		for (int i=n-2;i>=0;--i)
		{
			for (int j=0;j<=i;++j)
			{
				f[i][j]=(f[i+1][j]>f[i+1][j+1]?f[i+1][j]:f[i+1][j+1])+a[i][j];
			}
		}
		cout<<f[0][0]<<endl;
	}
	return 0;
}
