/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Grandpa is Famous
*       ID             : 2092
*       Date           : 12/7/2008
*       Time           : 10:11:24
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 10001

struct Player
{
	int index,score;
};

Player p[MAXN];
int n,m;

bool cmp(Player a,Player b)
{
	if (a.score==b.score)
	{
		return a.index<b.index;
	}
	else
	{
		return a.score>b.score;
	}
}

int main()
{
	//freopen("in_2092.txt","r",stdin);
	while (scanf("%d%d",&n,&m)!=-1)
	{
		if (n==0&&m==0)
		{
			break;
		}
		for (int i=1;i<MAXN;++i)
		{
			p[i].index=i;
			p[i].score=0;
		}
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<m;++j)
			{
				int t;
				scanf("%d",&t);
				p[t].score++;
			}
		}
		sort(p+1,p+MAXN,cmp);
		printf("%d",p[2].index);
		for (int i=3;i<MAXN;++i)
		{
			if (p[i].score==p[i-1].score)
			{
				printf(" %d",p[i].index);
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
