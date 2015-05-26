/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Palindrome
*       ID             : 1159
*       Date           : 11/20/2008
*       Time           : 22:9:28
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 5001

char s[MAXN];
short f[MAXN][MAXN];
int i,j,n,p;

inline int min1(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	//freopen("in_1159.txt","r",stdin);
	while(cin>>n)
	{
		for(getchar(),i=0;i<n;++i)
		{
			cin>>s[i];
		}
		memset(f,sizeof(f),0);
		for(i=0;i<n;++i)
		{
			f[i][i]=0;
		}
		for(p=2;p<=n;++p)
		{
			for(i=0;i<n-p+1;++i)
			{
				j=p+i-1;
				if(s[i]==s[j])
				{
					f[i][j]=f[i+1][j-1];
				}
				else
				{
					f[i][j]=min1(f[i][j-1],f[i+1][j])+1;
				}
			}
		}
		cout<<f[0][n-1]<<endl;
	}
	return 0;
}
