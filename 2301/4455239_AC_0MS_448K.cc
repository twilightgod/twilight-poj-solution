#include<iostream>
using namespace std;

int a,b,x,y,t;

int main()
{
	//freopen("in_2301.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		if((x+y)%2||x-y<0||(x-y)%2)
		{
			cout<<"impossible\n";
		}
		else
		{
			cout<<((x+y)>>1)<<' '<<((x-y)>>1)<<endl;
		}
	}
	return 0;
}
