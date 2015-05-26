/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sorting by Swapping
*       ID             : 1674
*       Date           : 4/26/2009
*       Time           : 10:8:56
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 10001

bool used[MAXN];
int a[MAXN];
int n,t,ans;

int main()
{
	//freopen("in_1674.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			int u;
			cin>>u;
			a[u]=i;
			used[i]=false;
		}
		ans=0;
		for(int i=1;i<=n;++i)
		{
			if(!used[i])
			{
				ans++;
				int j=i;
				while(!used[j])
				{
					used[j]=true;
					j=a[j];
				}
			}
		}
		cout<<n-ans<<endl;
	}
	return 0;
}
