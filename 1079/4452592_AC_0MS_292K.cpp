/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Ratio
*       ID             : 1079
*       Date           : 12/4/2008
*       Time           : 14:43:8
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

double n,w,w1,w2;
int a,b,zi,deno,d1,d2;
bool first;

int main()
{
	//freopen("in_1079.txt","r",stdin);
	first=true;
	while(cin>>a>>b)
	{
		if (first)
		{
			first=false;
		}
		else
		{
			cout<<endl;
		}
		n=(double)a/b;
		for(deno=1;deno<=b;++deno)
		{
			d1=(int)floor(n*(double)deno);
			d2=(int)ceil(n*(double)deno);
			w1=fabs((double)d1/(double)deno-(double)n);
			w2=fabs((double)d2/(double)deno-(double)n);
			if(w1<w2)
			{
				if(deno==1)
				{
					w=w1;
					cout<<d1<<'/'<<deno<<endl;
				}
				else
				{
					if (w>w1)
					{
						cout<<d1<<'/'<<deno<<endl;
						w=w1;
					}
				}
			}
			else
			{
				if(deno==1)
				{
					w=w2;
					cout<<d2<<'/'<<deno<<endl;
				}
				else
				{
					if (w>w2)
					{
						cout<<d2<<'/'<<deno<<endl;
						w=w2;
					}
				}
			}
		}
	}
	return 0;
}