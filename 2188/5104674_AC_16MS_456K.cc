#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 1001

struct Wire
{
	int x,y;
};

Wire w[MAXN];

int n,ans;

bool cmp(Wire a,Wire b)
{
	return a.x<b.x;
}

int main()
{
	//freopen("in_2188.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int a,b;
		cin>>a>>b;
		w[a].x=w[b].y=i;
	}
	sort(w+1,w+n+1,cmp);
	ans=0;
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<i;++j)
		{
			if(w[j].y>w[i].y)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
