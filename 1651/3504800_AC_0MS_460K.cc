#include<iostream>
using namespace std;
#define MAXN 100
#define MAXINT 2147483647

int i,j,n,p,k;
int a[MAXN];
int f[MAXN][MAXN];

inline int min1(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	for(i=0;i<MAXN-1;++i)
	{
		f[i][i+1]=0;
	}
	while(cin>>n)
	{
		for(i=0;i<n;++i)
		{
			cin>>a[i];
		}
		for(p=2;p<=n-1;++p)
		{
			for(i=0;i<=n-p-1;++i)
			{
				j=i+p;
				f[i][j]=MAXINT;
				for(k=i+1;k<=j-1;++k)
				{
					f[i][j]=min1(f[i][j],f[i][k]+f[k][j]+a[k]*a[i]*a[j]);
				}
			}
		}
		cout<<f[0][n-1]<<endl;
	}
	return 0;
}
