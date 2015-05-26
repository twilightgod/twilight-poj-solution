/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Communication System
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1018
*       ID             : 1018
*       Date           : 9/8/2009
*       Time           : 13:27:45
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
//#include<functional>
using namespace std;

#define MAXN 101

struct DEVICE
{
	int b,p;
};

bool cmp(DEVICE x,DEVICE y)
{
	return x.b<y.b;
}

vector<DEVICE> d[MAXN];
int t,n;
double best;
set<int> band;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1018.txt","r",stdin);
#endif
	cin>>t;
	while(t--)
	{
		cin>>n;
		band.clear();
		for(int i=0;i<n;++i)
		{
			d[i].clear();
			int m;
			cin>>m;
			while(m--)
			{
				DEVICE td;
				cin>>td.b>>td.p;
				d[i].push_back(td);
				band.insert(td.b);
			}
			sort(d[i].begin(),d[i].end(),cmp);
		}
		best=0;
		for(set<int>::iterator sit=band.begin();sit!=band.end();++sit)
		{
			int tot=0;
			for(int i=0;i<n;++i)
			{
				int mi=0x7fffffff;
				DEVICE ddd;
				ddd.b=*sit;
				vector<DEVICE>::iterator vit=lower_bound(d[i].begin(),d[i].end(),ddd,cmp);
				if(vit==d[i].end())
				{
					goto con;
				}
				for(;vit!=d[i].end();++vit)
				{
					if(mi>vit->p)
					{
						mi=vit->p;
					}
				}
				tot+=mi;
			}
			if(best<(*sit)/(double)tot)
			{
				best=(*sit)/(double)tot;
			}
		}
con:	;
		printf("%.3f\n",best);
	}
	return 0;
}
