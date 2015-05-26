/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Special Experiment
*       ID             : 1770
*       Date           : 5/11/2009
*       Time           : 19:1:51
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<set>
#include<math.h>
using namespace std;

#define MAXN 200

int el[MAXN];
set<int> pho;
int f[MAXN][2];
int n,m;
bool mat[MAXN][MAXN];

inline int max1(int a,int b)
{
	return a>b?a:b;
}

int opt(int i,int j,int root)
{
	if(f[i][j]!=-1)
	{
		return f[i][j];
	}
	if(j)
	{
		f[i][1]=el[i];
		for(int k=0;k<n;++k)
		{
			if(mat[i][k]&&k!=root)
			{
				f[i][1]+=opt(k,0,i);
			}
		}
	}
	else
	{
		f[i][0]=0;
		for(int k=0;k<n;++k)
		{
			if(mat[i][k]&&k!=root)
			{
				f[i][0]+=max1(opt(k,0,i),opt(k,1,i));
			}
		}	
	}
	return f[i][j];
}

int main()
{
//	freopen("in_1770.txt","r",stdin);
	while(cin>>n>>m&&n)
	{
		for(int i=0;i<n;++i)
		{
			cin>>el[i];
		}
		pho.clear();
		for(int i=0;i<m;++i)
		{
			int p;
			cin>>p;
			pho.insert(p);	
		}
		memset(mat,false,sizeof(mat));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(pho.find(abs(el[i]-el[j]))!=pho.end())
				{
					mat[i][j]=true;
				}
			}
		}
		memset(f,-1,sizeof(f));
		cout<<max1(opt(0,0,0),opt(0,1,0))<<endl;
	}
	return 0;
}
