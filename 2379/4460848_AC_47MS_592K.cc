#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 1001
#define MAXP 21

struct Submission
{
	int c,p,t,r;
};

struct Team
{
	int ac,time,no;
	int subs[MAXP];
	bool IsAC[MAXP];
};

bool cmpSub(Submission a,Submission b)
{
	return a.t<b.t;
}

bool cmpTeam(Team a,Team b)
{
	if (a.ac==b.ac)
	{
		if (a.time==b.time)
		{
			return a.no<b.no;
		}
		else
		{
			return a.time<b.time; 
		}
	}
	else
	{
		return a.ac>b.ac;
	}
}

int C,N;
Team team[MAXN];
Submission sub[MAXN];

int main()
{	
	//freopen("in_2379.txt","r",stdin);
	while (cin>>C>>N)
	{
		for (int i=1;i<=C;++i)
		{
			team[i].ac=0;
			team[i].time=0;
			memset(team[i].IsAC,false,sizeof(team[i].IsAC));
			team[i].no=i;
			memset(team[i].subs,0,sizeof(team[i].subs));
		}
		for (int i=0;i<N;++i)
		{
			cin>>sub[i].c>>sub[i].p>>sub[i].t>>sub[i].r;
		}
		sort(sub,sub+N,cmpSub);
		for(int i=0;i<N;++i)
		{
			if(!team[sub[i].c].IsAC[sub[i].p])
			{
				if (sub[i].r)
				{
					team[sub[i].c].IsAC[sub[i].p]=true;
					team[sub[i].c].ac++;
					team[sub[i].c].time+=sub[i].t+team[sub[i].c].subs[sub[i].p]*20*60;
				} 
				else
				{
					team[sub[i].c].subs[sub[i].p]++;
				}
			}
		}
		sort(team+1,team+C+1,cmpTeam);
		for (int i=1;i<=C;++i)
		{
			if(i>1)
			{
				cout<<' ';
			}
			cout<<team[i].no;
		}
		cout<<endl;
	}
	return 0;
}
