#include<iostream>
using namespace std;

int i;
double sum,t;

int main()
{
	sum=0;
	for(i=0;i<12;++i)
	{
		cin>>t;
		sum+=t;
	}
	printf("$%.2lf\n",sum/12);
	return 0;
}
