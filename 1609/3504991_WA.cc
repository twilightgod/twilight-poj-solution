#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10001

struct bl
{
	int l,m;
};

bl b[MAXN],rec[MAXN];
int f[MAXN];
int n,i,j,best,r,l,m;

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
		rec[0]=b[0];
		for(i=1;i<n;++i)
		{
			if(b[i].l>=rec[best-1].l&&b[i].m>=rec[best-1].m)
			{
				rec[best++]=b[i];
			}
			else
			{
				l=0;
				r=best-1;
				while(l<=r)
				{
					m=(l+r)>>1;
					if(b[i].l>=rec[m].l&&b[i].m>=rec[m].m)
					{
						l=m+1;
					}
					else
					{
						r=m-1;
					}
				}
				rec[r]=b[i];
			}
		}
		cout<<best<<endl;
	}
	cout<<"*\n";
	return 0;
}
