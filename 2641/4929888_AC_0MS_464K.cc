#include<iostream>
#include<math.h>
using namespace std;

double a,b,s,m,n,alpha,v;

int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>a>>b>>s>>m>>n)
	{
		if(a==0)
		{
			break;
		}
		alpha=atan(n*b/m/a);
		v=m*a/cos(alpha)/s;
		printf("%.2lf %.2lf\n",alpha*180/acos((double)0)/2,v);
	}
	return 0;
}

