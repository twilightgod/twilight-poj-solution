/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Glass Beads
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1509
*       ID             : 1509
*       Date           : 5/26/2009
*       Time           : 13:5:26
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
using namespace std;

#define MAXN 20001

int t,n;
char s[MAXN];

int solve()
{
	int	i=0;
	int j=1;
	while(1)
	{
		int k=0;
		while(s[i+k]==s[j+k])
		{
			if(++k==n)
			{
				return i<j?i:j;
			}
		}
		if(s[i+k]>s[j+k])
		{
			if((i+=k+1)==j)
			{
				i++;
			}
		}
		else
		{
			if((j+=k+1)==i)
			{
				j++;
			}
		}
		if(i>=n)
		{
			return j;
		}
		if(j>=n)
		{
			return i;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1509.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&s);
		n=strlen(s);
		for(int i=0;i<n-1;++i)
		{
			s[i+n]=s[i];
		}
		printf("%d\n",solve()+1);
	}
	return 0;
}
