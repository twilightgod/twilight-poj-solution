/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Tree Summing
*       ID             : 1145
*       Date           : 5/15/2009
*       Time           : 22:14:17
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

struct Node
{
	Node *lc,*rc;
	int v;
	Node()
	{
		v=0;
		lc=rc=NULL;
	}
};

Node* root;
int n;
bool found;

void BuildTree(Node *&T)
{
	char ch;
	//(
	cin>>ch;
	cin>>ch;
	if(ch!=')')
	{
		cin.putback(ch);
		T=new Node();
		cin>>T->v;
		BuildTree(T->lc);
		BuildTree(T->rc);
		//)
		cin>>ch;
	}
}

void DFS(Node *T,int s)
{
	if(T)
	{
		if(T->lc==NULL&&T->rc==NULL)
		{
			if(s+T->v==n)
			{
				found=true;
			}
			return;
		}
		DFS(T->lc,s+T->v);
		if(found)
		{
			return;
		}
		DFS(T->rc,s+T->v);
		if(found)
		{
			return;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1145.txt","r",stdin);
#endif
	while(cin>>n)
	{
		BuildTree(root);
		found=false;
		DFS(root,0);
		if(found)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	return 0;
}
