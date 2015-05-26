/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Self Numbers
*       ID             : 1316
*       Date           : 12/5/2008
*       Time           : 22:47:2
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

#define MAXN 10000

bool sn[MAXN+1];

int main()
{
	//freopen("in_1316.txt","r",stdin);
	memset(sn,true,sizeof(sn));
	for (int i=1;i<=MAXN;++i)
	{
		int sum=i;
		stringstream ss;
		ss.clear();
		ss<<sum;
		string s;
		ss>>s;
		for (int j=0;j<s.length();++j)
		{
			sum+=s[j]-'0';
		}
		if (sum<=MAXN)
		{
			sn[sum]=false;
		}
		if (sn[i])
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
