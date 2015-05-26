#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int t,step,i;
string his[18];
string s;
int c[10];
stringstream ss;
bool found;

int main()
{
	//freopen("e:/in.txt","r",stdin);
	//freopen("e:/out.txt","w",stdout);
	cin>>t;
	while(t--)
	{
		while(cin>>s&&s!="-1")
		{
			found=false;
			his[0]=s;
			step=0;
			while(1)
			{
				step++;
				memset(c,0,sizeof(c));
				s=his[step-1];
				for(i=0;i<s.length();++i)
				{
					c[s[i]-48]++;
				}
				ss.clear();
				for(i=0;i<10;++i)
				{
					if(c[i]!=0)
					{
						ss<<c[i]<<i;
					}
				}
				ss>>s;
				if(his[0]==s)
				{
					if(step==1)
					{
						cout<<his[0]<<" is self-inventorying\n";
						found=true;
					}
				}
				else if(his[step-1]==s)
				{	cout<<his[0]<<" is self-inventorying after "<<step-1<<" steps\n";
					found=true;
				}
				else
				for(i=step-1;i>=0;--i)
				{
					if(his[i]==s)
					{
											cout<<his[0]<<" enters an inventory loop of length "<<step-i<<endl;
					
						found=true;
					break;
					}
				}
				if(found)
				{
					break;
				}
				his[step]=s;
				if(step==15)
				{
					break;
				}
			}
			if(!found)
			{
				cout<<his[0]<<" can not be classified after 15 iterations\n";
			}
		}
		if(t!=0)
		{
			getline(cin,s);
			
		}cout<<endl;
	}
	return 0;
}