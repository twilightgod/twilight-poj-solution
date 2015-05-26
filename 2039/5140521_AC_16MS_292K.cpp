/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : To and Fro
*       ID             : 2039
*       Date           : 5/12/2009
*       Time           : 17:27:28
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

#define MAXN 200

char w[MAXN][MAXN];
int n,m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2039.txt","r",stdin);
#endif
	while(cin>>n&&n)
	{
		string s;
		cin>>s;
		m=s.length()/n;
		stringstream ss;
		ss.clear();
		ss<<s;
		for(int i=0;i<m;++i)
		{
			if(i%2==0)
			{
				for(int j=0;j<n;++j)
				{
					ss>>w[i][j];
				}
			}
			else
			{
				for(int j=n-1;j>=0;--j)
				{
					ss>>w[i][j];
				}
			}
		}


		for(int j=0;j<n;++j)
		{
			for(int i=0;i<m;++i)
			{
				cout<<w[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}
