/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Trees
*       ID             : 2665
*       Date           : 4/25/2009
*       Time           : 21:13:46
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
using namespace std;

int l,s;

int main()
{
//	freopen("in_2665.txt","r",stdin);
	while(cin>>l>>s&&s)
	{
		for(int i=0;i<s;++i)
		{
			int a,b;
			cin>>a>>b;
			l-=b-a+1;
		}
		cout<<l+1<<endl;
	}
	return 0;
}
