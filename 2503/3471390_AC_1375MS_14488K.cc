#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,string> m;
map<string,string>::iterator it;
char c[25];
int pos;
string s;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(1)
	{
		gets(c);
		s=c;
		if(s.length()==0)
		{
			break;
		}
		pos=s.find(' ');
		m[s.substr(pos+1,s.length()-pos-1)]=s.substr(0,pos);
	}
	while(1)
	{
		if(!gets(c))
		{
			break;
		}
		s=c;
		it=m.find(s);
		if(it==m.end())
		{
			printf("eh\n");
		}
		else
		{
			printf("%s\n",(*it).second.c_str());
		}
	}
	return 0;
}
