#include<iostream>
#include<string>
using namespace std;
#define MAXN 1000
#define MAXM 1000000
#define MAXL 200000

int i,j,n,ph,pt,k,t,test;
int se[MAXM];
int qu[MAXN][MAXN];
int head[MAXN];
int tail[MAXN];
int s2p[MAXN];
int p2s[MAXL];
string s;

int main()
{
	//freopen("e:/in.txt","r",stdin);
	test=0;
	while(cin>>n&&n!=0)
	{
		test++;
		cout<<"Scenario #"<<test<<'\n';
		for(i=0;i<n;++i)
		{
			cin>>k;
			for(j=0;j<k;++j)
			{
				cin>>t;
				se[t]=i;
			}
		}
		memset(head,0,sizeof(head));
		memset(tail,-1,sizeof(tail));
		memset(s2p,0,sizeof(s2p));
		ph=1;
		pt=0;
		while(1)
		{
			cin>>s;
			if(s=="STOP")
			{
				break;
			}
			if(s=="ENQUEUE")
			{
				cin>>t;
				int ss=se[t];
				int pp=s2p[ss];
				if(pp<ph)
				{
					pt++;
					s2p[ss]=pt;
					tail[ss]=(tail[ss]+1)%MAXN;
					qu[ss][tail[ss]]=t;
					p2s[pt]=ss;
				}
				else
				{
					tail[ss]=(tail[ss]+1)%MAXN;
					qu[ss][tail[ss]]=t;
				}
			}
			else
			{
				int ss=p2s[ph];
				cout<<qu[ss][head[ss]]<<endl;
				head[ss]=(head[ss]+1)%MAXN;
				if(head[ss]>tail[ss])
				{
					ph++;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}