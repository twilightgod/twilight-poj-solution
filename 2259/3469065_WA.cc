#include<iostream>
using namespace std;
#define MAXN 1000
#define MAXINT 1000000

int qhead[MAXN];
int qtail[MAXN];
int s[MAXINT];
int qsize[MAXN];
int qpos[MAXN];
int qu[MAXN][MAXN];
int h,t,n,i,j,temp,p,test;
char str[10];

int main()
{
	//freopen("d:/in.txt","r",stdin);
	test=0;
	while(scanf("%d",&n)&&n!=0)
	{
		test++;
		printf("Scenario #%d\n",test);
		for(i=0;i<n;++i)
		{
			scanf("%d",&p);
			for(j=0;j<p;++j)
			{
				scanf("%d",&temp);
				s[temp]=i;
			}
		}
		memset(qhead,0,sizeof(int)*n);
		memset(qtail,-1,sizeof(int)*n);
		memset(qsize,0,sizeof(int)*n);
		memset(qpos,-1,sizeof(int)*n);
		h=0;
		t=-1;
		while(1)
		{
			scanf("%s",&str);
			if(strcmp(str,"STOP")==0)
			{
				break;
			}
			if(strcmp(str,"ENQUEUE")==0)
			{
				scanf("%d",&temp);
				int ss=s[temp];
				int pp=qpos[ss];
				if(pp<0)
				{
					t=(t+1)%MAXN;
					qpos[ss]=t;
				}
				qtail[ss]=(qtail[ss]+1)%MAXN;
				qu[qpos[ss]][qtail[ss]]=temp;
				qsize[ss]++;
			}
			else
			{
				temp=qu[h][qhead[h]];
				int ss=s[temp];
				printf("%d\n",temp);
				qhead[ss]=(qhead[ss]+1)%MAXN;
				qsize[ss]--;
				if(qsize[ss]==0)
				{
					h=(h+1)%MAXN;
					qpos[ss]=-1;
				}
			}
		}

	}
	return 0;
}