#include<iostream>
using namespace std;
#define MAXN 101

int l1,l2,i,j,t;
char c;
int f[MAXN][MAXN];
int a[MAXN],b[MAXN];
int w[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};

inline int max1(int x,int y)
{
	return x>y?x:y;
}

inline int Encode(int x)
{
	switch(x)
	{
	case 'A':return 0;
	case 'C':return 1;
	case 'G':return 2;
	case 'T':return 3;
	}
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>l1;
		for(i=1;i<=l1;++i)
		{
			cin>>c;
			a[i]=Encode(c);
		}
		cin>>l2;
		for(i=1;i<=l2;++i)
		{
			cin>>c;
			b[i]=Encode(c);
		}
		f[0][0]=0;
		for(i=1;i<=l1;++i)
		{
			f[i][0]=f[i-1][0]+w[a[i]][4];
		}
		for(j=1;j<=l2;++j)
		{
			f[0][j]=f[0][j-1]+w[4][b[j]];
		}
		for(i=1;i<=l1;++i)
		{
			for(j=1;j<=l2;++j)
			{
				f[i][j]=max1(f[i-1][j]+w[a[i]][4],max1(f[i][j-1]+w[4][b[j]],f[i-1][j-1]+w[a[i]][b[j]]));
			}
		}
		cout<<f[l1][l2]<<endl;
	}
	return 0;
}
