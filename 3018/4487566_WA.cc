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
		sort(box+1,box+n+1,cmp);
		best=1;
		f[0]=0;
		for(int i=1;i<=n;++i)
		{
			if (cmp(box[f[best-1]],box[i]))
			{
				f[best++]=i;
			}
			else
			{
				int l=0,r=best-1,m;
				while (l<=r)
				{
					m=(l+r)>>1;
					if (cmp(box[f[m]],box[i]))
					{
						l=m+1;
					}
					else
					{
						r=m-1;
					}
				}
				if (l)
				{
					f[l]=i;
				}
			}
		}
		if(best>1)
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
