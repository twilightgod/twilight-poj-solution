/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : UmBasketella
*       ID             : 3737
*       Date           : 5/20/2009
*       Time           : 20:50:52
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

double s,r,h,v,sdp;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3737.txt","r",stdin);
#endif
	while(cin>>s)
	{
		sdp=sqrt((double)s/acos((double)0)/2);
		h=sqrt((double)2)*sdp;
		r=sdp/2;
		v=acos((double)0)*2*r*r*h/3;
		printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
	}
	return 0;
}
