#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define MAXN 100

struct Node
{
	bool a[MAXN],b[MAXN];
};

int i,j,n,k,t,pi,m,test,ans;
string s;
char c;
Node wit[MAXN];
bool use[MAXN];

int fit(int x)
{
	int i,ret=0;
	for (i=0;i<m;++i)
	{
		if (wit[i].b[x])
		{
			break;
		}
	}
	if (i==m)
	{
		ret++;
	}
	for (i=0;i<m;++i)
	{
		if (wit[i].a[x])
		{
			break;
		}
	}
	if (i==m)
	{
		ret++;
	}
	return ret;
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	test=0;
	while (cin>>n>>k&&!(n==0&&k==0))
	{
		test++;
		memset(use,true,n);
		m=0;
		for (i=0;i<k;++i)
		{
			getchar();
			getline(cin,s);
			stringstream ss(s);
			ss>>pi;
			cin>>c;
			switch (c)
			{
			case '=':
				for (j=0;j<pi*2;++j)
				{
					ss>>t;
					use[t-1]=false;
				}
				break;
			case '<':
				memset(wit[m].a,false,n);
				memset(wit[m].b,false,n);
				for (j=0;j<pi;++j)
				{
					ss>>t;
					wit[m].a[t-1]=true;
				}
				for (j=0;j<pi;++j)
				{
					ss>>t;
					wit[m].b[t-1]=true;
				}
				m++;
				break;
			case '>':
				memset(wit[m].a,false,n);
				memset(wit[m].b,false,n);
				for (j=0;j<pi;++j)
				{
					ss>>t;
					wit[m].b[t-1]=true;
				}
				for (j=0;j<pi;++j)
				{
					ss>>t;
					wit[m].a[t-1]=true;
				}
				m++;
				break;
			}
		}
		ans=-1;
		for (i=0;i<n;++i)
		{
			if (use[i])
			{
				if (fit(i)!=0)
				{
					if (ans!=-1)
					{
						ans=-1;
						break;
					}
					else
					{
						ans=i;
					}
				}
			}
		}
		cout<<"Scenario #"<<test<<":\n"<<ans+1<<endl<<endl;
	}
	return 0;
}