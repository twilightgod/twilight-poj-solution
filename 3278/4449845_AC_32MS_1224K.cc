/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Catch That Cow
*       ID             : 3278
*       Date           : 12/3/2008
*       Time           : 16:54:41
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 100001

int f[MAXN];
int n,k;
int q[MAXN];
int h,t;
int here;

int main()
{
	//freopen("in_3278.txt","r",stdin);
	while (cin>>n>>k)
	{
		memset(f,0,sizeof(f));
		f[n]=1;
		h=-1;
		t=0;
		q[0]=n;
		while (h!=t)
		{
			here=q[++h];
			if (here-1>=0&&!f[here-1])
			{
				q[++t]=here-1;
				f[here-1]=f[here]+1;
				if (here-1==k)
				{
					break;
				}
			}
			if (here+1<MAXN&&!f[here+1])
			{
				q[++t]=here+1;
				f[here+1]=f[here]+1;
				if (here+1==k)
				{
					break;
				}
			}
			if (here*2<MAXN&&!f[here*2])
			{
				q[++t]=here*2;
				f[here*2]=f[here]+1;
				if (here*2==k)
				{
					break;
				}
			}
		}
		cout<<f[k]-1<<endl;
	}
	return 0;
}
