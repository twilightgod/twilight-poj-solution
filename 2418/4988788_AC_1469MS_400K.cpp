/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Hardwood Species
*       ID             : 2418
*       Date           : 4/16/2009
*       Time           : 13:15:10
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<map>
using namespace std;

string str;
char ch[31];
map<string,int> m;
map<string,int>::iterator it;
int n;

int main()
{
	//freopen("in_2418.txt","r",stdin);
	n=0;
	while(1)
	{
		if(gets(ch)==NULL)
		{
			break;
		}
		str=ch;
		m[str]++;
		n++;
	}
	for(it=m.begin();it!=m.end();++it)
	{
		printf("%s %.4lf\n",(*it).first.c_str(),(double)(*it).second/n*100);
	}
	return 0;
}
