/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Count Color
*       ID             : 2777
*       Date           : 11/17/2008
*       Time           : 18:46:28
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 100000

struct Node
{
	bool mark;
	int colors;
};

Node IT[2*MAXN-1];
int bin[30];
int l,t,o,a,b,c;
char ch;

inline int GetLoc(int l,int r)
{
	return (l+r)|(l!=r);
}

int ITUpdate(int l,int r,int c)
{
	int v=GetLoc(l,r);
	if(b<l||a>r)
	{
		return IT[v].colors;
	}
	if(l>=a&&r<=b)
	{
		IT[v].colors=c;
		IT[v].mark=true;
		return c;
	}
	int m=(l+r)>>1,
		lc=GetLoc(l,m),
		rc=GetLoc(m+1,r);
	if(IT[v].mark)
	{
		IT[lc].colors=IT[v].colors;
		IT[lc].mark=true;
		IT[rc].colors=IT[v].colors;
		IT[rc].mark=true;
		IT[v].mark=false;
	}
	return IT[v].colors=ITUpdate(l,m,c)|ITUpdate(m+1,r,c);
}

int ITQuest(int l,int r)
{
	int v=GetLoc(l,r);
	if(b<l||a>r)
	{
		return 0;
	}
	if(l>=a&&r<=b)
	{
		return IT[v].colors;
	}
	int m=(l+r)>>1,
		lc=GetLoc(l,m),
		rc=GetLoc(m+1,r);
	if(IT[v].mark)
	{
		IT[lc].colors=IT[v].colors;
		IT[lc].mark=true;
		IT[rc].colors=IT[v].colors;
		IT[rc].mark=true;
		IT[v].mark=false;
	}
	return ITQuest(l,m)|ITQuest(m+1,r);
}

int CountColors(int c)
{
	int count=0;
	while(c)
	{
		count+=c%2;
		c/=2;
	}
	return count;
}

int main()
{
	//freopen("in_2777.txt","r",stdin);
	bin[0]=1;
	for(int i=1;i<30;++i)
	{
		bin[i]=bin[i-1]<<1;
	}
	while(scanf("%d%d%d",&l,&t,&o)!=-1)
	{
		int root=GetLoc(0,l-1);
		IT[root].colors=1;
		IT[root].mark=true;
		/*
		for(int i=0;i<2*l-1)
		{
			IT[i].mark=false;
		}
		*/
		while(o--)
		{
			getchar();
			scanf("%c%d%d",&ch,&a,&b);
			a--;b--;
			if(a>b)
			{
				if(ch=='P')
				{
					printf("0\n");
				}
				continue;
			}
			if(ch=='C')
			{
				scanf("%d",&c);
				ITUpdate(0,l-1,bin[c-1]);
			}
			else
			{
				printf("%d\n",CountColors(ITQuest(0,l-1)));
			}
		}
	}
	return 0;
}
