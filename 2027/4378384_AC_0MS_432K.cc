#include<iostream>
using namespace std;

int t;
int a,b;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<(a>=b?"MMM":"NO")<<" BRAINS\n";
	}
	return 0;
}
