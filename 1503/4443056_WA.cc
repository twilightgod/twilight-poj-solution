/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Integer Inquiry
*       ID             : 1503
*       Date           : 12/1/2008
*       Time           : 13:6:37
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

#define MAXN 20000

struct BigInt
{
	int len;
	int b[MAXN];
	BigInt operator = (const BigInt &a)
	{
		len=a.len;
		for(int i=0;i<a.len;++i)
		{
			b[i]=a.b[i];
		}
		return *this;
	}
};

istream& operator >> (istream &ins,BigInt &a)
{
	string s;
	getline(ins,s);
	int i;
	for(i=0;i<s.length();++i)
	{
		if (s[i]!='0')
		{
			break;
		}
	}
	a.len=s.length()-i;
	for(int j=s.length()-1,k=0;j>=i;--j,++k)
	{
		a.b[k]=s[j]-'0';
	}
	return ins;
}

ostream& operator << (ostream &outs,const BigInt &a)
{
	for (int i=a.len-1;i>=0;--i)
	{
		outs<<a.b[i];
	}
	return outs;
}

BigInt operator + (const BigInt &a,const BigInt &b)
{
	BigInt c;
	int l=a.len>b.len?a.len:b.len;
	c.len=l+1;
	c.b[c.len-1]=0;
	for(int i=0;i<l;++i)
	{
		c.b[i]=a.b[i]+b.b[i];
	}
	for(int i=0;i<l;++i)
	{
		if (c.b[i]>9)
		{
			c.b[i]-=10;
			c.b[i+1]++;
		}
	}
	if (c.b[c.len-1]==0)
	{
		c.len--;
	}
	return c;
}



bool InputEnd(const BigInt &a)
{
	if(a.len==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	//freopen("in_1503.txt","r",stdin);
	BigInt sum;
	BigInt t;
	cin>>sum;
	while(cin>>t&&!InputEnd(t))
	{
		sum=sum+t;
	}
	cout<<sum<<endl;
	return 0;
}
