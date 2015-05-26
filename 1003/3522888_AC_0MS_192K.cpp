#include<iostream>
#include<math.h>
using namespace std;

int i,n;
double sum,t;

inline bool equ0(double x)
{
	return fabs(x)<1e-6;
}

int main()
{
	while(cin>>t&&!equ0(t))
	{
		sum=0;
		i=1;
		while(1)
		{
			i++;
			sum+=1/(double)i;
			if(equ0(sum-t)||sum>t)
			{
				break;
			}
		}
		cout<<i-1<<" card(s)\n";
	}
	return 0;
}
