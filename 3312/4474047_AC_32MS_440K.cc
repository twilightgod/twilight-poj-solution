/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Mahershalalhashbaz, Nebuchadnezzar, and Billy Bob
Benjamin Go to the Regionals
*       ID             : 3312
*       Date           : 12/10/2008
*       Time           : 21:35:3
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

#define MAXN 1000

int l[MAXN];
int n,k,ca;
bool god;
string s;

int main()
{
	//freopen("in_3312.txt","r",stdin);
	ca=0;
	while(cin>>n>>k)
	{
		if (n==0&&k==0)
		{
			break;
		}
		for (int i=0;i<n;++i)
		{
			cin>>s;
			l[i]=s.length();
		}
		sort(l,l+n);
		int m=n/k;
		god=false;
		for (int i=0;i<m;++i)
		{
			int sum=0;
			for (int j=0;j<k;++j)
			{
				sum+=l[i*k+j];
			}
			for (int j=0;j<k;++j)
			{
				if (abs(k*l[i*k+j]-sum)>2*k)
				{
					god=true;
					goto outp;
				}
			}
		}
outp:	printf("Case %d: %s\n\n",++ca,god?"no":"yes");
	}
	return 0;
}
