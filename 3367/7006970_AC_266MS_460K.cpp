#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

#define MAXN 10000

struct Node
{
	int l,r;
};

int t;
string s;
Node nodes[MAXN];
stack<int> ans;
stack<int> tree;
queue<int> q;

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		while(ans.size())
		{
			ans.pop();
		}
		while(tree.size())
		{
			tree.pop();
		}
		while(q.size())
		{
			q.pop();
		}
		memset(nodes,-1,sizeof(nodes));

		cin>>s;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]<='Z')
			{
				int a=tree.top();
				tree.pop();
				int b=tree.top();
				tree.pop();
				nodes[i].r=a;
				nodes[i].l=b;
			}
			tree.push(i);
		}

		q.push(s.length()-1);
		while(q.size())
		{
			int now=q.front();
			q.pop();
			ans.push(now);
			if(nodes[now].l!=-1)
			{
				q.push(nodes[now].l);
			}
			if(nodes[now].r!=-1)
			{
				q.push(nodes[now].r);
			}
		}

		for(int i=0;i<s.length();++i)
		{
			cout<<s[ans.top()];
			ans.pop();
		}
		cout<<endl;
	}
	return 0;
}
