#include<iostream>
using namespace std;
#define MAXN 1000

int ans,n,i,j,t,test;
int a[MAXN];

int main()
{
	cin>>t;
	test=0;
	while(t--)
	{
		test++;
		cout<<"Scenario #"<<test<<":\n";
		cin>>n;
		for(i=0;i<n;++i)
		{
			cin>>a[i];
		}
		ans=0;
		for(i=0;i<n-1;++i)
		{
			for(j=i+1;j<n;++j)
			{
				if(a[i]>a[j])
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n\n";
	}
	return 0;
}
