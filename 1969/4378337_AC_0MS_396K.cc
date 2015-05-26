#include<iostream>
#include<math.h>
using namespace std;

int k,c,n;

int main()
{
	while(scanf("%d",&n)!=-1)
	{
		k=floor((sqrt((double)1+8*n-1)-1)/2-0.000000001);
		c=n-k*(k+1)/2;
		printf("TERM %d IS %d/%d\n",n,k%2?c:k+2-c,k%2?k+2-c:c);
	}
	return 0;
}
