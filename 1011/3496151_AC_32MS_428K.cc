#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 100

int n,i,len,m,sum;
int s[MAXN];
bool used[MAXN];
bool found;

bool cmp(int x,int y)
{
	return x>y;
}

void dfs(int num,int cur,int next)
{
	if(num==m)
	{
		found=true;
		return;
	}
	int i;
	for(i=next;i<n;++i)
	{
		if(!used[i])
		{
			 if(s[i]+cur==len)
			{
				used[i]=true;
				dfs(num+1,0,0);
				if(found)
				{
					return;
				}
				used[i]=false;
				return;
			}			
			else if(s[i]+cur<len)
			{
				used[i]=true;
				dfs(num,s[i]+cur,i+1);
				if(found)
				{
					return;
				}
				used[i]=false;
				if(cur==0)
				{
					return;
				}
				while(i<n-1 && s[i]==s[i+1])                      ++i;
			}
			else if(cur==0)
			{
				return;
			}

		}

	}
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n&&n!=0)
	{
		sum=0;
		for(i=0;i<n;++i)
		{
			cin>>s[i];
			sum+=s[i];
		}
		sort(s,s+n,cmp);
		found=false;
		memset(used,false,sizeof(used));
		for(len=s[n-1];!found&&len<=sum;++len)
		{
			if(len!=0&&sum%len==0)
			{
				m=sum/len;
				dfs(0,0,0);
				if(found)
				{
					cout<<len<<endl;
				}
			}
		}
		
	}
	return 0;
}
