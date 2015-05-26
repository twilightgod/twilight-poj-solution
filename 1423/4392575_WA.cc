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
double pi,e;

int main()
{
	//freopen("in_1423.txt","r",stdin);
	pi=acos((double)-1);
	e=exp((double)1);
	cin>>test;
	while(test--)
	{
		cin>>n;
		cout<<(int)floor((double)log10(sqrt(2*pi*n))+n*log10(n/e))+1<<endl;
	}
	return 0;
}
