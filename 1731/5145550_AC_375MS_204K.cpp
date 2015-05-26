/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Orders
*       ID             : 1731
*       Date           : 5/13/2009
*       Time           : 13:18:56
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char s[205];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1731.txt","r",stdin);
#endif
	scanf("%s",&s);
	n=strlen(s);
	sort(s,s+n);
	for(int i=0;i<n;++i)
	{
		printf("%c",s[i]);
	}
	printf("\n");
	while(next_permutation(s,s+n))
	{
		for(int i=0;i<n;++i)
		{
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
