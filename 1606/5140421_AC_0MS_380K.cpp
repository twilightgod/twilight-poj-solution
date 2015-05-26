/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Jugs
*       ID             : 1606
*       Date           : 5/12/2009
*       Time           : 17:18:41
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 101

struct status
{
	int v[2];
	status(int _la,int _lb)
	{
		v[0]=_la;
		v[1]=_lb;
	}
	status(){}
};

struct oper
{
	int t,op1,op2;
	status s;
};

int vol[3];
int d[MAXN][MAXN];
oper o[MAXN][MAXN];
queue<status> q;
bool god;
status last;

inline int* GetD(status &sta)
{
	return &d[sta.v[0]][sta.v[1]];
}

inline oper* GetO(status &sta)
{
	return &o[sta.v[0]][sta.v[1]];
}

inline bool AddNode(status &next,status &cur)
{
	if (*GetD(next)!=-1)
	{
		return false;
	}
	*GetD(next)=*GetD(cur)+1;
	q.push(next);
	return true;
}

bool Check(status &sta)
{
	for (int i=0;i<2;++i)
	{
		if (sta.v[i]==vol[2])
		{
			return true;
		}
	}
	return false;
}

void Print(status sta)
{
	if (sta.v[0]==0&&sta.v[1]==0)
	{
		return;
	}
	oper op=*GetO(sta);
	Print(op.s);
	switch (op.t)
	{
	case 1:cout<<"fill "<<char(op.op1+'A')<<"\n";break;
	case 2:cout<<"empty "<<char(op.op1+'A')<<"\n";break;
	case 3:cout<<"pour "<<char(op.op1+'A')<<' '<<char(op.op2+'A')<<"\n";break;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1606.txt","r",stdin);
#endif
	while (cin>>vol[0]>>vol[1]>>vol[2])
	{
		memset(d,-1,sizeof(d));
		d[0][0]=0;
		while (!q.empty())
		{
			q.pop();
		}
		god=true;
		q.push(status(0,0));
		while (!q.empty())
		{
			status cur=q.front(),next;
			q.pop();
			if (Check(cur))
			{
				last=cur;
				god=false;
				break;
			}
			//Fill
			for (int i=0;i<2;++i)
			{
				if (cur.v[i]<vol[i])
				{
					next=cur;
					next.v[i]=vol[i];
					if(AddNode(next,cur))
					{
						(*GetO(next)).t=1;
						(*GetO(next)).op1=i;
						(*GetO(next)).s=cur;
					}
				}
			}
			//Drop
			for (int i=0;i<2;++i)
			{
				if (cur.v[i]>0)
				{
					next=cur;
					next.v[i]=0;
					if(AddNode(next,cur))
					{
						(*GetO(next)).t=2;
						(*GetO(next)).op1=i;
						(*GetO(next)).s=cur;
					}
				}
			}
			//Pour
			for (int i=0;i<2;++i)
			{
				for (int j=0;j<2;++j)
				{
					if (i!=j&&cur.v[i]>0&&cur.v[j]<vol[j])
					{
						next=cur;
						if (cur.v[i]>vol[j]-cur.v[j])
						{
							next.v[j]=vol[j];
							next.v[i]-=vol[j]-cur.v[j];
						}
						else
						{
							next.v[i]=0;
							next.v[j]+=cur.v[i];
						}
						if(AddNode(next,cur))
						{
							(*GetO(next)).t=3;
							(*GetO(next)).op1=i;
							(*GetO(next)).op2=j;
							(*GetO(next)).s=cur;
						}
					}
				}
			}
		}//end of BFS
		if (god)
		{
			cout<<"impossible\n";
		}
		else
		{
			//cout<<*GetD(last)<<endl;
			Print(last);
			cout<<"success\n";
		}
	}
	return 0;
}
