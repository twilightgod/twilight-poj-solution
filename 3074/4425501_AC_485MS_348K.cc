/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sudoku
*       ID             : 3074
*       Date           : 11/26/2008
*       Time           : 9:44:32
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//#include<time.h>
#include<stdio.h>

#define ALLA 1022

struct Point
{
	int co_x,co_y,g,status;
};

struct ST
{
	int size;
	int a[10];
};

int bin[10];
int R[10],C[10],G[10];
int B[10][10];
ST puz[1024];
Point q[81];
int n;
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
	int mind=10,mindi;
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

//clock_t allstart;

int main()
{
	//allstart=clock();
	//freopen("in_3074.txt","r",stdin);
	//freopen("sudoku.txt","r",stdin);
	//freopen("temp_ver6.txt","w",stdout);
	bin[0]=1;
	for(int i=1;i<=9;++i)
	{
		bin[i]=bin[i-1]<<1;
	}
	for(int i=0;i<1024;i+=2)
	{
		puz[i].size=0;
		for(int k=1;k<=9;++k)
		{
			if(i&bin[k])
			{
				puz[i].a[puz[i].size++]=k;
			}
		}
	}
	while(1)
	{
		//clock_t start=clock();
		ch=getchar();
		if(ch=='e')
		{
			break;
		}
		for(int i=0;i<9;++i)
		{
			R[i]=C[i]=G[i]=ALLA;
		}
		n=0;
		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
			{
				if(ch!='.')
				{
					B[i][j]=ch-48;
					R[i]^=bin[B[i][j]];
					C[j]^=bin[B[i][j]];
					G[i/3*3+j/3]^=bin[B[i][j]];
				}
				else
				{
					B[i][j]=0;
					q[n].co_x=i;
					q[n].co_y=j;
					q[n].g=i/3*3+j/3;
					n++;
				}
				ch=getchar();
			}
		}
		got=false;
		DFS(0);
		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
			{
				printf("%d",B[i][j]);
			}
		}
		printf("\n");
		//printf("%dms\n",clock()-start);
	}
	//printf("Total time : %dms\n",clock()-allstart);
	return 0;
}
