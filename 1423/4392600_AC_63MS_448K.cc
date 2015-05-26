/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Big Number
*       ID             : 1423
*       Date           : 11/18/2008
*       Time           : 21:39:50
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

int i,n,test;
double pi,e,sum;

int main()
{
	//freopen("in_1423.txt","r",stdin);
	pi=//acos((double)-1)
		3.14159265358979323846264338327950288419716939937510;
	e=//exp((double)1);
		2.7182818284590452354;
	cin>>test;
	while(test--)
	{
		cin>>n;
		if(n<1000000)
		{
			sum=0;
			for(i=1;i<=n;++i)
			{
				sum+=log10(double(i));
			}
			cout<<(int)sum+1<<endl;
		}
		else
		{
			cout<<(int)floor((double)log10(sqrt(2*pi*n))+n*log10(n/e))+1<<endl;
		}
	}
	return 0;
}
