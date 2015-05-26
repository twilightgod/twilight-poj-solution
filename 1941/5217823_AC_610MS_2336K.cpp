#include<iostream>
using namespace std;

#define MAXN 2048

char f[MAXN][MAXN];
int b[13];
int n;

void DFS(int x,int y,int size)
{
	if(size==1)
	{
		f[x][y+1]=f[x+1][y]='/';
		f[x][y+2]=f[x+1][y+3]='\\';
		f[x+1][y+1]=f[x+1][y+2]='_';
		return;
	}
	DFS(x,y+b[size-1],size-1);
	DFS(x+b[size-1],y,size-1);
	DFS(x+b[size-1],y+b[size],size-1);
}

int main()
{
	//freopen("fractal.txt","r",stdin);
	b[0]=1;
	for(int i=1;i<13;++i)
	{
		b[i]=b[i-1]<<1;
	}
	while(cin>>n&&n)
	{
		for(int i=0;i<b[n];++i)
		{
			for(int j=0;j<b[n+1];++j)
			{
				f[i][j]=' ';
			}
		}
		DFS(0,0,n);
		int ma=b[n];
		for(int i=0;i<b[n];++i)
		{
			for(int j=0;j<=ma;++j)
			{
				printf("%c",f[i][j]);
			}
			ma++;
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}