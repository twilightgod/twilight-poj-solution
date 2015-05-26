#include<iostream>
using namespace std;
#define MAXN 40001

int n,i,t,m,l,r,len;
int a[MAXN],d[MAXN];

int main()
{
	//freopen("d:/in.txt","r",stdin);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		len=0;
		memset(d,0,sizeof(d));
		for (i=1;i<=n;++i)
		{
			if (a[i]>d[len])
			{
				len++;
				d[len]=a[i];
			}
			else
			{
				l=1;
				r=len;
				while (l<r-1)
				{
					m=(l+r)>>1;
					if (d[m]<a[i])
					{
						l=m;
					}
					else
					{
						r=m;
					}
				}
				if (d[l]>a[i])
				{
					d[l]=a[i];
				} 
				else
				{
					d[r]=a[i];
				}
			}
	
		}
		cout<<len<<endl;
	}
	return 0;
}