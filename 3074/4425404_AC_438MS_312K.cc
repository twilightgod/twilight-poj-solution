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

struct Node
{
	int i,j,g,status,d;
};

int bin[10];
int R[10],C[10],G[10];
int B[10][10];
int size[1024];
int first[1024];
Node q[81];
int n;
bool got;
char ch;

inline int GetG(int i,int j)
{
	return i/3*3+j/3;
}

inline void Change(int i,int k)
{
	B[q[i].i][q[i].j]=k;
	R[q[i].i]^=bin[k];
	C[q[i].j]^=bin[k];
	G[q[i].g]^=bin[k];
}

inline void Back(int i,int k)
{
	B[q[i].i][q[i].j]=0;
	R[q[i].i]|=bin[k];
	C[q[i].j]|=bin[k];
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
		if(!B[q[i].i][q[i].j])
		{
			q[i].status=R[q[i].i]&C[q[i].j]&G[q[i].g];
			q[i].d=size[q[i].status];
			if(q[i].d<mind)
			{
				mind=q[i].d;
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
	for(int k=first[q[mindi].status];k<=9;++k)
	{
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
	//freopen("temp_ver5.txt","w",stdout);
	bin[0]=1;
	for(int i=1;i<=9;++i)
	{
		bin[i]=bin[i-1]<<1;
	}
	for(int i=0;i<1024;i+=2)
	{
		size[i]=0;
		int j=i;
		while(j)
		{
			j=j&(j-1);
			size[i]++;
		}
		j=i;
		first[i]=0;
		while(j&&!(j&1))
		{ 
			j>>=1; 
			first[i]++;
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
					G[GetG(i,j)]^=bin[B[i][j]];
				}
				else
				{
					B[i][j]=0;
					q[n].i=i;
					q[n].j=j;
					q[n].g=GetG(i,j);
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
