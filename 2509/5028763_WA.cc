/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Peter's smokes
*       ID             : 2509
*       Date           : 4/22/2009
*       Time           : 21:47:52
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int sum;
int l,n,k;

int main()
{
	//freopen("in_2509.txt","r",stdin);
	while(cin>>n>>k)
	{
		sum=0;
		l=k+1;
		while(1)
		{
			sum+=n;
			int t=n/k;
			l=t+n%k;
			n=t;
			if(n==0)
			{
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
