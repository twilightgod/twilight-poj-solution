#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<stack>
using namespace std;

#define MAXN 100000
#define MAXD 10

struct Node
{
	int u,i;
	Node(int _u,int _i)
	{
		u=_u;
		i=_i;
	}
};

bool link[MAXN][MAXD];
int n,m;
stack<Node> s;

/*
void DFS(int u)
{
	for(int i=0;i<MAXD;++i)
	{
		if(link[u][i])
		{
			link[u][i]=false;
			printf("%d",i);
			DFS((u*MAXD+i)%m);
		}
	}
}
*/

int main()
{
	//freopen("in_1009.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		m=(int)pow((double)10,(double)(n-1));
		for(int i=0;i<m;++i)
		{
			fill_n(link[i],MAXD,true);
		}
		for(int i=0;i<n-1;++i)
		{
			printf("0");
		}
//		DFS(0);
		while(!s.empty())
		{
			s.pop();
		}
		s.push(Node(0,0));
		while(!s.empty())
		{
noend:		Node no=s.top();
			s.pop();
			for(int i=no.i;i<MAXD;++i)
			{
				if(link[no.u][i])
				{
					link[no.u][i]=false;
					printf("%d",i);
					s.push(Node(no.u,i+1));
					s.push(Node((no.u*MAXD+i)%m,0));
					goto noend;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
