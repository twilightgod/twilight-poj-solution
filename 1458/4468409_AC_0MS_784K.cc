/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Common Subsequence
*       ID             : 1458
*       Date           : 12/8/2008
*       Time           : 22:28:5
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

#define MAXN 300

string s1,s2;
int l1,l2;
int f[MAXN][MAXN];

int main()
{
	//freopen("in_1458.txt","r",stdin);
	memset(f,0,sizeof(f));
	while (cin>>s1>>s2)
	{
		l1=s1.length();
		l2=s2.length();
		for (int i=1;i<=l1;++i)
		{
			for (int j=1;j<=l2;++j)
			{
				if (s1[i-1]==s2[j-1])
				{
					f[i][j]=f[i-1][j-1]+1;
				}
				else
				{
					f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];
				}
			}
		}
		cout<<f[l1][l2]<<endl;
	}
	return 0;
}
