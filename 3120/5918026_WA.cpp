/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sudoku
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3120
*       ID             : 3120
*       Date           : 9/26/2009
*       Time           : 17:2:41
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sudoku
*       ID             : 3074_DLX
*       Date           : 11/29/2008
*       Time           : 21:42:11
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//Exact Cover with Algorithm X
//Dancing Links X(asa DLX) applicated to Sudoku
#include"stdio.h"
#include"stdlib.h"

//棋盘小块的边长
#define NS 3
//次方
#define NS2 (NS*NS)
#define NS3 (NS2*NS)
#define NS4 (NS3*NS)

//exact cover columns
//格子覆盖    行覆盖             列覆盖               块覆盖
//[1,Ns^4]   [Ns^4+1,2*Ns^4]  [2*Ns^4+1,3*Ns^4]  [3*Ns^4+1,4*Ns^4]
#define OFFSET_P 1
#define OFFSET_R NS4+1
#define OFFSET_C 2*NS4+1
#define OFFSET_B 3*NS4+1

//正无穷大
#define MAXINT 2147483647

//链表节点结构
struct Node
{
	//上,下,左,右,所在列,(列头结点)列下属节点总数,所在行
	int U,D,L,R,C,S,N;
};

//用于建立静态链表的累加器
int count;
//0号为头结点
//Ns==3时,表为324*729
//每行4个节点,共[ Ns^4(格数) * Ns^2(可填数字数) ]行
Node DL[4*NS4+1+4*NS4*NS2];
//储存棋盘
int board[NS4];
//是否找到解
bool got;
//读入缓存
char ch;

//建立所有头节点
void BuildHeaderNode()
{
	//总头节点
	DL[0].L=DL[0].R=0;
	//列头结点
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

//添加节点
//pre为这次要加入的节点的行前驱,-1表示无前驱
//j为所属列
//n为行号
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

//覆盖列c
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

//恢复覆盖列c
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

//深度优先搜索
void Search()
{
	//列头节点只剩下总头节点,找到解
	if(DL[0].R==0)
	{
		got=true;
		return;
	}

	//启发式搜索,找节点最少的列进行搜索
	int c,s=MAXINT;
	for(int j=DL[0].R;j!=0;j=DL[j].R)
	{
		if(DL[j].S<s)
		{
			c=j;
			s=DL[j].S;
		}
	}

	//覆盖列c
	Cover(c);
	//选取节点r所在行
	for(int r=DL[c].D;r!=c;r=DL[r].D)
	{
		//将r所在行加入解
		board[DL[r].N/NS4]=DL[r].N%NS4+1;
		//覆盖r所在行所有节点的列
		for(int j=DL[r].R;j!=r;j=DL[j].R)
		{
			Cover(DL[j].C);
		}
		//搜索下一层
		Search();
		//找到解,返回
		if(got)
		{
			return;
		}
		//恢复覆盖r所在行所有节点的列
		for(int j=DL[r].L;j!=r;j=DL[j].L)
		{
			Uncover(DL[j].C);
		}
	}
	//恢复覆盖列c
	Uncover(c);
}

//建立一行
//i为格子编号
//k为所选用数字
inline void BuildRow(int i,int k)
{
	//计算所在行,列,块
	int r,c,b,pre;
	r=i/NS2;
	c=i%NS2;
	b=r/NS*NS+c/NS;
	//添加位置,行,列,块的节点
	pre=AddNode(-1,i+OFFSET_P,i*NS4+k-1);
	pre=AddNode(pre,r*NS2+k-1+OFFSET_R,i*NS4+k-1);
	pre=AddNode(pre,c*NS2+k-1+OFFSET_C,i*NS4+k-1);
	AddNode(pre,b*NS2+k-1+OFFSET_B,i*NS4+k-1);
}

//建立数据节点
void BulidDataNode()
{
	//数据节点接在头节点之后
	count=4*NS4+1;
	//建立行
	for(int i=0;i<NS4;++i)
	{
		//如果格子i非空,只添加特定行
		if(board[i]!=0)
		{
			BuildRow(i,board[i]);
		}
		//否则添加所有可能
		else
		{
			for(int k=1;k<=NS2;++k)
			{
				BuildRow(i,k);
			}
		}
	}
}

//建立十字链表
void BulidDL()
{
	BuildHeaderNode();
	BulidDataNode();
}

//读入初始局面
void InputPuzzle()
{
	for(int i=0;i<NS2;++i)
	{
		for(int j=0;j<NS2;++j)
		{
			scanf("%c",&ch);
			if(ch!='0')
			{
				board[i*NS2+j]=ch-48;
			}
			else
			{
				board[i*NS2+j]=0;
			}
		}
		getchar();
	}
	getchar();
}

int te;

//输出解
void OutputSolution()
{
	if(!got)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");	
	}
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3120.txt","r",stdin);
#endif
	scanf("%d\n",&te);
	while(te--)
	{
		InputPuzzle();
		BulidDL();
		got=false;
		Search();
		OutputSolution();
	}
	return 0;
}
