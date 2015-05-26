/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Game of Lines
*       ID             : 3668
*       Date           : 5/17/2009
*       Time           : 22:6:18
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<set>
using namespace std;

#define inf 5000
#define MAXN 200

struct _P
{
	int x,y;
};

_P p[MAXN];
int n;
set<double> s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3668.txt","r",stdin);
#endif
	cin>>n;
	s.clear();
	for(int i=0;i<n;++i)
	{
		cin>>p[i].x>>p[i].y;
	}
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(p[i].x-p[j].x==0)
			{
				s.insert(inf);
			}
			else
			{
				s.insert((double)(p[i].y-p[j].y)/(p[i].x-p[j].x));
			}
		}
	}
	cout<<s.size()<<endl;
	return 0;
}
