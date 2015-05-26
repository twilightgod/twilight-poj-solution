/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Going Home
*       ID             : 2195
*       Date           : 5/7/2009
*       Time           : 7:9:43
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//KM
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;

struct Coo
{
	int x,y;
	Coo (int _x,int _y)
	{
		x=_x;
		y=_y;
	}
};

#define MAXN 1002
#define inf 1000000000
vector<Coo> man,house;
int mat[MAXN][MAXN],m1[MAXN],m2[MAXN];
int n,m;

#define _clr(x) memset(x,0xff,sizeof(int)*n)

//二分图最佳匹配,kuhn munkras算法,邻接阵形式,复杂度O(m*m*n)
//返回最佳匹配值,传入二分图大小m,n和邻接阵mat,表示权值
//match1,match2返回一个最佳匹配,未匹配顶点match值为-1
//一定注意m<=n,否则循环无法终止
//最小权匹配可将权值取相反数
int kuhn_munkras(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
	for (i=0;i<m;i++)
		for (l1[i]=-inf,j=0;j<n;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
	for (i=0;i<n;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<m;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
		if (match1[i]<0){
			for (i--,p=inf,k=0;k<=q;k++)
				for (j=0;j<n;j++)
					if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
						p=l1[s[k]]+l2[j]-mat[s[k]][j];
			for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
			for (k=0;k<=q;l1[s[k++]]-=p);
		}
	}
	for (i=0;i<m;i++)
		ret+=mat[i][match1[i]];
	return ret;
}

int main()
{
//	freopen("in_2195.txt","r",stdin);
	while(cin>>m>>n&&m)
	{
		man.clear();
		house.clear();
		getchar();
		for(int i=0;i<m;++i,getchar())
		{
			for(int j=0;j<n;++j)
			{
				switch(getchar())
				{
				case 'm':man.push_back(Coo(i,j));break;
				case 'H':house.push_back(Coo(i,j));break;
				}
			}
		}
//		s=man.size()+house.size();
//		t=s+1;
		memset(mat,0,sizeof(mat));
//		memset(cost,0,sizeof(cost));
		for(int i=0;i<man.size();++i)
		{
			for(int j=0;j<house.size();++j)
			{
	//			cost[i][j+man.size()]=abs(man[i].x-house[j].x)+abs(man[i].y-house[j].y);
				//mat[i][j+man.size()]=1;
				mat[i][j]=-(abs(man[i].x-house[j].x)+abs(man[i].y-house[j].y));
			}
		}
		int ans=0;
		ans=kuhn_munkras(man.size(),house.size(),mat,m1,m2);
		cout<<-ans<<endl;
	}
	return 0;
}
