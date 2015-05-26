/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Diplomatic License
*       ID             : 1939
*       Date           : 3/25/2009
*       Time           : 17:2:18
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 100000

long long x[MAXN],y[MAXN];
int n;

int main()
{
	//freopen("in_1939.txt","r",stdin);
	while(cin>>n)
	{
		cout<<n;
		for(int i=0;i<n;++i)
		{
			cin>>x[i]>>y[i];
		}
		x[n]=x[0];
		y[n]=y[0];
		for(int i=0;i<n;++i)
		{
			printf(" %.6lf %.6lf",double(x[i]+x[i+1])/2,double(y[i]+y[i+1])/2);
		}
		cout<<endl;
	}
	return 0;
}
