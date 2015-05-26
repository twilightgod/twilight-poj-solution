/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Ranking List
*       ID             : 1918
*       Date           : 12/19/2008
*       Time           : 23:27:56
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

#define MAXT 20
#define MAXP 11

struct Team
{
	int time,AC,rank;
	bool IsAC[MAXP];
	int subs[MAXP];
	string name;
};

Team team[MAXT];
int test,n,k,m;
map<string,int> hash;

inline bool cmp(Team a,Team b)
{
	if (a.AC==b.AC)
	{
		if (a.time==b.time)
		{
			return a.name<b.name;
		}
		else
		{
			return a.time<b.time;
		}
	}
	else
	{
		return a.AC>b.AC;
	}
}

int main()
{
	//freopen("in_1918.txt","r",stdin);
	//freopen("out_1918.txt","w",stdout);
	cin>>test;
	while (test--)
	{
		cin>>n;
		hash.clear();
		for (int i=0;i<n;++i)
		{
			cin>>team[i].name;
			team[i].AC=team[i].time=0;
			memset(team[i].IsAC,false,sizeof(team[i].IsAC));
			memset(team[i].subs,0,sizeof(team[i].subs));
			hash[team[i].name]=i;
		}
		cin>>k>>m;
		for (int i=0;i<m;++i)
		{
			int p,t,no;
			string res,te;
			cin>>p>>t>>res>>te;
			no=hash[te];
			if (!team[no].IsAC[p])
			{
				if (res=="Yes")
				{
					team[no].IsAC[p]=true;
					team[no].time+=team[no].subs[p]*20+t;
					team[no].AC++;
				}
				else
				{
					team[no].subs[p]++;
				}
			}
		}
		sort(team,team+n,cmp);
		team[0].rank=1;
		for (int i=1;i<n;++i)
		{
			if(team[i].AC==team[i-1].AC&&team[i].time==team[i-1].time)
			{
				team[i].rank=team[i-1].rank;
			}
			else
			{
				team[i].rank=i+1;
			}
		}
		for (int i=0;i<n;++i)
		{
			cout<<setw(2)<<team[i].rank<<". "<<team[i].name;
			for (int j=0;j<8-team[i].name.length();++j)
			{
				cout<<' ';
			}
			cout<<' '<<team[i].AC<<' '<<setw(4)<<team[i].time<<endl;
		}
		cout<<endl;
	}
	return 0;
}
