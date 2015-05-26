/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Recaman's Sequence
*       ID             : 2081
*       Date           : 12/6/2008
*       Time           : 23:22:34
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 120000000
#define MAXP 500001

bool used[MAXN];
int a[MAXP];

int main()
{
	//freopen("in_2081.txt","r",stdin);
	a[0]=0;
	int m=-1;
	memset(used,false,sizeof(used));
	for (int i=1;i<=MAXP;++i)
	{
		a[i]=a[i-1]-i;
		if (a[i]<=0||used[a[i]])
		{
			a[i]=a[i-1]+i;
		}
		used[a[i]]=true;
	}
	int n;
	while (cin>>n)
	{
		if (n==-1)
		{
			break;
		}
		cout<<a[n]<<endl;
	}
	return 0;
}
