/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Coins
*       ID             : 3210
*       Date           : 12/6/2008
*       Time           : 22:41:18
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int main()
{
	//freopen("in_3210.txt","r",stdin);
	int n;
	while (cin>>n&&n)
	{
		if (n%2)
		{
			cout<<n-1<<endl;
		}
		else
		{
			cout<<"No Solution!\n";
		}
	}
	return 0;
}
