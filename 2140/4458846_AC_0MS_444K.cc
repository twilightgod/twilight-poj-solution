/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Herd Sums
*       ID             : 2140
*       Date           : 12/6/2008
*       Time           : 11:32:10
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

int n;

int main()
{
	//freopen("in_2140.txt","r",stdin);
	while (cin>>n)
	{
		int sum=0;
		for (int k=1;k<=int(sqrt(double(2*n)));++k)
		{
			if ((2*n)%k==0)
			{
				int t=2*n/k-k+1;
				double dt=t;
				if (double(t/2)==dt/2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
