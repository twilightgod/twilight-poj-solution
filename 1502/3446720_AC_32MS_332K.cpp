#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define MAXN 100
#define MAXINT 2147483647

struct Node
{
	int w,v,next;
};

Node e[MAXN*MAXN];
int v[MAXN];
int dis[MAXN];
bool use[MAXN];
int qu[MAXN];
int n,m,i,j,k,head,tail;
string s;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	
	while (cin>>n)
	{
		memset(v,-1,sizeof(v));
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
					e[m].v=j;
					e[m].w=k;
					e[m].next=v[i+1];
					v[i+1]=m;
					m++;
					e[m].v=i+1;
					e[m].w=k;
					e[m].next=v[j];
					v[j]=m;
					m++;
				}
			}
		}
		for (i=0;i<n;++i)
		{
			dis[i]=MAXINT;
		}
		dis[0]=0;
		memset(use,false,sizeof(use));
		head=-1;
		tail=0;
		use[0]=true;
		while(head!=tail)
		{
			head=(head+1)%MAXN;
			i=qu[head];
			use[i]=false;
			for(k=v[i];k!=-1;k=e[k].next)
			{
				j=e[k].v;
				if(dis[i]+e[k].w<dis[j])
				{
					dis[j]=dis[i]+e[k].w;
					if(!use[j])
					{
						tail=(tail+1)%MAXN;
						use[j]=true;
						qu[tail]=j;
					}
				}
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
