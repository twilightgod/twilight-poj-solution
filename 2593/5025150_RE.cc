/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Maximum sum
*       ID             : 2479
*       Date           : 12/10/2008
*       Time           : 17:1:35
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 50000
#define Inf 0x7fffffff

int a[MAXN];
int n,test;
int opt1[MAXN],opt2[MAXN];

int GetMax()
{
	int cp=0;
	for(int i=0;i<n;++i)
	{
		if(a[i]>0)
		{
			cp++;
		}
	}
	if(cp<2)
	{
		int max1=-Inf,max2=-Inf,max1_i,max2_i;
		for(int i=0;i<n;++i)
		{
			if(a[i]>max1)
			{
				max1=a[i];
				max1_i=i;
			}
		}
		for(int i=0;i<n;++i)
		{
			if(i!=max1_i&&a[i]>max2)
			{
				max2=a[i];
				max2_i=i;
			}
		}
		return max1+max2;
	}
	int f=0,best=0;
	for (int i=0;i<n;++i)
	{
		if (f+a[i]<0)
		{
			f=0;
		}
		else
		{
			if (f+a[i]>best)
			{
				best=f+a[i];
			}
			f+=a[i];
		}
		opt1[i]=best;
	}

	best=0;f=0;
	for (int i=n-1;i>=0;--i)
	{
		if (f+a[i]<0)
		{
			f=0;
		}
		else
		{
			if (f+a[i]>best)
			{
				best=f+a[i];
			}
			f+=a[i];
		}
		opt2[i]=best;
	}

	best=-Inf;
	for(int i=0;i<n-1;++i)
	{
		if(best<opt1[i]+opt2[i+1])
		{
			best=opt1[i]+opt2[i+1];
		}
	}
	return best;
}

int main()
{
	//freopen("in_2479.txt","r",stdin);
	//scanf("%d",&test);
	while (scanf("%d",&n)&&n)
	{
		
		for (int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		printf("%d\n",GetMax());
	}
	return 0;
}
