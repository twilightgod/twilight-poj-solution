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

struct DoublyLinkedList
{
	int L,R;
	Point data;
};

struct ST
{
	int size;
	int a[9];
};

int bin[10];
int R[9],C[9],G[9];
int B[9][9];
ST puz[1024];
DoublyLinkedList q[82];
int n;
bool got;
char ch;

inline void Change(int i,int k)
{
	B[q[i].data.co_x][q[i].data.co_y]=k;
	R[q[i].data.co_x]^=bin[k];
	C[q[i].data.co_y]^=bin[k];
	G[q[i].data.g]^=bin[k];
}

inline void Back(int i,int k)
{
	R[q[i].data.co_x]|=bin[k];
	C[q[i].data.co_y]|=bin[k];
	G[q[i].data.g]|=bin[k];
}

void DFS(int dep)
{
	if(dep==n)
	{
		got=true;
		return;
	}
	int minD=10,minD_i=0;
	for(int i=q[0].R;i!=-1;i=q[i].R)
	{
		q[i].data.status=R[q[i].data.co_x]&C[q[i].data.co_y]&G[q[i].data.g];
		if(puz[q[i].data.status].size<minD)
		{
			minD=puz[q[i].data.status].size;
			if(minD==0)
			{
				return;
			}
			minD_i=i;
			if(minD==1)
			{
				break;
			}
		}
	}

	q[q[minD_i].L].R=q[minD_i].R;
	q[q[minD_i].R].L=q[minD_i].L;

	for(int kk=0;kk<puz[q[minD_i].data.status].size;++kk)
	{
		int k=puz[q[minD_i].data.status].a[kk];
		if(q[minD_i].data.status&bin[k])
		{
			Change(minD_i,k);
			DFS(dep+1);
			if(got)
			{
				return;
			}
			Back(minD_i,k);
		}
	}

	q[q[minD_i].L].R=minD_i;
	q[q[minD_i].R].L=minD_i;

}

//clock_t allstart;

int main()
{
	//allstart=clock();
	//freopen("in_3074.txt","r",stdin);
	//freopen("out.txt","w",stdout);
 	//freopen("sudoku.txt","r",stdin);
// 	freopen("temp_ver7.txt","w",stdout);
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
		q[0].L=q[0].R=-1;
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
					n++;
					B[i][j]=0;
					q[n].data.co_x=i;
					q[n].data.co_y=j;
					q[n].data.g=i/3*3+j/3;
					q[n].L=n-1;
					q[n].R=-1;
					q[n-1].R=n;
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
