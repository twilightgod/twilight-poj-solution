/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Dungeon Master
*       ID             : 2251
*       Date           : 11/22/2008
*       Time           : 23:13:1
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
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
int sx,sy,sz,ex,ey,ez,i,j,k,l,r,c,h,t,x1,y1,z1,x0,y0,z0;
char ch;
bool god;
 
int main()
{
	//freopen("e:/in.txt","r",stdin);
	while(cin>>l>>r>>c)
	{
		if(l==0&&r==0&&c==0)
		{
			break;
		}
		memset(map,false,sizeof(map));
		memset(ti,0,sizeof(ti));
		for(k=0;k<l;++k,getchar())
		{
			for(i=0;i<r;++i)
			{
				for(j=0;j<c;++j)
				{
					cin>>ch;
					if(ch=='S')
					{
						sz=k;
						sx=i;
						sy=j;
						map[i][j][k]=false;
					}
					else if(ch=='E')
					{
						ez=k;
						ex=i;
						ey=j;
						map[i][j][k]=true;
					}
					else if(ch=='.')
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
			cout<<"Trapped!\n";
		}
		else
		{
			printf("Escaped in %d minute(s).\n",ti[ex][ey][ez]);
		}
	}
	return 0;
}
