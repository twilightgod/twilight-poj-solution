/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Parliament
*       ID             : 1032
*       Date           : 1/7/2009
*       Time           : 22:27:43
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int n,l,k;

int main()
{
//	freopen("in_1032.txt","r",stdin);
	while (cin>>n)
	{
		l=n;
		k=2;
		while (1)
		{
			if (l-k<0)
			{
				break;
			}
			l-=k;
			k++;
		}
		k--;
		for (int i=2;i<k;++i)
		{
			cout<<i+(i>k-l?1:0)<<' ';
		}
		if (k==l)
		{
			cout<<k+2<<endl;
		}
		else
		{
			cout<<k+(l!=0?1:0)<<endl;
		}
	}
	return 0;
}
