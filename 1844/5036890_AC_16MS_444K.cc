#include<iostream>
using namespace std;

int n;
int sum;

int GetSum()
{
		sum=0;
		for(int i=1;;++i)
		{
			sum+=i;
			if(sum==n||sum>n&&(sum-n)%2==0)
			{
				return i;
			}
		}
}

int main()
{
	while(cin>>n)
	{
		cout<<GetSum()<<endl;
	}
	return 0;
}
