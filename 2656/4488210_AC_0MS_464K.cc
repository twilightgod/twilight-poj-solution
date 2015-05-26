/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Unhappy Jinjin
*       ID             : 2656
*       Date           : 12/15/2008
*       Time           : 22:40:36
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int n,best,best_i;

int main()
{
	//freopen("in_2656.txt","r",stdin);
	while (cin>>n&&n)
	{
		best=0;
		for (int i=0;i<n;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if (a+b>8)
			{
				if (a+b>best)
				{
					best=a+b;
					best_i=i+1;
				}
			}
		}
		if (best)
		{
			cout<<best_i<<endl;
		}
		else
		{
			cout<<"0\n";
		}
	}
	return 0;
}
