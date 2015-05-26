#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 1000

int n,i,len,m,sum;
int s[MAXN];
bool used[MAXN];
bool found;

void dfs(int num,int cur,int next)
{
	if(num==m)
	{
		found=true;
		return;
	}
	for(int i=next;!found&&i<n;++i)
	{
		if(!used[i])
		{
			if(s[i]+cur<len)
			{
				used[i]=true;
				dfs(num,s[i]+cur,i+1);
				used[i]=false;
				if(cur==0)
				{
					return;
				}
			}
			else if(s[i]+cur==len)
			{
				used[i]=true;
				dfs(num+1,0,0);
				used[i]=false;
				return;
			}
			else
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
		sort(s,s+n);
		found=false;
		memset(used,false,sizeof(used));
		for(len=s[n-1];!found&&len<=sum;++len)
		{
			if(sum%len==0)
			{
				m=sum/len;
				dfs(0,0,0);
			}
		}
		cout<<len-1<<endl;
	}
	return 0;
}
