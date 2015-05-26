#include<iostream>
using namespace std;

#define MAXN 16

int a[MAXN];
int n,ans;

int main()
{
	//freopen("in_1552.txt","r",stdin);
	while(1)
	{
		n=0;
		do
		{
			cin>>a[n++];
			if(a[n-1]==-1)
			{
				goto ret;
			}
		}while(a[n-1]!=0);
		ans=0;
		for(int i=0;i<n-1;++i)
		{
			for(int j=0;j<n-1;++j)
			{
				if(i!=j&&a[i]*2==a[j])
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
ret:return 0;
}
