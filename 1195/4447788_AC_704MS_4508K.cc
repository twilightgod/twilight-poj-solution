/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Mobile phones
*       ID             : 1195
*       Date           : 12/2/2008
*       Time           : 20:49:34
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//二维树状数组
#include<iostream>
using namespace std;

#define MAXC 1024

int C[MAXC+1][MAXC+1];
int cmd,l,r,b,t,a,s,x,y;

inline int LowBit(int x)
{
	return x&(-x);
}

int Sum(int x,int y)
{
	int sum=0;
	while (x>0)
	{
		int t=y;
		while (t>0)
		{
			sum+=C[x][t];
			t-=LowBit(t);
		}
		x-=LowBit(x);
	}
	return sum;
}

void Modify(int x,int y,int delta,int len)
{
	while (x<=len)
	{
		int t=y;
		while (t<=len)
		{
			C[x][t]+=delta;
			t+=LowBit(t);
		}
		x+=LowBit(x);
	}
}

bool WorkLoop()
{
	while (1)
	{
		if(scanf("%d",&cmd)==-1)
		{
			return false;
		}
		switch (cmd)
		{
		case 0:
			{
				memset(C,0,sizeof(C));
				scanf("%d",&s);
				break;
			}
		case 1:
			{
				scanf("%d%d%d",&x,&y,&a);
				x++;
				y++;
				Modify(x,y,a,s);
				break;
			}
		case 2:
			{
				scanf("%d%d%d%d",&l,&b,&r,&t);
				l++;
				b++;
				r++;
				t++;
				printf("%d\n",Sum(r,t)-Sum(r,b-1)-Sum(l-1,t)+Sum(l-1,b-1));
				break;
			}
		case 3:
			{
				return true;
			}
		}
	}
}

int main()
{
	//freopen("in_1195.txt","r",stdin);
	while (WorkLoop());
	return 0;
}
