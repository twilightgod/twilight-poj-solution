#include<iostream>
using namespace std;
#define MAXN 101
#define MININT -5000

int w[MAXN][MAXN];
int opt[MAXN][MAXN];
int i,j,k,f,v,ans;

inline int max1(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	memset(opt,0,sizeof(opt));
	while(cin>>f>>v)
	{
		for(i=1;i<=f;++i)
		{
			for(j=1;j<=v;++j)
			{
				cin>>w[i][j];
			}
		}
		for(i=1;i<=f;++i)
		{
			for(j=i;j<=v-f+i;++j)
			{
				opt[i][j]=MININT;
				for(k=i-1;k<=j-1;++k)
				{
					opt[i][j]=max1(opt[i][j],opt[i-1][k]);
				}
				opt[i][j]+=w[i][j];
			}
		}
		ans=MININT;
		for(j=f;j<=v;++j)
		{
			ans=max1(ans,opt[f][j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}