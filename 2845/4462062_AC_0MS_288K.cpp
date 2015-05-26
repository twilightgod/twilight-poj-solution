/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : 01000001
*       ID             : 2845
*       Date           : 12/7/2008
*       Time           : 11:2:10
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

#define MAXN 81

struct BN
{
	int len;
	int b[MAXN];
};

int t,ca;
BN a,b,c;
string s1,s2;

void Trans(string s,BN& a)
{
	a.len=s.length();
	for (int i=0,j=s.length()-1;i<a.len;++i,--j)
	{
		a.b[i]=s[j]-48;
	}
}

void Clear(BN& a)
{
	for (int i=0;i<MAXN;++i)
	{
		a.b[i]=0;
	}
}

void Add(BN&a,BN&b,BN&c)
{
	int l=a.len>b.len?a.len:b.len;
	c.len=l+1;
	for (int i=0;i<l;++i)
	{
		c.b[i]=a.b[i]+b.b[i];
	}
	for (int i=0;i<l;++i)
	{
		if (c.b[i]>1)
		{
			c.b[i]-=2;
			c.b[i+1]++;
		}
	}
	int i;
	for (i=c.len-1;i>=0;--i)
	{
		if (c.b[i])
		{
			c.len=i+1;
			break;
		}
	}
	if (i==-1)
	{
		c.len=1;
	}
}

void Output(BN&a)
{
	cout<<++ca<<' ';
	for (int i=a.len-1;i>=0;--i)
	{
		cout<<a.b[i];
	}
	cout<<endl;
}

int main()
{
	//freopen("in_2845.txt","r",stdin);
	cin>>t;
	ca=0;
	while (t--)
	{
		cin>>s1>>s2;
		Clear(a);
		Clear(b);
		Clear(c);
		Trans(s1,a);
		Trans(s2,b);
		Add(a,b,c);
		Output(c);
	}
	return 0;
}
