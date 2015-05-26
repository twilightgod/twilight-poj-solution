#include<iostream>
using namespace std;

#define MAXN 0x10000
#define GOAL0 0
#define GOAL1 0x10000

int hash[MAXN];
int bin[16];
int i,h,t,init,cur,next;
int q[MAXN];
char c;
bool god;

int main()
{
	//freopen("in1753.txt","r",stdin);
	bin[0]=1;
	for(i=1;i<16;++i)
	{
		bin[i]=bin[i-1]<<1;
	}
	while(1)
	{
		memset(hash,-1,sizeof(hash));
		init=0;
		for(i=0;i<16;++i)
		{
			cin>>c;
			if(cin.eof()) return 0;
			//cout<<c;
			//if((i+1)%4==0) getchar();
			if(c=='w')
			{
				init+=bin[i];
			}
		}
		god=true;
		hash[init]=0;
		h=t=0;
		q[0]=init;
		while(h<=t)
		{
			cur=q[h++];
			if(cur==GOAL0||cur==GOAL1)
			{
				god=false;
				break;
			}
			for(i=0;i<16;++i)
			{
				next=cur;
				next^=bin[i];
				if(i-1>=0) next^=bin[i-1];
				if(i+1<16) next^=bin[i+1];
				if(i-4>=0) next^=bin[i-4];
				if(i+4<16) next^=bin[i+4];

				if(hash[next]==-1)
				{
					hash[next]=hash[cur]+1;
					q[++t]=next;
				}
			}
		}
		if(god)
		{
			cout<<"Impossible\n";
		}
		else if(hash[GOAL0]==-1)
		{
			cout<<hash[GOAL1]<<endl;
		}
		else
		{
			cout<<hash[GOAL0]<<endl;
		}
	}
	return 0;
}
