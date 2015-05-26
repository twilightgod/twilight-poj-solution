/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Apple Tree
*       ID             : 3321
*       Date           : 11/19/2008
*       Time           : 13:3:24
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 100001

struct Node
{
	int parent;
	int count;
	bool apple;
};

Node T[MAXN];
int m,n,i,p,v;
char ch;

int main()
{
	//freopen("in_3321.txt","r",stdin);
	while(scanf("%d",&n)!=-1)
	{
		for(i=1;i<=n;++i)
		{
			T[i].count=1;
			T[i].apple=true;
			T[i].parent=0;
		}
		for(i=1;i<n;++i)
		{
			scanf("%d%d",&p,&v);
			//T[v].count++;
			T[v].parent=p;
			while(T[v].parent!=0)
			{
				v=T[v].parent;
				T[v].count++;
			}
		}
		scanf("%d",&m);
		for(i=0;i<m;++i)
		{
			getchar();
			scanf("%c%d",&ch,&v);
			if(ch=='Q')
			{
				printf("%d\n",T[v].count);
			}
			else
			{
				if(T[v].apple)
				{
					p=-1;
					T[v].count--;
					T[v].apple=false;
				}
				else
				{
					p=1;
					T[v].count++;
					T[v].apple=true;
				}
				while(v!=1)
				{
					v=T[v].parent;
					T[v].count+=p;
				}
			}
		}
	}
	return 0;
}
