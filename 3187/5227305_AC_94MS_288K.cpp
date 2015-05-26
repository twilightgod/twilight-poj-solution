/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Backward Digit Sums
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3187
*       ID             : 3187
*       Date           : 5/26/2009
*       Time           : 22:26:2
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 10

int a[MAXN][MAXN];
int n,k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3187.txt","r",stdin);
#endif
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		a[0][i]=i+1;
	}
	while(next_permutation(a[0],a[0]+n))
	{
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<n-i;++j)
			{
				a[i][j]=a[i-1][j]+a[i-1][j+1];	
			}
		}
		if(a[n-1][0]==k)
		{
			break;
		}
	}
	for(int i=0;i<n;++i)
	{
		if(i)
		{
			cout<<' ';
		}
		cout<<a[0][i];
	}
	cout<<endl;
	return 0;
}
