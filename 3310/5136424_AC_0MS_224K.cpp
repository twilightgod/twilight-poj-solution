#include<iostream>
#include<vector>
using namespace std;
 
#define MAXN 101
 
//bool mat[MAXN][MAXN];
vector<int> l[MAXN];
int dr[MAXN];
bool vis[MAXN];
int n,m,ans,s,ca;
 
int main()
{
	//freopen("in.txt","r",stdin);
	ca=0;
	while(/*cin>>n&&n*/scanf("%d",&n)&&n)
	{
		//cin>>m;
		scanf("%d",&m);
		//memset(mat,false,sizeof(mat));
		for(int i=1;i<=n;++i)
		{
			l[i].clear();
		}
		memset(dr,0,sizeof(dr));
		memset(vis,false,sizeof(vis));
		while(m--)
		{
			int u,v;
			//cin>>u>>v;
			scanf("%d%d",&u,&v);
			dr[u]++;
			dr[v]++;
			//mat[u][v]=mat[v][u]=true;
			l[u].push_back(v);
			l[v].push_back(u);
			if(dr[v]==1)
			{
				s=v;
			}
		}
		ans=1;
		vis[s]=true;
		bool flag=true;
		while(flag)
		{
			flag=false;
			int e=-1,c=0;
			//for(int i=1;i<=n;++i)
			for(int j=0;j<l[s].size();++j)
			{
				int i=l[s][j];
				if(!vis[i])
				{
					flag=true;
					vis[i]=true;
					ans++;
					if(dr[i]!=1)
					{
						c++;
						e=i;
					}
				}
			}
			if(c>1)
			{
				ans=0;
				break;
			}
			if(ans==n)
			{
				break;
			}
			if(e==-1)
			{
				ans=0;
				break;
			}
			s=e;
		}
		//cout<<"Graph "<<++ca<<" is";
		printf("Graph %d is",++ca);
		if(ans==0)
		{
			//cout<<" not";
			printf(" not");
		}
		//cout<<" a caterpillar.\n";
		printf(" a caterpillar.\n");
	}
	return 0;
}