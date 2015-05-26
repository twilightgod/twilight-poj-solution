/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Skew Binary
*       ID             : 1362
*       Date           : 4/23/2009
*       Time           : 12:48:16
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<stack>
using namespace std;

#define MAXN 30

unsigned int w[MAXN];
stack<int> s;
int t,n;

int main()
{
	//freopen("in_1362.txt","r",stdin);
	for(int i=0;i<MAXN;++i)
	{
		w[i]=(1<<(i+1))-1;
		//cout<<w[i]<<endl;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<n;
		if(!n)
		{
			cout<<" []\n";
			continue;
		}
		for(int i=MAXN-1;i>=0;--i)
		{
			if(n>=w[i])
			{
				n-=w[i];
				s.push(i);
				if(n==w[i])
				{
					n-=w[i];
					s.push(i);
				}
			}
		}
		cout<<" [";
		cout<<s.top();
		s.pop();
		while(!s.empty())
		{
			cout<<','<<s.top();
			s.pop();
		}
		cout<<"]\n";
	}
	return 0;
}
