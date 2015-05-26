/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sudoku
*       ID             : 3074
*       Date           : 11/26/2008
*       Time           : 9:44:32
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//DFS Ver 7.1
//#include<time.h>
#include<stdio.h>

//1111111110B
//第i位为1表示数字i可选
#define ALLA 1022

//空白格子的数据
struct Point
{
	//所在x,y坐标,所在组,可用的状态
	int co_x,co_y,g,status;
};

//双向静态链表的节点,储存空格点
struct DoublyLinkedList
{
	//前/后指针
	int L,R;
	//数据
	Point data;
};

//某个状态可用下所有可用数字
struct ST
{
	//可用数字总数
	int size;
	//依次储存每一个可用数字
	int a[9];
};

//2的幂
int bin[10];
//行,列,组的状态数组
int R[9],C[9],G[9];
//棋盘
int B[9][9];
//空白格子所有可能状态
ST puz[1024];
//双向链表
DoublyLinkedList DL[82];
//空白格子总数
int n;
//是否得到解
bool got;
//读入用缓冲字符
char ch;

//链表中节点i所储存的空白格子放数字k
inline void Change(int i,int k)
{
	//放置k
	B[DL[i].data.co_x][DL[i].data.co_y]=k;
	//更新其所在的行,列,组的可用状态
	R[DL[i].data.co_x]^=bin[k];
	C[DL[i].data.co_y]^=bin[k];
	G[DL[i].data.g]^=bin[k];
}

//回溯,取消放置
inline void Back(int i,int k)
{
	R[DL[i].data.co_x]|=bin[k];
	C[DL[i].data.co_y]|=bin[k];
	G[DL[i].data.g]|=bin[k];
}

//深度优先搜索,dep表示搜索深度
void DFS(int dep)
{
	//递归边界,达到n+1层
	if(dep==n)
	{
		//获得解
		got=true;
		return;
	}

	//在没用过的空白节点中寻找可用数字总数最小的,minD_i为其在链表中的节点标号
	int minD=10,minD_i=0;
	for(int i=DL[0].R;i!=-1;i=DL[i].R)
	{
		//计算节点i所储存的空白格子的可用的状态
		DL[i].data.status=R[DL[i].data.co_x]&C[DL[i].data.co_y]&G[DL[i].data.g];
		//更新
		if(puz[DL[i].data.status].size<minD)
		{
			//记录最小值
			minD=puz[DL[i].data.status].size;
			//可用数为0,无解,回溯
			if(minD==0)
			{
				return;
			}
			//记录最小值对应的节点
			minD_i=i;
			//可用数为1已经是最少的了,不用继续遍历链表
			if(minD==1)
			{
				break;
			}
		}
	}

	//从链表中删除节点minD_i
	DL[DL[minD_i].L].R=DL[minD_i].R;
	DL[DL[minD_i].R].L=DL[minD_i].L;

	//枚举可放置的数字k
	for(int kk=0;kk<puz[DL[minD_i].data.status].size;++kk)
	{
		int k=puz[DL[minD_i].data.status].a[kk];
		//if(DL[minD_i].data.status&bin[k])
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

	DL[DL[minD_i].L].R=minD_i;
	DL[DL[minD_i].R].L=minD_i;

}

//clock_t allstart;

int main()
{
//	allstart=clock();
	//freopen("in_3074.txt","r",stdin);
	//freopen("out.txt","w",stdout);
 //	freopen("sudoku.txt","r",stdin);
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
		DL[0].L=DL[0].R=-1;
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
					DL[n].data.co_x=i;
					DL[n].data.co_y=j;
					DL[n].data.g=i/3*3+j/3;
					DL[n].L=n-1;
					DL[n].R=-1;
					DL[n-1].R=n;
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
