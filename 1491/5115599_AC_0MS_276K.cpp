/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Pi
*       ID             : 1491
*       Date           : 5/8/2009
*       Time           : 12:17:44
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 50

int a[MAXN];
int ans,n;

int gcd(int a,int b)
{
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main()
{
	//freopen("in_1491.txt","r",stdin);
	while(cin>>n&&n)
	{
		ans=0;
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				if(gcd(a[i],a[j])==1)
				{
					ans++;
				}
			}
		}
		if(ans)
		{
			printf("%.6lf\n",sqrt(double(6)*n*(n-1)/ans/2));
		}
		else
		{
			cout<<"No estimate for this data set.\n";
		}
	}
	return 0;
}
