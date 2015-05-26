/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Crypto Columns
*       ID             : 1617
*       Date           : 1/5/2009
*       Time           : 12:58:58
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAXN 10

struct Key
{
	char c;
	int index;
};

string s1,s2;
Key key[MAXN];
int m,n;
int hash[MAXN];

inline bool cmp(Key a,Key b)
{
	if (a.c==b.c)
	{
		return a.index<b.index;
	}
	else
	{
		return a.c<b.c;
	}
}

int main()
{
//	freopen("in_1617.txt","r",stdin);
	while (1)
	{
		cin>>s1;
		if (s1=="THEEND")
		{
			break;
		}
		cin>>s2;
		n=s1.length();
		m=s2.length()/n;
		for (int i=0;i<n;++i)
		{
			key[i].c=s1[i];
			key[i].index=i;
		}
		sort(key,key+n,cmp);
		for (int i=0;i<n;++i)
		{
			hash[key[i].index]=i;
		}
		for (int i=0;i<m;++i)
		{
			for (int j=0;j<n;++j)
			{
				cout<<s2[hash[j]*m+i];
			}
		}
		cout<<endl;
	}
	return 0;
}
