#include<iostream>
using namespace std;

#define MAXN 102

bool op[MAXN];
int v[MAXN],f[MAXN][MAXN][2];
int n,ans,ansi,v1,v2;
char ch;

inline int max1(int a,int b)
{
	return a>b?a:b;
}

inline int min1(int a,int b)
{
	return a<b?a:b;
}

inline void swap1(int &a,int &b)
{
	a^=b;
	b^=a;
	a^=b;
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			cin>>ch;
			op[i]=ch=='t'?false:true;
			op[n+i]=op[i];
			cin>>v[i];
			v[n+i]=v[i];
		}
		for(int i=0;i<n*2;++i)
		{
			f[i][i][0]=f[i][i][1]=v[i];
		}
		for(int p=2;p<=n;++p)
		{
			for(int i=0;i<n;++i)
			{
				int j=i+p-1;
				for(int k=i+1;k<=j;++k)
				{
					int &a=f[i][k-1][0],&b=f[i][k-1][1],
						&c=f[k][j][0],&d=f[k][j][1];
					//add
					if(!op[k])
					{
						f[i][j][0]=a+c;
						f[i][j][1]=b+d;
					}
					//mul
					else
					{
						f[i][j][0]=min1(min1(b*c,b*d),min1(a*c,a*d));
						f[i][j][1]=max1(max1(b*c,b*d),max1(a*c,a*d));
					}
				}
			}
		}
		ans=f[0][n-1][1];
		ansi=0;
		for(int i=1;i<n;++i)
		{
			ansi=f[i][i+n-1][1]>ans?i:ansi;
			ans=max1(ans,f[i][i+n-1][1]);
		}
		cout<<ans<<endl;
		v1=ansi%n;
		v2=ansi%n+1;
		if(v1>v2)
		{
			swap1(v1,v2);
		}
		cout<<v1<<' '<<v2<<endl;
	}
	return 0;
}
