#include<iostream>
using namespace std;

#define MAXN 50
#define MAXINT 50000
#define MININT -50000

bool op[MAXN];
int f[MAXN][MAXN][2];
int n,ans;
char ch;

inline int max1(int a,int b)
{
	return a>b?a:b;
}

inline int min1(int a,int b)
{
	return a<b?a:b;
}

void pr(int t)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout<<f[i][j][t]<<' ';
		}
		cout<<endl;
	}
}

int main()
{
	//freopen("e:/in.txt","r",stdin);
	while(cin>>n)
	{
		//input
		for(int i=0;i<n;++i)
		{
			cin>>ch;
			op[i]=ch=='t'?true:false;
			cin>>f[i][i][0];
			f[i][i][1]=f[i][i][0];
		}
		//dp
		for(int p=2;p<=n;++p)
		{
			for(int i=0;i<n;++i)
			{
				int j=i+p-1;
				f[i][j%n][0]=MAXINT;
				f[i][j%n][1]=MININT;
				for(int k=i+1;k<=j;++k)
				{
					int	a=f[i][(k-1)%n][0],b=f[i][(k-1)%n][1],
						c=f[k%n][j%n][0],d=f[k%n][j%n][1];
					
					//add
					if(op[k%n])
					{
						f[i][j%n][0]=min1(f[i][j%n][0],a+c);
						f[i][j%n][1]=max1(f[i][j%n][1],b+d);
					}
					//mul
					else
					{
						f[i][j%n][0]=min1(f[i][j%n][0],min1(min1(a*c,a*d),min1(b*c,b*d)));
						f[i][j%n][1]=max1(f[i][j%n][1],max1(max1(a*c,a*d),max1(b*c,b*d)));
					}
				}
			}
		}
		//output
		ans=f[0][n-1][1];
		for(int i=1;i<n;++i)
		{
			ans=max1(ans,f[i][(i+n-1)%n][1]);
		}
		cout<<ans<<endl;
		//pr(0);
		//pr(1);
		bool first=true;
		for(int i=0;i<n;++i)
		{
			if(f[i][(i+n-1)%n][1]==ans)
			{
				if(first)
				{
					first=false;
				}
				else
				{
					cout<<' ';
				}
				cout<<i+1;	
			}
		}
		cout<<endl;
	}
	return 0;
}
