/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Binary Search
*       ID             : 1757_2
*       Date           : 12/7/2008
*       Time           : 8:54:36
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<fstream>
using namespace std;

#define MAXN 10000

int A[MAXN],low[MAXN],high[MAXN];
int N,i,j,l,k,total,test;

bool BinarySearch(int x,int _i,int _l)
{
	int p, q, i, L;

	p = 0;   /* Left border of the search  */
	q = N-1; /* Right border of the search */
	L = 0;   /* Comparison counter         */
	while (p <= q) {
		i = (p + q) / 2;
		++L;
		if (A[i] == x) {
			if(i==_i&&L==_l)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (x < A[i])
			q = i - 1;
		else
			p = i + 1;
	}
	return false;
}

int main()
{
	//freopen("in_1757_2.txt","r",stdin);
	for(i=0;i<MAXN;++i)
	{
		A[i]=i;
	}

	
	while(scanf("%d%d",&i,&l)!=-1)
	{
		memset(low,-1,sizeof(low));
		memset(high,-1,sizeof(high));
		total=0;
		for(N=1;N<=MAXN;++N)
		{
			if(BinarySearch(i,i,l))
			{
				if(low[total]==-1)
				{
					low[total]=N;
				}
				else
				{
					high[total]=N;
				}
			}
			else
			{
				if(low[total]!=-1)
				{
					if(high[total]==-1)
					{
						high[total]=N-1;
					}
					total++;
				}
			}
		}
		if(low[total]!=-1)
		{
			high[total]=MAXN;
			total++;
		}
		cout<<total<<endl;
		for(i=0;i<total;++i)
		{
			printf("%d %d\n",low[i],high[i]);
			//cout<<low[i]<<' '<<high[i]<<endl;
		}
		if(test!=0)
		{
			printf("\n");
			//           cout<<endl;
		}
	}
	return 0;
}
