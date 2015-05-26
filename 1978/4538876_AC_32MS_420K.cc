/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Hanafuda Shuffle
*       ID             : 1978
*       Date           : 1/7/2009
*       Time           : 3:15:20
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 50

int a[MAXN];
int t[MAXN];
int n,c,p,r;

int main()
{
	//freopen("in_1978.txt","r",stdin);
	while (cin>>n>>r&&n)
	{
		for (int i=0;i<n;++i)
		{
			a[i]=n-i;
		}
		for (int i=0;i<r;++i)
		{
			cin>>p>>c;
			for (int j=0;j<p-1;++j)
			{
				t[j]=a[j];
			}
			for (int j=p-1;j<p+c-1;++j)
			{
				a[j-p+1]=a[j];
			}
			for (int j=0;j<p-1;++j)
			{
				a[j+c]=t[j];
			}
		}
		cout<<a[0]<<endl;
	}
	return 0;
}
