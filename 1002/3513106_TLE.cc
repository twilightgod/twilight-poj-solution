#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int i,j,n,t;
map<string,int> m;
map<string,int>::iterator it;
string s;
stringstream ss;
int pad[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
bool god;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n)
	{
		m.clear();
		for(i=0;i<n;++i)
		{
			cin>>s;
			ss.clear();
			t=0;
			for(j=0;j<s.length();++j)
			{
				if(s[j]!='-')
				{
					if(s[j]>='A'&&s[j]<='Z')
					{
						ss<<pad[s[j]-'A'];
						t++;
					}
					else
					{
						ss<<s[j];
						t++;
					}
				}
				if(t==3)
				{
					ss<<'-';
					t=-100;
				}
			}
			ss>>s;
			m[s]++;
		}
		god=true;
		for(it=m.begin();it!=m.end();++it)
		{
			t=(*it).second;
			if(t>1)
			{
				god=false;
				cout<<(*it).first<<' '<<t<<endl;
			}
		}
		if(god)
		{
			cout<<"No duplicates.\n";
		}
	}
	return 0;
}
