/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : How much did the businessman lose
*       ID             : 2521
*       Date           : 4/22/2009
*       Time           : 21:44:25
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int n,m,p,c;

int main()
{
	//freopen("in_2521.txt","r",stdin);
	while(cin>>n>>m>>p>>c&&m)
	{
		cout<<p+n-m<<endl;
	}
	return 0;
}
