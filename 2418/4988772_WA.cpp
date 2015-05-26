/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Hardwood Species
*       ID             : 2418
*       Date           : 4/16/2009
*       Time           : 13:15:10
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct Node
{
	string s;
	double rate;
};

string str;
char ch[31];
map<string,int> m;
map<string,int>::iterator it;
vector<Node> v;
int n;

bool cmp(Node a,Node b)
{
	if(fabs(a.rate-b.rate)<1e-6)
	{
		return a.s<b.s;
	}
	else
	{
		return a.rate>b.rate;
	}
}

int main()
{
	//freopen("in_2418.txt","r",stdin);
	n=0;
	while(1)
	{
		if(gets(ch)==NULL)
		{
			break;
		}
		str=ch;
		m[str]++;
		n++;
	}
	for(it=m.begin();it!=m.end();++it)
	{
		Node no;
		no.rate=(double)(*it).second/n;
		no.s=(*it).first;
		v.push_back(no);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<(int)v.size();++i)
	{
		printf("%s %.4lf\n",v[i].s.c_str(),v[i].rate*100);
	}
	return 0;
}
