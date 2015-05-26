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

#define MAXN 5000000
#define MAXP 500000

bool used[MAXN];
int a[MAXP];

int main()
{
	//freopen("in_2081.txt","r",stdin);
	a[0]=0;
	memset(used,false,sizeof(used));
	for (int i=1;i<=MAXP;++i)
	{
		int t=a[i-1]-i;
		if (t>0&&!used[t])
		{
			a[i]=t;
		}
		else
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
