/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Gold Coins
*       ID             : 2000
*       Date           : 12/6/2008
*       Time           : 22:2:33
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 200001

int sum[MAXN];
int p[MAXN];
int n;

int main()
{
	//freopen("in_2000.txt","r",stdin);
	int day=0;
	int pay=0;
	sum[0]=0;
	while (day<=10000)
	{
		pay++;
		for (int i=1;i<=pay;++i)
		{
			day++;
			sum[day]=sum[day-1]+pay;
		}
	}
	while (cin>>n&&n)
	{
		cout<<n<<' '<<sum[n]<<endl;
	}
	return 0;
}
