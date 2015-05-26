/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Ball bearings
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2959
*       ID             : 2959
*       Date           : 9/9/2009
*       Time           : 17:41:24
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

int t;
double D,d,s,theta;
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2959.txt","r",stdin);
#endif
	cin>>t;
	while(t--)
	{
		cin>>D>>d>>s;
		theta=2*(asin((d+s)/(D-d)));
		n=int(4*acos(double(0))/theta);
		cout<<n<<endl;
	}
	return 0;
}
