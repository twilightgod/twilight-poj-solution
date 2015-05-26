/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sequence Sum Possibilities
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2853
*       ID             : 2853
*       Date           : 5/27/2009
*       Time           : 17:9:24
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

int n,ca,t;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2853.txt","r",stdin);
#endif
	cin>>t;
	while (t--)
	{
		cin>>ca>>n;
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
		cout<<ca<<' '<<sum-1<<endl;
	}
	return 0;
}
