#include<iostream>
#include<string>
#include<set>
using namespace std;

char map[5][5];
const int move[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
string temp;
set<string> s;

void DFS(int x,int y,int dep)
{
	if(dep==6)
	{
		s.insert(temp);
		return;
	}
	for(int i=0;i<4;++i)
	{
		int nx,ny;
		nx=x+move[i][0];
		ny=y+move[i][1];
		if(nx>=0&&ny>=0&&nx<5&&ny<5)
		{
			temp[dep]=map[nx][ny];
			DFS(nx,ny,dep+1);
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)
		{
			cin>>map[i][j];
		}
	}
	temp.resize(6);
	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)
		{
			temp[0]=map[i][j];
			DFS(i,j,1);
		}
	}
	cout<<s.size()<<endl;
	return 0;
}

