#include<iostream>
#include<string>
using namespace std;
#define MAXN 50

bool ben;
string s;
int i,j,k,n,m,test;
double t;
string curname[MAXN];
double w[MAXN][MAXN];
double dis[MAXN][MAXN];

int Find(string s)
{
	int i;
	for(i=0;i<n;++i)
	{
		if(curname[i]==s)
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	//freopen("e:/in.txt","r",stdin);
	//freopen("e:/out.txt","w",stdout);	
	test=0;
	while(cin>>n&&n!=0)
	{
		test++;
		memset(w,0,sizeof(w));
		memset(dis,0,sizeof(dis));
		for(i=0;i<n;++i)
		{
			cin>>curname[i];
		}
		cin>>m;
		for(i=0;i<m;++i)
		{
			cin>>s;
			j=Find(s);
			cin>>t;
			cin>>s;
			k=Find(s);
			w[j][k]=t;
		}
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				if(i==j)
				{
					if(w[i][j]==0)
					{
						dis[i][j]=1;
					}
					else
					{
						dis[i][j]=w[i][j];
					}
				}
				else
				{
					dis[i][j]=w[i][j];
				}
			}
		}
		for(k=0;k<n;++k)
		{
			for(i=0;i<n;++i)
			{
				for(j=0;j<n;++j)
				{
					if(dis[i][k]!=0&&dis[k][j]!=0&&dis[i][j]<dis[i][k]*dis[k][j])
					{
						dis[i][j]=dis[i][k]*dis[k][j];
					}
				}
			}
		}
		ben=false;
		for(i=0;i<n;++i)
		{
			if(dis[i][i]>1)
			{
				ben=true;
				break;
			}
		}
		cout<<"Case "<<test<<": ";
		if(ben)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}

	}
	return 0;
}
