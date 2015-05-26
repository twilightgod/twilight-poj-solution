#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
	int n,i;
	string cmd;
	bool newgame=true;
	set<int> s;
	while (cin>>n&&n!=0)
	{
		if (newgame==true)
		{
			s.clear();
			for(i=1;i<=10;++i)
			{
				s.insert(i);
			}
		}
		getline(cin,cmd);
		getline(cin,cmd);
		if (cmd=="too high")
		{
			newgame=false;
			for(i=n;i<=10;++i)
			{
				s.erase(i);
			}
		}
		else if (cmd=="too low")
		{
			newgame=false;
			for (i=1;i<=n;++i)
			{
				s.erase(i);
			}
		}
		else
		{
			newgame=true;
			if (s.find(n)==s.end())
			{
				cout<<"Stan is dishonest\n";
			}
			else
			{
				cout<<"Stan may be honest\n";
			}
		}
	}
	return 0;
}