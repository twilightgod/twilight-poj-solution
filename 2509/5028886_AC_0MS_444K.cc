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
int l,n,k,l2;

int main()
{
	//freopen("in_2509.txt","r",stdin);
	while(cin>>n>>k)
	{
		sum=l=0;
		while(1)
		{
			l2=n+l;
			sum+=n;
			n=0;
			if(l2<k)
			{
				break;
			}
			n=l2/k;
			l=l2%k;
		}
		cout<<sum<<endl;
	}
	return 0;
}
