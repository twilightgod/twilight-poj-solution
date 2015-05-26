/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sudoku
*       ID             : 3076
*       Date           : 11/26/2008
*       Time           : 22:34:47
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<stdio.h>

#define ALLA 131070

struct Point
{
	int co_x,co_y,g,status;
};

struct ST
{
	int size;
	int a[16];
};

int bin[17];
int R[16],C[16],G[16];
int B[16][16];
ST puz[131072];
Point q[256];
int n,test;
bool got;
char ch;

inline void Change(int i,int k)
{
	B[q[i].co_x][q[i].co_y]=k;
	R[q[i].co_x]^=bin[k];
	C[q[i].co_y]^=bin[k];
	G[q[i].g]^=bin[k];
}

inline void Back(int i,int k)
{
	B[q[i].co_x][q[i].co_y]=0;
	R[q[i].co_x]|=bin[k];
	C[q[i].co_y]|=bin[k];
	G[q[i].g]|=bin[k];
}

void DFS(int dep)
{
	if(dep==n)
	{
		got=true;
		return;
	}
	int mind=17,mindi;
	for(int i=0;i<n;++i)
	{
		if(!B[q[i].co_x][q[i].co_y])
		{
			q[i].status=R[q[i].co_x]&C[q[i].co_y]&G[q[i].g];
			if(puz[q[i].status].size<mind)
			{
				mind=puz[q[i].status].size;
				mindi=i;
				if(mind==1)
				{
					break;
				}
			}
		}
	}
	if(mind==0)
	{
		return;
	}
	for(int kk=0;kk<=puz[q[mindi].status].size;++kk)
	{
		int k=puz[q[mindi].status].a[kk];
		if(q[mindi].status&bin[k])
		{
			Change(mindi,k);
			DFS(dep+1);
			if(got)
			{
				return;
			}
			Back(mindi,k);
		}
	}
}


int main()
{
	//freopen("in_3076.txt","r",stdin);
	bin[0]=1;
	for(int i=1;i<=16;++i)
	{
		bin[i]=bin[i-1]<<1;
	}
	for(int i=0;i<131072;i+=2)
	{
		puz[i].size=0;
		for(int k=1;k<=16;++k)
		{
			if(i&bin[k])
			{
				puz[i].a[puz[i].size++]=k;
			}
		}
	}
	while(1)
	{
		for(int i=0;i<16;++i)
		{
			R[i]=C[i]=G[i]=ALLA;
		}
		n=0;
		for(int i=0;i<16;++i)
		{
			for(int j=0;j<16;++j)
			{
				if(scanf("%c",&ch)==-1)
				{
					goto OUT;
				}
				if(ch!='-')
				{
					B[i][j]=ch-'A'+1;
					R[i]^=bin[B[i][j]];
					C[j]^=bin[B[i][j]];
					G[i/4*4+j/4]^=bin[B[i][j]];
				}
				else
				{
					B[i][j]=0;
					q[n].co_x=i;
					q[n].co_y=j;
					q[n].g=i/4*4+j/4;
					n++;
				}
			}
			getchar();
		}
		got=false;
		DFS(0);
		for(int i=0;i<16;++i,printf("\n"))
		{
			for(int j=0;j<16;++j)
			{
				printf("%c",char(B[i][j]+'A'-1));
			}
		}
	}
OUT:	return 0;
}
