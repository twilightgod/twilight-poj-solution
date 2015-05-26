/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sumsets
*       ID             : 2229
*       Date           : 5/15/2009
*       Time           : 16:30:53
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

#define MAXN 1000001
#define M 1000000000

int n;
bool ex;
int f[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2229.txt","r",stdin);
#endif
	while(cin>>n)
	{
		f[1]=1;
		f[2]=2;
		ex=false;
		for(int i=3;i<=n;++i)
		{
			if(i&1)
			{
				f[i]=f[i-1];
			}
			else
			{
				f[i]=f[i-2]+f[i>>1];
				if(f[i]>M)
				{
					ex=true;
					f[i]-=M;
				}
			}
		}
		if(!ex)
		{
			cout<<f[n]<<endl;
		}
		else
		{
			stringstream ss;
			ss.clear();
			ss<<f[n];
			string str;
			ss>>str;
			if(str.length()<9)
			{
				for(int i=0;i<9-str.length();++i)
				{
					cout<<'0';
				}
			}
			cout<<str<<endl;
		}
	}
	return 0;
}
