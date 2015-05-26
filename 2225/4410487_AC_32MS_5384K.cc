/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Asteroids!
*       ID             : 2225
*       Date           : 11/22/2008
*       Time           : 23:21:0
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;
 
#define MAXN 100
 
struct qu
{
	int x,y,z;
};
 
bool map[MAXN][MAXN][MAXN];
int move[6][3]={{-1,0,0},{0,1,0},{1,0,0},{0,-1,0},{0,0,1},{0,0,-1}};
int ti[MAXN][MAXN][MAXN];
qu q[MAXN*MAXN*MAXN];
int sx,sy,sz,ex,ey,ez,i,j,k,l,r,c,h,t,x1,y1,z1,x0,y0,z0,n;
char ch;
bool god;
string s;
 
int main()
{
	//freopen("in_2225.txt","r",stdin);
	while(cin>>s>>n)
	{
		l=r=c=n;
		memset(map,false,sizeof(map));
		memset(ti,0,sizeof(ti));
		for(k=0;k<l;++k)
		{
			for(i=0;i<r;++i)
			{
				for(j=0;j<c;++j)
				{
					cin>>ch;
					if(ch=='O')
					{
						map[i][j][k]=true;
					}
					else 
					{
						map[i][j][k]=false;
					}
				}
			}
		}
		cin>>sy>>sx>>sz;
		cin>>ey>>ex>>ez;
		/*
		for(k=0;k<l;++k,cout<<endl)
		{
			for(i=0;i<r;++i,cout<<endl)
			{
				for(j=0;j<c;++j)
				{
					cout<<(map[i][j][k]?".":"#");
				}
			}
		}
		*/
		god=true;
		ti[sx][sy][sz]=0;
		q[0].x=sx;
		q[0].y=sy;
		q[0].z=sz;
		h=-1;t=0;
		while(h!=t)
		{
			h++;
			x0=q[h].x;
			y0=q[h].y;
			z0=q[h].z;
 					if(x0==ex&&y0==ey&&z0==ez)
					{
						god=false;
						goto out;
					}
			for(i=0;i<6;++i)
			{
				x1=x0+move[i][0];
				y1=y0+move[i][1];
				z1=z0+move[i][2];
				if(x1>=0&&x1<r&&y1>=0&&y1<c&&z1>=0&&z1<l&&map[x1][y1][z1])
				{
					map[x1][y1][z1]=false;
					t++;
					q[t].x=x1;
					q[t].y=y1;
					q[t].z=z1;
					ti[x1][y1][z1]=ti[x0][y0][z0]+1;
 					if(x1==ex&&y1==ey&&z1==ez)
					{
						god=false;
						goto out;
					}
				}
			}
		}
 
out:	if(god)
		{
			cout<<"NO ROUTE\n";
		}
		else
		{
			cout<<n<<' '<<ti[ex][ey][ez]<<endl;
		}
		cin>>s;getchar();
	}
	return 0;
}
