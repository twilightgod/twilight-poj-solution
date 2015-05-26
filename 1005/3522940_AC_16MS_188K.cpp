#include<iostream>
#include<math.h>
using namespace std;

double r1,r0,x,y,r3;
int year,n,t;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	cin>>t;
	n=0;
	while(t--)
	{
		cin>>x>>y;
		r3=sqrt(x*x+y*y);
		year=0;
		r0=0;
		n++;
		while(1)
		{
			year++;
			r1=sqrt(100/3.1415926+r0*r0);
			if(r1>r3)
			{
				break;
			}
			r0=r1;
		}
		printf("Property %d: This property will begin eroding in year %d.\n",n,year);
	}
	cout<<"END OF OUTPUT.\n";
	return 0;
}
