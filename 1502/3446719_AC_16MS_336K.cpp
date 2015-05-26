#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define MAXN 100
#define MAXINT 2147483647

struct _e
{
	int v1,v2,w;
};

_e e[MAXN*MAXN];
int dis[MAXN];
int n,m,i,j,k;
bool relax;
string s;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	
	while (cin>>n)
	{
		m=0;
		for (i=0;i<n-1;++i)
		{
			for (j=0;j<i+1;++j)
			{
				cin>>s;
				if (s!="x")
				{
					stringstream ss(s);
					ss>>k;
					e[m].v1=e[m+1].v2=i+1;
					e[m].v2=e[m+1].v1=j;
					e[m].w=e[m+1].w=k;
					m+=2;
				}
			}
		}
		for (i=0;i<n;++i)
		{
			dis[i]=MAXINT;
		}
		dis[0]=0;
		for(i=0;i<n-1;++i)
		{
			relax=false;
			for(j=0;j<m;++j)
			{
				if(dis[e[j].v1]!=MAXINT&&dis[e[j].v1]+e[j].w<dis[e[j].v2])
				{
					dis[e[j].v2]=dis[e[j].v1]+e[j].w;
					relax=true;
				}
			}
			if(!relax)
			{
				break;
			}
		}
		m=0;
		for (i=1;i<n;++i)
		{
			if (dis[i]>m)
			{
				m=dis[i];
			}
		}
		cout<<m<<endl;
	}
	return 0;
}