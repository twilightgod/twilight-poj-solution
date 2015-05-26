/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Giftbox
*       ID             : 3018
*       Date           : 12/15/2008
*       Time           : 18:14:47
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 501
#define MAXD 1001

struct Box
{
	int d[MAXD];
};

Box box[MAXN];
int n,m,best;
int f[MAXN];

bool cmp(Box a,Box b)
{
	for(int i=0;i<m;++i)
	{
		if(a.d[i]>=b.d[i])
		{
			return false;
		}
	}
	return true;
}

bool cmp1(Box a,Box b)
{
	return a.d[0]<b.d[0];
}

int main()
{
	//freopen("in_3018.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<m;++j)
			{
				scanf("%d",&box[i].d[j]);
			}
			sort(box[i].d,box[i].d+m);
		}
		sort(box+1,box+n+1,cmp1);
		sort(box+1,box+n+1,cmp);
		best=0;
		f[0]=1;
		for(int i=1;i<=n;++i)
		{
			f[i]=0;
			int maxf=0;
			for(int j=0;j<i;++j)
			{
				if(cmp(box[j],box[i])&&f[j]>maxf)
				{
					maxf=f[j];
				}
			}
			if(maxf)
			{
				f[i]=maxf+1;
			}
			if(f[i]>best)
			{
				best=f[i];
			}
		}
		if(best)
		{
			printf("%d\n",best-1);
		}
		else
		{
			printf("Please look for another gift shop!\n");
		}
	}
	return 0;
}

