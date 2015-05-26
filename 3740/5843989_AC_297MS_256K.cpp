/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Easy Finding
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3740
*       ID             : 3740
*       Date           : 9/11/2009
*       Time           : 18:43:51
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#define MAXN 6000

int L[MAXN],R[MAXN],U[MAXN],D[MAXN],S[MAXN],Col[MAXN],Row[MAXN];
int ans[1001];
int n,m,c,deep,cnt;

//建立所有头节点
void BuildHeaderNode()
{
	//总头节点
	L[0]=R[0]=0;
	//列头结点
	for(int i=1;i<=m;++i)
	{
		L[i]=i-1;
		R[i]=0;
		L[0]=i;
		R[i-1]=i;
		U[i]=i;
		D[i]=i;
		S[i]=0;
	}
}

//添加节点
//pre为这次要加入的节点的行前驱,-1表示无前驱
//j为所属列
//n为行号
int AddNode(int pre,int j,int n)
{
	Col[cnt]=j;
	U[cnt]=U[j];
	D[cnt]=j;
	D[U[cnt]]=cnt;
	U[j]=cnt;
	S[j]++;
	Row[cnt]=n;
	if(pre==-1)
	{
		L[cnt]=R[cnt]=cnt;
	}
	else
	{
		L[cnt]=pre;
		R[cnt]=R[pre];
		L[R[pre]]=cnt;
		R[pre]=cnt;
	}
	return cnt++;
}

void remove(int &c) {
	L[R[c]] = L[c];
	R[L[c]] = R[c];
	for(int i = D[c]; i != c ; i = D[i]) {
		for(int j = R[i]; j != i ; j = R[j]) {
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			--S[Col[j]];
		}
	}
}

void resume(int &c) {
	for(int i = U[c];i != c;i = U[i]) {
		for(int j = L[i]; j != i ; j = L[j]) {
			++S[Col[j]];
			U[D[j]] = j;
			D[U[j]] = j;
		}
	}
	L[R[c]] = c;
	R[L[c]] = c;
}

bool dfs() {
	if(R[0] == 0) {
		return true;
	}
	int i , j;
	int idx,minnum = 999999;
	for(i = R[0];i != 0 ; i = R[i]) {
		if(S[i] < minnum) {
			minnum = S[i];
			idx = i;
		}
	}
	remove(idx);
	for(i = D[idx]; i != idx; i = D[i]) {
		ans[deep++] = Row[i];
		for(j = R[i]; j != i ; j = R[j]) {
			remove(Col[j]);
		}
		if(dfs()) {
			return true;
		}
		deep --;
		for(j = L[i]; j != i ; j = L[j]) {
			resume(Col[j]);
		}
	}
	resume(idx);
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3740.txt","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		BuildHeaderNode();
		cnt=m+1;
		for(int i=0;i<n;++i)
		{
			int pre=-1;
			for(int j=0;j<m;++j)
			{
				scanf("%d",&c);
				if(c==1)
				{
					pre=AddNode(pre,j+1,i+1);
				}
			}
		}
		deep=0;
		if(dfs())
		{
			printf("Yes, I found it\n");
		}
		else
		{
			printf("It is impossible\n");
		}
	}
	return 0;
}
