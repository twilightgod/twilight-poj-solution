#include<iostream>
#include<string>
using namespace std;
char map[32][32];

int x,y,t,sa,i,j;

int main()
{
//	freopen("d:/in.txt","r",stdin);
	cin>>t;
	sa=0;
	while (t--)
	{
		memset(map,'.',sizeof(map));
		sa++;
		cout<<"Bitmap #"<<sa<<endl;
		cin>>x>>y;
		string s;
		cin>>s;
		for (i=0;i<s.length()-1;++i)
		{
			switch (s[i])
			{
			case 'E':x++;map[y-1][x-1]='X';
				break;
			case 'W':x--;map[y][x]='X';
				break;
			case 'N':y++;map[y-1][x]='X';
				break;
			case 'S':y--;map[y][x-1]='X';
			}
		}
		for (i=31;i>=0;--i)
		{
			for (j=0;j<32;++j)
			{
				cout<<map[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}