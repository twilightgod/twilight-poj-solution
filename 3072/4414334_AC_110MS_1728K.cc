/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Robot
*       ID             : 3072
*       Date           : 11/23/2008
*       Time           : 22:1:7
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 20
#define MAXD 1e20

const double PI=3.14159265358979323846264338327950288419716939937510;
double x[MAXN],y[MAXN],w[MAXN*MAXN][MAXN*MAXN],d[MAXN*MAXN];
bool used[MAXN*MAXN];
int n,best;
double R,temp;

inline double min1(double a,double b)
{
	return a<b?a:b;
}

inline double GetDistance2(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

double GetDegree(int i1,int j1,int i2,int j2)
{
	double r1=atan2(y[j1]-y[i1],x[j1]-x[i1]),
		r2=atan2(y[j2]-y[i2],x[j2]-x[i2]),
		r=fabs(r1-r2);
	return min1(r,2*PI-r)*180/PI;
}

inline int P(int i,int j)
{
	return i*n+j;
}

int main()
{
	//freopen("in_3072.txt","r",stdin);
	while(cin>>R>>n)
	{
		if(n==-1&&R==-1)
		{
			break;
		}
		for(int i=0;i<n;++i)
		{
			cin>>x[i]>>y[i];
		}
		for(int i=0;i<=P(n-1,n-1);++i)
		{
			for(int j=0;j<=P(n-1,n-1);++j)
			{
				w[i][j]=MAXD;
			}
			d[i]=MAXD;
			used[i]=false;
		}
		for(int i=1;i<n;++i)
		{
			if(GetDistance2(0,i)<=R*R)
			{
				w[P(0,0)][P(i,0)]=sqrt(GetDistance2(0,i))+GetDegree(0,n-1,0,i);
			}
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				for(int k=0;k<n;++k)
				{
					if(i!=k&&i!=j&&j!=k&&GetDistance2(i,j)<=R*R&&GetDistance2(j,k)<=R*R)
					{
						w[P(j,i)][P(k,j)]=sqrt(GetDistance2(j,k))+GetDegree(i,j,j,k);
					}
				}
			}
		}
		for(int i=0;i<n-1;++i)
		{
			w[P(n-1,i)][P(n-1,n-1)]=0;
		}
		d[P(0,0)]=0;
		while(1)
		{
			best=-1;
			temp=MAXD;
			for(int i=0;i<=P(n-1,n-1);++i)
			{
				if(!used[i]&&d[i]<temp)
				{
					best=i;
					temp=d[i];
				}
			}
			if(best==P(n-1,n-1)||best==-1)
			{
				break;
			}
			used[best]=true;
			for(int i=0;i<=P(n-1,n-1);++i)
			{
				if(!used[i]&&w[best][i]+temp<d[i])
				{
					d[i]=w[best][i]+temp;
				}
			}
		}
		if(best==-1)
		{
			cout<<"impossible\n";
		}
		else
		{
			cout<<int(d[P(n-1,n-1)]+0.5)<<endl;
		}
	}
	return 0;
}
