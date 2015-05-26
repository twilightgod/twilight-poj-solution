#include<iostream>
#include<string>
using namespace std;
#define MAXN 20

int count[MAXN];
int from[MAXN];
string pname[MAXN];
string cname[MAXN];
string s1,s2;
int n,m,i,p,pn,cc,pi;
char t[85];

int GetPos(string s)
{
	if(s=="independent")
	{
		return pn++;
	}
	int i;
	for(i=0;i<pn;++i)
	{
		if(s==pname[i])
		{
			return i;
		}
	}
	return pn++;
}

int GetPos2(string s)
{
	int i;
	for(i=0;i<n;++i)
	{
		if(s==cname[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n)
	{
		pn=0;
		getline(cin,s1);
		memset(count,0,sizeof(count));
		for(i=0;i<n;++i)
		{
			getline(cin,s1);
			cname[i]=s1;
			getline(cin,s2);
			p=GetPos(s2);
			from[i]=p;
			pname[p]=s2;
		}
		cin>>m;
		getline(cin,s1);
		for(i=0;i<m;++i)
		{
			gets(t);
			//scanf("%s",&t);
			s1=t;
			p=GetPos2(s1);
			if(p!=-1)
			{
				count[from[p]]++;
			}
		}
		p=-100;
		for(i=0;i<pn;++i)
		{
			if(p<count[i])
			{
				p=count[i];
				pi=i;
			}
		}
		cc=0;
		for(i=0;i<pn;++i)
		{
			if(p==count[i])
			{
				cc++;
			}
		}
		if(cc==1)
		{
			cout<<pname[pi]<<endl;
		}
		else
		{
			cout<<"tie\n";
		}
	}
	return 0;
}
