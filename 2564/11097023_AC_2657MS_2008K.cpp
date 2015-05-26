#include<map>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

map<string, int> f;
int ans;

void UpdateBest(string& str, int& best)
{
	if(f.find(str)!=f.end())
	{
		best=max(best,f[str]);
	}
}

int TryAllStep(string& str)
{
	int best=0;
	string tmp;

	//modify index i
	for(int i=0;i<str.size();++i)
	{
		for(char x='a';x<str[i];++x)
		{
			tmp=str;
			tmp[i]=x;
			UpdateBest(tmp, best);
		}
	}

	//insert before index i
	for(int i=0;i<str.size();++i)
	{
		for(int x='a';x<=str[i];++x)
		{
			tmp=str;
			tmp.insert(i,1,x);
			UpdateBest(tmp, best);
		}
	}

	//delete index i
	for(int i=0;i<str.size();++i)
	{
		tmp=str;
		tmp.erase(i,1);
		UpdateBest(tmp, best);
	}

	return best;
}

int main()
{
#ifndef ONLINE_JUDGE 
	freopen("in.txt", "r", stdin);
#endif
	ans=0;
	while (!cin.eof())
	{
		string str;
		cin>>str;
		f[str]=TryAllStep(str)+1;
		ans=max(ans,f[str]);
	}
	cout<<ans<<endl;
}
