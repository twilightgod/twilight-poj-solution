/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Find the Clones
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2945
*       ID             : 2945
*       Date           : 10/6/2009
*       Time           : 22:38:47
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

#define MAXN 20001

typedef map<long long,int> DNA;
int n,m;
DNA dna;
DNA::iterator mit;
int cnt[MAXN];
char buf[30];
long long four[30];

inline int GetW(char ch)
{
	switch(ch)
	{
	case 'A':return 0;
	case 'C':return 1;
	case 'G':return 2;
	case 'T':return 3;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2945.txt","r",stdin);
#endif
	four[0]=1;
	for(int i=1;i<=20;++i)
	{
		four[i]=four[i-1]*4;
	}
	while(scanf("%d%d\n",&n,&m)&&n)
	{
		dna.clear();
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;++i)
		{
			//scanf("%s\n",&buf);
			gets(buf);
			long long tmp=0;
			for(int j=0;j<m;++j)
			{
				tmp+=four[j]*GetW(buf[j]);
			}
			mit=dna.find(tmp);
			if(mit==dna.end())
			{
				dna[tmp]=1;
			}
			else
			{
				dna[tmp]++;
			}
		}
		for(mit=dna.begin();mit!=dna.end();++mit)
		{
			cnt[mit->second]++;
		}
		for(int i=1;i<=n;++i)
		{
			printf("%d\n",cnt[i]);
		}
	}
	return 0;
}
