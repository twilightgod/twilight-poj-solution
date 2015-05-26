#include<iostream>
#include<string>
using namespace std;

string src;
int len;

int main()
{
	//freopen("in_2271.txt","r",stdin);
	//freopen("out_2271.txt","w",stdout);
	len=0;
	while(cin>>src)
	{
		if (src=="<br>")
		{
			cout<<endl;
			len=0;
		}
		else if(src=="<hr>")
		{
			if (len!=0)
			{
				cout<<endl;
			}
			cout<<"--------------------------------------------------------------------------------\n";
			len=0;
		}
		else
		{
			if (len+src.length()>80)
			{
				cout<<endl<<src<<' ';
				len=src.length()+1;
			}
			else
			{
				cout<<src<<' ';
				len+=src.length()+1;
			}
		}
	}
	return 0;
}
