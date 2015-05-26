/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sudoku
*       ID             : 3074_DLX
*       Date           : 11/29/2008
*       Time           : 21:42:11
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//Dancing Links X applicated to Sudoku
#include"stdio.h"
#include"stdlib.h"

#define NS 3
#define NS2 (NS*NS)
#define NS3 (NS2*NS)
#define NS4 (NS3*NS)

#define OFFSET_P 1
#define OFFSET_R NS4+1
#define OFFSET_C 2*NS4+1
#define OFFSET_B 3*NS4+1

#define MAXINT 2147483647

struct Node
{
	int U,D,L,R,C,S,N;
};

int count;
Node DL[4*NS4+1+4*NS4*NS2];
int board[NS4];
bool got;
char ch;

void BuildHeaderNode()
{
	DL[0].L=DL[0].R=0;
	for(int i=1;i<=4*NS4;++i)
	{
		DL[i].L=i-1;
		DL[i].R=0;
		DL[0].L=i;
		DL[i-1].R=i;
		DL[i].U=i;
		DL[i].D=i;
		DL[i].S=0;
	}
}

int AddNode(int pre,int j,int n)
{
	DL[count].C=j;
	DL[count].U=DL[j].U;
	DL[count].D=j;
	DL[DL[count].U].D=count;
	DL[j].U=count;
	DL[j].S++;
	DL[count].N=n;
	if(pre==-1)
	{
		DL[count].L=DL[count].R=count;
	}
	else
	{
		DL[count].L=pre;
		DL[count].R=DL[pre].R;
		DL[DL[pre].R].L=count;
		DL[pre].R=count;
	}
	return count++;
}

void Cover(int c)
{
	DL[DL[c].R].L=DL[c].L;
	DL[DL[c].L].R=DL[c].R;
	for(int i=DL[c].D;i!=c;i=DL[i].D)
	{
		for(int j=DL[i].R;j!=i;j=DL[j].R)
		{
			DL[DL[j].D].U=DL[j].U;
			DL[DL[j].U].D=DL[j].D;
			DL[DL[j].C].S--;
		}
	}
}

void Uncover(int c)
{
	for(int i=DL[c].U;i!=c;i=DL[i].U)
	{
		for(int j=DL[i].L;j!=i;j=DL[j].L)
		{
			DL[DL[j].C].S++;
			DL[DL[j].D].U=j;
			DL[DL[j].U].D=j;
		}
	}
	DL[DL[c].R].L=c;
	DL[DL[c].L].R=c;
}

void Search(int k)
{
	if(DL[0].R==0)
	{
		got=true;
		return;
	}
	int c,s=MAXINT;
	for(int j=DL[0].R;j!=0;j=DL[j].R)
	{
		if(DL[j].S<s)
		{
			c=j;
			s=DL[j].S;
		}
	}
	Cover(c);
	for(int r=DL[c].D;r!=c;r=DL[r].D)
	{
		board[DL[r].N/NS4]=DL[r].N%NS4+1;
		for(int j=DL[r].R;j!=r;j=DL[j].R)
		{
			Cover(DL[j].C);
		}
		Search(k+1);
		if(got)
		{
			return;
		}
		for(int j=DL[r].L;j!=r;j=DL[j].L)
		{
			Uncover(DL[j].C);
		}
	}
	Uncover(c);
}

inline void BuildRow(int i,int k)
{
	int r,c,b,pre;
	r=i/NS2;
	c=i%NS2;
	b=r/NS*NS+c/NS;
	pre=AddNode(-1,i+OFFSET_P,i*NS4+k-1);
	pre=AddNode(pre,r*NS2+k-1+OFFSET_R,i*NS4+k-1);
	pre=AddNode(pre,c*NS2+k-1+OFFSET_C,i*NS4+k-1);
	AddNode(pre,b*NS2+k-1+OFFSET_B,i*NS4+k-1);
}

void BulidDataNode()
{
	count=4*NS4+1;
	for(int i=0;i<NS4;++i)
	{
		if(board[i]!=0)
		{
			BuildRow(i,board[i]);
		}
		else
		{
			for(int k=1;k<=NS2;++k)
			{
				BuildRow(i,k);
			}
		}
	}
}

void BulidDL()
{
	BuildHeaderNode();
	BulidDataNode();
}

void InputPuzzle()
{
	for(int i=0;i<NS4;++i)
	{
		scanf("%c",&ch);
		if(ch=='e')
		{
			exit(0);
		}
		else if(ch!='.')
		{
			board[i]=ch-48;
		}
		else
		{
			board[i]=0;
		}
	}
	getchar();
}

void OutputSolution()
{
	for(int i=0;i<NS4;++i)
	{
		printf("%d",board[i]);
	}
	printf("\n");
}

int main()
{
	//freopen("in_3074_DLX.txt","r",stdin);
	while(1)
	{
		InputPuzzle();
		BulidDL();
		got=false;
		Search(0);
		OutputSolution();
	}
	return 0;
}
