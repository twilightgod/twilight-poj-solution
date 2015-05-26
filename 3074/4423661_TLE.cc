/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sudoku
*       ID             : 3074
*       Date           : 11/26/2008
*       Time           : 9:44:32
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<sstream>
//#include<time.h>
using namespace std;

#define ALLA 1022

struct Node
{
	int i,j,g,status,d;
};

int bin[10];
int R[10],C[10],G[10];
int B[10][10];
Node q[81];
int n;
bool got;
string s;
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
			q[i].d=0;
			for(int k=1;k<=9;++k)
			{
				if(q[i].status&bin[k])
				{
					q[i].d++;
				}
			}
			if(q[i].d<mind)
			{
				mind=q[i].d;
				mindi=i;
			}
		}
	}
	if(mind==0)
	{
		return;
	}
	for(int k=1;k<=9;++k)
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

int main()
{
	//freopen("in_3074.txt","r",stdin);
	//freopen("sudoku.txt","r",stdin);
	//freopen("temp_ver1.txt","w",stdout);
	bin[0]=1;
	for(int i=1;i<=9;++i)
	{
		bin[i]=bin[i-1]<<1;
	}
	while(cin>>s)
	{
		//clock_t start=clock();
		if(s=="end")
		{
			break;
		}
		for(int i=0;i<9;++i)
		{
			R[i]=C[i]=G[i]=ALLA;
		}
		n=0;
		stringstream ss(s);
		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
			{
				ss>>ch;
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
			}
		}
		got=false;
		DFS(0);
		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
			{
				cout<<B[i][j];
			}
		}
		cout<<endl;
		//cout<<(clock()-start)<<"ms"<<endl;
	}
	return 0;
}
