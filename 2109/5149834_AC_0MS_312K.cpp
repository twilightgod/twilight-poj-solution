/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Power of Cryptography
*       ID             : 2109
*       Date           : 5/13/2009
*       Time           : 22:17:55
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

double n,p;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2109.txt","r",stdin);
#endif
	while(cin>>n>>p)
	{
		cout<<pow(p,1/n)<<endl;
	}
	return 0;
}
