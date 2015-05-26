#include<iostream>
#include<string>
using namespace std;
#define MAXN 26

int p[MAXN];
int rank[MAXN];
int i,ans,n;
string s;

void MAKESET(int x)
{
	p[x]=x;
	rank[x]=0;
}

void LINK(int x,int y)
{
	if(rank[x]>rank[y])
	{
		p[y]=x;
	}
	else
	{
		p[x]=y;
		if(rank[x]==rank[y])
		{
			rank[y]++;
		}
	}
}

int FINDSET(int x)
{
	if(x!=p[x])
	{
		p[x]=FINDSET(p[x]);
	}
	return p[x];
}

void UNION(int x,int y)
{
	LINK(FINDSET(x),FINDSET(y));
}

int main()
{
	//freopen("e:/in.txt","r",stdin);
	cin>>s;
	n=s[0]-'A'+1;
	for(i=0;i<n;++i)
	{
		MAKESET(i);
	}
	while(cin>>s)
	{
		UNION(s[0]-'A',s[1]-'A');
	}
	ans=0;
	for(i=0;i<n;++i)
	{
		if(p[i]==i)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}