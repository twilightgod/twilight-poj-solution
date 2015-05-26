/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Just the Facts
*       ID             : 1604
*       Date           : 4/23/2009
*       Time           : 13:15:8
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

#define MAXN 100001

int ans[MAXN];
int n,temp;

int main()
{
	//freopen("in_1604.txt","r",stdin);
	temp=1;
	for(int i=1;i<MAXN;++i)
	{
		temp*=i;
		while(temp%10==0)
		{
			temp/=10;
		}
		temp%=100000;
		ans[i]=temp%10;
	}
	while(cin>>n)
	{
		cout<<setw(5)<<n<<" -> "<<ans[n]<<endl;
	}
	return 0;
}
