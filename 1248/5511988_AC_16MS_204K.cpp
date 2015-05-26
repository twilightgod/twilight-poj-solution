#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

/*
v - w^2 + x^3 - y^4 + z^5 = target 
*/

int ta;
string str,ans;
bool used[15];
bool god;

void DFS(int dep,int s)
{
	if(dep==5)
	{
		if(s==ta)
		{
			god=false;
		}
		return;
	}
	for(int i=str.size()-1;i>=0;--i)
	{
		if(!used[i])
		{
			ans[dep]=str[i];
			used[i]=true;
			int ss=0;
			if(dep==0)
			{
				ss=str[i]-64;
			}
			if(dep==1)
			{
				ss=-(str[i]-64)*(str[i]-64);
			}
			if(dep==2)
			{
				ss=(str[i]-64)*(str[i]-64)*(str[i]-64);
			}
			if(dep==3)
			{
				ss=-(str[i]-64)*(str[i]-64)*(str[i]-64)*(str[i]-64);
			}
			if(dep==4)
			{
				ss=(str[i]-64)*(str[i]-64)*(str[i]-64)*(str[i]-64)*(str[i]-64);
			}
			DFS(dep+1,s+ss);
			if(!god)
			{
				return;
			}
			used[i]=false;
		}
	}
}

int main()
{
	//freopen("in_ccsa.txt","r",stdin);
	while(1)
	{
		cin>>ta>>str;
		if(ta==0&&str=="END")
		{
			break;
		}
		sort(str.begin(),str.end());
		ans.clear();
		ans.resize(5);
		god=true;
		memset(used,false,sizeof(used));
		DFS(0,0);
		if(god)
		{
			cout<<"no solution"<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
	return 0;
}
