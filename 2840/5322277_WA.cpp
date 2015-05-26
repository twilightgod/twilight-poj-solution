#include<iostream>
#include<string>
using namespace std;

int t;
int n;
string ttt;

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>n;		
		getline(cin,ttt);
		if(ttt!=":00")
		{
			cout<<0<<endl;
			continue;
		}
		cout<<((n+12)%24)<<endl;
	}
	return 0;
}
