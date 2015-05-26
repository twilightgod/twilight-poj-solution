/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Yeehaa!
*       ID             : 1799
*       Date           : 5/20/2009
*       Time           : 21:36:1
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

double alp,R,r;
int n,ca,t;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1799.txt","r",stdin);
#endif
	cin>>t;
	ca=0;
	while(t--)
	{
		cin>>R>>n;
		alp=2*acos((double)0)/n;
		r=R*sin(alp)/(1+sin(alp));
		printf("Scenario #%d:\n%.3lf\n\n",++ca,r);
	}
	return 0;
}
