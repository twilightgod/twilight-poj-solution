/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Symmetric Order
*       ID             : 2013
*       Date           : 12/6/2008
*       Time           : 23:4:40
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

#define MAXN 15

string name[MAXN],sorted[MAXN];
int n,t;

int main()
{
	//freopen("in_2013.txt","r",stdin);
	t=0;
	while (cin>>n&&n)
	{
		getchar();
		for (int i=0;i<n;++i)
		{
			getline(cin,name[i]);
		}
		cout<<"SET "<<++t<<endl;
		int h=0;t=n-1;
		for (int i=0;i<n;++i)
		{
			if (i%2)
			{
				sorted[t--]=name[i];
			}
			else
			{
				sorted[h++]=name[i];
			}
		}
		for (int i=0;i<n;++i)
		{
			cout<<sorted[i]<<endl;
		}
	}
	return 0;
}
