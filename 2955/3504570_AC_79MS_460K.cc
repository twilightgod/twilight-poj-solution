#include<iostream>
#include<string>
using namespace std;
#define MAXN 101

string s;
int f[MAXN][MAXN];
int i,j,k,p,len;

inline int max1(int x,int y)
{
	return x>y?x:y;
}

inline bool fit(int a,int b)
{
	return s[a]=='('&&s[b]==')'||s[a]=='['&&s[b]==']';
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	//freopen("d:/out.txt","w",stdout);
	while(cin>>s&&s!="end")
	{
		len=s.length();
		memset(f,0,sizeof(f));
		for(p=1;p<=len-1;++p)
		{
			for(i=0;i<=len-p-1;++i)
			{
				j=i+p;
				for(k=i;k<=j-1;++k)
				{
					f[i][j]=max1(f[i][j],f[i][k]+f[k+1][j]);
				}
				if(fit(i,j))
				{
					f[i][j]=max1(f[i][j],f[i+1][j-1]+2);
				}
			}
		}
		cout<<f[0][len-1]<<endl;
	}
	return 0;
}
