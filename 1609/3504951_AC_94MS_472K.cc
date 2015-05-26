#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10001

struct bl
{
	int l,m;
};

bl b[MAXN];
int f[MAXN];
int n,i,j,best;

bool cmp(bl x,bl y)
{
	if(x.l==y.l)
	{
		return x.m<y.m;
	}
	else
	{
		return x.l<y.l;
	}
}

inline int max1(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n&&n)
	{
		for(i=0;i<n;++i)
		{
			cin>>b[i].l>>b[i].m;
		}
		sort(b,b+n,cmp);
		f[0]=1;
		best=1;
		for(i=1;i<n;++i)
		{
			f[i]=1;
			for(j=0;j<=i-1;++j)
			{
				if(b[j].l<=b[i].l&&b[j].m<=b[i].m)
				{
					f[i]=max1(f[i],f[j]+1);
				}
			}
			best=max1(best,f[i]);
		}
		cout<<best<<endl;
	}
	cout<<"*\n";
	return 0;
}
