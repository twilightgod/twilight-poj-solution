/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Word Amalgamation
*       ID             : 1318
*       Date           : 12/1/2008
*       Time           : 21:35:48
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//STL 嵌套map
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

typedef map<string,int> map_s_i;
typedef map<string,map_s_i> map_s_m;
typedef map_s_m::iterator it_s_m;
typedef map_s_i::iterator it_s_i;

map_s_m dic;
string s,sp;
it_s_m it_dic;

bool cmp(char a,char b)
{
	return a<b;
}

int main()
{
	//freopen("in_1318.txt","r",stdin);
	dic.clear();
	while (1)
	{
		getline(cin,s);
		if (s=="XXXXXX")
		{
			break;
		}
		sp=s;
		sort(sp.begin(),sp.end());
		it_dic=dic.find(sp);
		if (it_dic==dic.end())
		{
			map_s_i wordlist;
			wordlist[s]=0;
			dic[sp]=wordlist;
		}
		else
		{
			(it_dic->second)[s]=0;
		}
	}
	while (1)
	{
		getline(cin,s);
		if (s=="XXXXXX")
		{
			break;
		}
		sp=s;
		sort(sp.begin(),sp.end());
		it_dic=dic.find(sp);
		if (it_dic==dic.end())
		{
			cout<<"NOT A VALID WORD\n";
		}
		else
		{
			for (it_s_i it_wordlist=(it_dic->second).begin();it_wordlist!=(it_dic->second).end();++it_wordlist)
			{
				cout<<it_wordlist->first<<endl;
			}
		}
		cout<<"******\n";
	}
	return 0;
}
