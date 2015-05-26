/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Alignment of the Planets
*       ID             : 3174
*       Date           : 12/20/2008
*       Time           : 21:58:46
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<vector>
using namespace std;

#define MAXN 770

struct Line
{
	int a,b,c;
	Line(int _a,int _b,int _c):a(_a),b(_b),c(_c)
	{
	}
};

int x[MAXN],y[MAXN];
vector<Line> line;
int n,total;

int main()
{
	//freopen("in_3174.txt","r",stdin);
	while (scanf("%d",&n)!=-1)
	{
		for (int i=0;i<n;++i)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		total=0;
		line.clear();
		for (int i=0;i<n;++i)
		{
			for (int j=i+1;j<n;++j)
			{
				for (int k=j+1;k<n;++k)
				{
					if ((x[k]-x[i])*(y[j]-y[i])-(x[j]-x[i])*(y[k]-y[i])==0)
					{
						line.push_back(Line(i+1,j+1,k+1));
						total++;
					}
				}
			}
		}
		printf("%d\n",total);
		for (int i=0;i<total;++i)
		{
			printf("%d %d %d\n",line[i].a,line[i].b,line[i].c);
		}
	}
	return 0;
}
