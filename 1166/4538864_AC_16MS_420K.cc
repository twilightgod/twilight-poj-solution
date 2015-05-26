/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Clocks
*       ID             : 1166_dfs
*       Date           : 1/7/2009
*       Time           : 2:38:15
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int ans[9];
int a[9];
int bestans[9];
int bestlen;
bool first;

void DFS(int dep,int len)
{
	if(dep==9)
	{
// 		1         ABDE
// 			2         ABC
// 			3         BCEF
// 			4         ADG
// 			5         BDEFH
// 			6         CFI
// 			7         DEGH
// 			8         GHI
// 			9         EFHI
		if (
			(a[0]+ans[0]+ans[1]+ans[3])%4==0&&
			(a[1]+ans[0]+ans[1]+ans[2]+ans[4])%4==0&&
			(a[2]+ans[1]+ans[2]+ans[5])%4==0&&
			(a[3]+ans[0]+ans[3]+ans[4]+ans[6])%4==0&&
			(a[4]+ans[0]+ans[2]+ans[4]+ans[6]+ans[8])%4==0&&
			(a[5]+ans[2]+ans[4]+ans[5]+ans[8])%4==0&&
			(a[6]+ans[3]+ans[6]+ans[7])%4==0&&
			(a[7]+ans[4]+ans[6]+ans[7]+ans[8])%4==0&&
			(a[8]+ans[5]+ans[7]+ans[8])%4==0&&
			len<bestlen
			)
		{
			for (int i=0;i<9;++i)
			{
				bestans[i]=ans[i];
			}
			bestlen=len;
		}
		return;
	}
	else
	{
		for (int i=0;i<=3;++i)
		{
			ans[dep]=i;
			DFS(dep+1,len+i);
		}
	}
}

int main()
{
//	freopen("in_1166_dfs.txt","r",stdin);
	while(1)
	{
		for (int i=0;i<9;++i)
		{
			cin>>a[i];
			if (cin.eof())
			{
				goto end;
			}
		}
		bestlen=0x7fffffff;
		DFS(0,0);
		first=true;
		for (int i=0;i<9;++i)
		{
			for (int j=0;j<bestans[i];++j)
			{
				if (first)
				{
					first=false;
					cout<<i+1;
				}
				else
				{
					cout<<' '<<i+1;
				}
			}
		}
		cout<<endl;
	}
end:return 0;
}
