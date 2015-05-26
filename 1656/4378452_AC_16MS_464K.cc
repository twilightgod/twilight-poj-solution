#include<iostream>
#include<string>
using namespace std;

int t;
int x,y,l;
string s;
int c;

bool map[101][101];

int main()
{
	//freopen("in1656.txt","r",stdin);
	while(cin>>t)
	{
		memset(map,false,sizeof(map));
		while(t--)
		{

			cin>>s>>x>>y>>l;
			c=0;
			for(int i=x;i<=x+l-1;++i)
			{
				for(int j=y;j<=y+l-1;++j)
				{
					if(s=="TEST"&&map[i][j])
					{
						c++;
					}
					else if(s=="WHITE")
					{
						map[i][j]=false;
					}
					else if(s=="BLACK")
					{
						map[i][j]=true;
					}
				}
			}
			if(s=="TEST")
			{
				cout<<c<<endl;
			}
		}
	}
	return 0;
}
