/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Perfect Cubes
*       ID             : 1543
*       Date           : 4/27/2009
*       Time           : 7:56:54
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int n;

int main()
{
	//freopen("in_1543.txt","r",stdin);
	scanf("%d",&n);
	for(int a=6;a<=n;++a)
	{
		for(int b=2;b<=n;++b)
		{
			for(int c=b+1;c<=n;++c)
			{
				for(int d=c+1;d<=n;++d)
				{
					if(a*a*a==b*b*b+c*c*c+d*d*d)
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
					}
				}
			}
		}
	}
	return 0;
}
