#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define MAXN 10001

struct Se
{
	int p,d;
};

Se s[MAXN];
int n;
priority_queue<int> q;

bool cmp(Se a,Se b)
{
	return a.d>b.d;
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&s[i].p,&s[i].d);
		}
		sort(s,s+n,cmp);
		int t=s[0].d;
		int k=0;
		int ans=0;
		while(!q.empty())
		{
			q.pop();
		}
		int c=0;
		while(t&&c!=n)
		{
			while(k<n&&s[k].d==t)
			{
				q.push(s[k].p);
				k++;
			}
			if(!q.empty())
			{
				ans+=q.top();
				q.pop();
				c++;
			}
			if(q.empty()&&k>=n)
			{
				break;
			}
			if(q.empty()&&k<n)
			{
				t=s[k].d;
			}
			else
			{
				t--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
