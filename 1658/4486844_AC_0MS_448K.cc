#include<iostream>
using namespace std;

int a[5];
int c1,c2,test;

int main()
{
	//freopen("in_1658.txt","r",stdin);
	cin>>test;
	while(test--)
	{
		for(int i=0;i<4;++i)
		{
			cin>>a[i];
			cout<<a[i]<<' ';
		}
		c1=a[3]-a[2];
		c2=a[1]-a[0];
		if(c1==c2)
		{
			cout<<a[3]+c1<<endl;
		}
		else
		{
			cout<<a[3]/a[2]*a[3]<<endl;
		}
	}
	return 0;
}
