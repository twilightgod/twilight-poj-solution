/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Hall of Fountains
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1943
*       ID             : 1943
*       Date           : 5/24/2009
*       Time           : 22:31:54
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<queue>
using namespace std;

#define MAXR 5041 
#define MAXN 105

struct Node
{
	int x,tc;
	Node(int _x,int _tc)
	{
		x=_x;
		tc=_tc;
	}
	Node()
	{
		x=tc=0;
	}
};

int p[MAXN],q[MAXN];
int tt[MAXN][MAXR];
bool w[MAXN][MAXR];
int n,ans,c;
bool god;
queue<Node> qu;

int GCD(int a,int b)
{
	while(b)
	{
		int c=a%b;
		a=b;
		b=c;	
	}
	return a;
}

int LCM(int a,int b)
{
	return a/GCD(a,b)*b;
}

void BFS()
{
	god=true;
	while(!qu.empty())
	{
		qu.pop();
	}
	//memset(tt,0,sizeof(tt));
	for(int i=0;i<=n+1;++i)
	{
		for(int j=0;j<c;++j)
		{
			tt[i][j]=0;
		}
	}
	tt[0][0]=1;
	qu.push(Node(0,0));
	while(!qu.empty())
	{
		Node now=qu.front(),next;
		//cout<<now.x<<' '<<now.tc<<' '<<tt[now.x][now.tc]<<endl;
		if(now.x==n+1)
		{
			god=false;
			ans=tt[now.x][now.tc];
			break;
		}
		qu.pop();
		//left
		next.x=now.x-1;
		next.tc=(now.tc+1)%c;
		if(next.x>=0&&!w[next.x][next.tc]&&(tt[next.x][next.tc]==0))
		{
			qu.push(next);
			tt[next.x][next.tc]=tt[now.x][now.tc]+1;
		}
		//right
		next.x=now.x+1;
		next.tc=(now.tc+1)%c;
		if(next.x<=n+1&&!w[next.x][next.tc]&&(tt[next.x][next.tc]==0))
		{
			qu.push(next);
			tt[next.x][next.tc]=tt[now.x][now.tc]+1;
		}
		//stay
		next.x=now.x;
		next.tc=(now.tc+1)%c;
		if(!w[next.x][next.tc]&&(tt[next.x][next.tc]==0))
		{
			qu.push(next);
			tt[next.x][next.tc]=tt[now.x][now.tc]+1;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("in_1943.txt","r",stdin);
	freopen("D:\\Development\\Sources\\hall\\in.txt","r",stdin);
	freopen("D:\\Development\\Sources\\hall\\list.txt","w",stdout);
#endif
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;++i)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;++i)
		{
			cin>>q[i];
		}
		c=1;
		for(int i=1;i<=n;++i)
		{
			if(p[i])
			{
				c=LCM(c,p[i]);
			}
		}
		c<<=1;
		for(int j=0;j<c;++j)
		{
			w[n+1][j]=w[0][j]=false;
		}
		for(int i=1;i<=n;++i)
		{
			if(p[i]==0)
			{
				for(int j=0;j<c;++j)
				{
					w[i][j]=false;
				}
				continue;
			}
			int cnt=0;
			bool ty=true;
			int st=q[i];
			for(int j=0;j<c;++j)
			{
				w[i][st]=ty;
				cnt++;
				st++;
				if(cnt==p[i])
				{
					cnt=0;
					ty=!ty;
				}
				if(st==c)
				{
					st=0;
				}
			}
		}
		ans=0;
		BFS();
		if(god)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<ans-1<<endl;
		}
		//return 0;
	}
	return 0;
}
