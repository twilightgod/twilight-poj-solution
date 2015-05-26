/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Phone Home
*       ID             : 1620
*       Date           : 1/4/2009
*       Time           : 23:35:53
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 12

int n,ca,best;
bool arc[MAXN][MAXN];
double x[MAXN],y[MAXN];
int c[MAXN];

bool Check(int i)
{
	for (int j=0;j<i;++j)
	{
		if (arc[i][j]&&c[i]==c[j])
		{
			return false;
		}
	}
	return true;
}

void DFS(int dep,int sum)
{
	if (dep==n)
	{
		best=sum;
		return;
	}
	for (int i=0;i<sum;++i)
	{
		c[dep]=i;
		if (Check(dep))
		{
			DFS(dep+1,sum);
		}
	}
	if (sum+1<best)
	{
		c[dep]=sum;
		DFS(dep+1,sum+1);
	}
}

int main()
{
//	freopen("in_1620.txt","r",stdin);
	ca=0;
	while (cin>>n&&n)
	{
		memset(arc,false,sizeof(arc));
		for (int i=0;i<n;++i)
		{
			cin>>x[i]>>y[i];
			for (int j=0;j<i;++j)
			{
				if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=400)
				{
					arc[i][j]=arc[j][i]=true;
				}
			}
		}
		best=n;
		DFS(0,1);
		printf("The towers in case %d can be covered in %d frequencies.\n",++ca,best);
	}
	return 0;
}
