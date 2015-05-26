/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Gone Fishing
*       ID             : 1042
*       Date           : 5/15/2009
*       Time           : 15:27:3
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 25

template<typename T>
struct cmp
{
	bool operator () (T a,T b)
	{
		if(tf[a]==tf[b])
		{
			return a>b;
		}
		else
		{
			return tf[a]<tf[b];
		}
	}
};

priority_queue<int,vector<int>,cmp<int> > q;
int n,h,ans;
int f[MAXN],tf[MAXN],d[MAXN],t[MAXN],c[MAXN],best[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1042.txt","r",stdin);
#endif
	while(cin>>n&&n)
	{
		cin>>h;
		for(int i=0;i<n;++i)
		{
			cin>>f[i];
		}
		for(int i=0;i<n;++i)
		{
			cin>>d[i];
		}
		t[0]=0;
		for(int i=1;i<n;++i)
		{
			cin>>t[i];
		}
		ans=0;
		h*=12;
		int h1=0;
		for(int x=0;x<n;++x)
		{
			int tans=0;
			h1+=t[x];
			memset(c,0,sizeof(c));
			while(!q.empty())
			{
				q.pop();
			}
			for(int i=0;i<=x;++i)
			{
				tf[i]=f[i];
			}
			for(int i=0;i<=x;++i)
			{
				q.push(i);
			}
			for(int i=h1;i<h;++i)
			{
				int m=q.top();
				if(tf[m]<=0)
				{
					c[m]++;
					continue;
				}
				q.pop();
				tans+=tf[m];
				c[m]++;
				tf[m]-=d[m];
				q.push(m);
			}
			if(tans>ans)
			{
				ans=tans;
				for(int i=0;i<n;++i)
				{
					best[i]=c[i];
				}
			}
		}
		cout<<best[0]*5;
		for(int i=1;i<n;++i)
		{
			cout<<", "<<5*best[i];
		}
		cout<<"\nNumber of fish expected: "<<ans<<endl<<endl;
	}
	return 0;
}
