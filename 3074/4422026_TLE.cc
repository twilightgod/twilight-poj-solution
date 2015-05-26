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
using namespace std;

#define ALLA 1022

struct Node
{
	int i,j;
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

void DFS(int dep)
{
	if(dep==n)
	{
		got=true;
		return;
	}
	int i=q[dep].i;
	int j=q[dep].j;
	int av=G[GetG(i,j)]&R[i]&C[j];
	if(av==0)
	{
		return;
	}
	for(int k=1;k<=9;++k)
	{
		if(av&bin[k])
		{
			B[i][j]=k;
			R[i]^=bin[k];
			C[j]^=bin[k];
			G[GetG(i,j)]^=bin[k];
			DFS(dep+1);
			if(got)
			{
				return;
			}
			B[i][j]=0;
			R[i]|=bin[k];
			C[j]|=bin[k];
			G[GetG(i,j)]|=bin[k];
		}
	}
}

int main()
{
	//freopen("in_3074.txt","r",stdin);
	bin[0]=1;
	for(int i=1;i<=9;++i)
	{
		bin[i]=bin[i-1]<<1;
	}
	while(cin>>s)
	{
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
	}
	return 0;
}
