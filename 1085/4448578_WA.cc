/*
线段使用二进制存储,2^i表示第i条线段的hash值
0<=state<2^18,二进制表示当前棋盘状态
f(state) 表示在state这个状态下,A先走,双方走法都是最优,最终A比B多得到的三角形个数

0<=i<18,记place(state,2^i)=t,则
f(state)=max
{
	   -f(state|2^i)	当t=0
	 t +f(state|2^i)	当t>0
}
*/
#include<iostream>
using namespace std;

//储存组成每个三角形的线段hash值
int tri[9][3]=
{
	{0x1,0x2,0x4},
	{0x4,0x10,0x20},
	{0x8,0x10,0x80},
	{0x20,0x40,0x100},
	{0x200,0x400,0x8000},
	{0x80,0x400,0x800},
	{0x800,0x1000,0x10000},
	{0x100,0x1000,0x2000},
	{0x2000,0x4000,0x20000}
};

//存线段端点标号
int line[18][2]=
{
	{1, 2},{1, 3},{2, 3},{2, 4},{2, 5},{3, 5},
    {3, 6},{4, 5},{5, 6},{4, 7},{4, 8},{5, 8},                                 
	{5, 9},{6, 9},{6, 10},{7, 8},{8, 9},{9, 10}
};

//2的幂
int exp2[18]=
{
	0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x100,0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000,0x10000,0x20000
};

/*
全局变量
f[] 将f()的值存下,避免重复计算
state 当前棋盘状态
MIN 初始化的极小值
*/
int f[0x40000];
int state;
const int MIN=-10;

//计算在state这个状态下,放置某线段新得到的三角形数
int place(int state,int hash)
{
	int already,t,get=0;
	for(int i=0;i<9;++i)
	{
		already=0;t=3;
		for(int j=0;j<3;++j)
		{
			//放置的线段是第i个三角形中的第j条
			if(tri[i][j]&hash)
			{
				t=j;
			}
			//第i个三角形中的第j条已经放置
			else if(tri[i][j]&state)
			{
				already++;
			}
		}
		//不存在于第i个三角形中
		if(t==3)
		{
			continue;
		}
		//则第i个三角形是新得到的
		if(already==2)
		{
			get++;
		}
	}
	return get;
}

//f()
int dp(int state)
{
	//如果当前状态已算过就直接用
	if(f[state]!=MIN)
	{
		return f[state];
	}

	int max=MIN,t;
	for(int i=0;i<18;++i)
	{
		//如果第i条线段没有用过
		if(!(state&exp2[i]))
		{
			//放置第i条线段
			t=place(state,exp2[i]);
			//递归计算
			t+=((t)?1:-1)*dp(state|exp2[i]);
			//更新最大值
			max=(t>max)?t:max;
		}
	}
	//存下当前状态的最大值,并返回
	return (f[state]=max);
}

int main()
{
	//全局初始化
	for(int i=0;i<0x40000;++i)
	{
		f[i]=MIN;
	}
	f[0x3FFFF]=0;
	/*
	b 数据块数
	n 每块的局数
	m 每局已经走的步数
	x,y 读入的线段
	t 临时变量
	player 表示当前谁走(1 A,-1 B)
	pre 根据给出的步骤A比B多得到的三角形数
	*/
	int b,n,m,x,y,t,player,pre;
	cin>>b;
	for(int i=0;i<b;++i)
	{
		cin>>n;
		for(int j=0;j<n;++j)
		{
			//每局初始化
			pre=0;
			state=0;
			player=1;
			cin>>m;
			for(int k=0;k<m;++k)
			{
				//读入线段
				cin>>x>>y;
				for(int l=0;l<18;++l)
				{
					//转化为hash并放置
					if(line[l][0]==x&&line[l][1]==y)
					{
						t=place(state,exp2[l]);
						state|=exp2[l];
						break;
					}
				}
				//新得到三角形
				if(t)
				{
					pre+=(player*t);
				}
				//没有生成新三角形则换另一方走
				else
				{
					player*=-1;
				}
			}
			//计算状态并输出,>0即A胜
			cout<<"Game "<<j+1<<": "<<((pre+player*dp(state)>0)?'A':'B')<<" wins.\n";
		}
		cout<<endl;
	}
}