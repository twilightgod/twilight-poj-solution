/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Geometric Shapes
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3449
*       ID             : 3449
*       Date           : 9/7/2009
*       Time           : 19:43:8
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define sign(a) ((a)>0?1:(((a)<0?-1:0)))
struct point{int x,y;point(int _x,int _y):x(_x),y(_y){} point(){} };
struct line{point a,b;line(point _a,point _b):a(_a),b(_b){}};


//计算cross product (P1-P0)x(P2-P0)
int xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//判点是否在线段上,包括端点和部分重合
int dot_online_in(point p,line l){
	return !xmult(p,l.a,l.b)&&(l.a.x-p.x)*(l.b.x-p.x)<=0&&(l.a.y-p.y)*(l.b.y-p.y)<=0;
}

//判两点在直线同侧,点在直线上返回0
int same_side(point p1,point p2,line l){
	return sign(xmult(l.a,p1,l.b))*xmult(l.a,p2,l.b)>0;
}

//判三点共线
int dots_inline(point p1,point p2,point p3){
	return !xmult(p1,p2,p3);
}

//判两线段相交,包括端点和部分重合
int intersect_in(line u,line v){
	if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
		return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
	return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}

struct Gr
{
	vector<line> l;
	char name;
};

bool cmp(Gr x,Gr y)
{
	return x.name<y.name;
};

int n;
Gr g[27];

int tx;

int GetX()
{
	return tx<<1;
}

int GetY()
{
	int ret;
	scanf(" (%d,%d)",&tx,&ret);
	return ret<<1;
}

bool CheckIns(int x,int y)
{
	for(int i=0;i<g[x].l.size();++i)
	{
		for(int j=0;j<g[y].l.size();++j)
		{
			if(intersect_in(g[x].l[i],g[y].l[j]))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3449.txt","r",stdin);
#endif
	while(1)
	{
		char ch;
		string str;
		n=0;
l1:		cin>>ch;
		if(ch=='.')
		{
			break;
		}
		if(ch!='-')
		{
			g[n].name=ch;
			cin>>str;
			g[n].l.clear();
			if(str=="line")
			{
				g[n].l.push_back(line(point(GetX(),GetY()),point(GetX(),GetY())));		
			}
			else if(str=="triangle")
			{
				point p0(GetX(),GetY());
				point p1(GetX(),GetY());
				point p2(GetX(),GetY());
				g[n].l.push_back(line(p0,p1));
				g[n].l.push_back(line(p1,p2));
				g[n].l.push_back(line(p2,p0));
			}
			else if(str=="polygon")
			{
				int nn;
				cin>>nn;
				point p0(GetX(),GetY()),p1,p00;
				p00=p0;
				for(int i=0;i<nn-1;++i)
				{
					p1.y=GetY();
					p1.x=GetX();
					g[n].l.push_back(line(p0,p1));
					p0=p1;
				}
				g[n].l.push_back(line(p0,p00));
			}
			else if(str=="rectangle")
			{
				point p0(GetX(),GetY());
				point p1(GetX(),GetY());
				point p2(GetX(),GetY());
				g[n].l.push_back(line(p0,p1));
				g[n].l.push_back(line(p1,p2));
				g[n].l.push_back(line(point(p0.x-p1.x+p2.x,p0.y-p1.y+p2.y),p0));
				g[n].l.push_back(line(point(p0.x-p1.x+p2.x,p0.y-p1.y+p2.y),p2));
			}
			else //square
			{
				point p0(GetX(),GetY());
				point p1(GetX(),GetY());
				point pm((p0.x+p1.x)/2,(p0.y+p1.y)/2);
				point px(-(p0.y-pm.y),p0.x-pm.x);
				point p2(pm.x+px.x,pm.y+px.y);
				point p3(pm.x-px.x,pm.y-px.y);
				g[n].l.push_back(line(p0,p2));
				g[n].l.push_back(line(p0,p3));
				g[n].l.push_back(line(p1,p2));
				g[n].l.push_back(line(p1,p3));
			}
			n++;
			goto l1;
		}
		sort(g,g+n,cmp);
		for(int i=0;i<n;++i)
		{
			cout<<g[i].name<<' ';
			vector<char> ni;
			for(int j=0;j<n;++j)
			{
				if(i!=j&&CheckIns(i,j))
				{
					ni.push_back(g[j].name);
				}
			}
			if(ni.size()==0)
			{
				cout<<"has no intersections\n";
			}
			else
			{
				cout<<"intersects with ";
				if(ni.size()==1)
				{
					cout<<ni[0]<<endl;
				}
				else if(ni.size()==2)
				{
					cout<<ni[0]<<" and "<<ni[1]<<endl;
				}
				else
				{
					for(int k=0;k<ni.size()-1;++k)
					{
						cout<<ni[k]<<", ";
					}
					cout<<"and "<<ni[ni.size()-1]<<endl;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
