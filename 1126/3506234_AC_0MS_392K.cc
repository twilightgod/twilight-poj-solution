#include<iostream>
#include<string>
using namespace std;

int i,c;
string s;
bool legal;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while (cin>>s)
	{
		c=0;
		legal=true;
		for (i=s.length()-1;i>=0;--i)
		{
			if (s[i]>='p'&&s[i]<='z')
			{
				c++;
			}
			else if (s[i]=='N')
			{
				if (c==0)
				{
					legal=false;
					break;
				}
			}
			else if (s[i]=='C'||s[i]=='D'||s[i]=='E'||s[i]=='I')
			{
				if (c<2)
				{
					legal=false;
					break;
				}
				c--;
			}
			else
			{
				legal=false;
				break;
			}
		}
		if (legal&&c==1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}
