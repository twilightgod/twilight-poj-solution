#include<iostream>
using namespace std;

#define MAXM 505

int f[2][MAXM][2];

int n,m,d;
bool c;

inline int max1(int a,int b)
{
	if(a==-1&&b==-1)
	{
		return -1;
	}
	if(a==-1)
	{
		return b;
	}
	if(b==-1)
	{
		return a;
	}
	return a>b?a:b;
}

int main()
{
	//freopen("C.txt","r",stdin);
	scanf("%d%d",&n,&m);
	c=false;
	memset(f,-1,sizeof(f));
	f[!c][0][0]=0;
	//f[!c][0][1]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&d);
		for(int j=0;j<=m;++j)
		{
			//k==0
			if(j!=m)
			{
				f[c][j][0]=max1(f[!c][j+1][1],f[!c][j+1][0]);
				if(j==0)
				{
					f[c][j][0]=max1(f[c][j][0],f[!c][0][0]);
				}
			}
			
			//k==1
			if(j!=0)
			{
				f[c][j][1]=max1(f[!c][j-1][1],f[!c][0][0]);
				if(f[c][j][1]!=-1)
				{
					f[c][j][1]+=d;
				}
			}
		}
		c=!c;
	}
	printf("%d\n",f[!c][0][0]);
	return 0;
}

