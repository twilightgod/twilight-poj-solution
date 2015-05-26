#include<iostream>
#include<string>
using namespace std;
#define MAXC 10
#define MAXP 101
#define MAXT 100001

int cn,pn,i,j,k,t,ans;
bool f[MAXT];
int ti[MAXC][MAXP];
string c[MAXC];
int num[MAXC];
int sum[MAXC];
string s;

inline int GetC(string s)
{
	int i;
	for(i=0;i<cn;++i)
	{
		if(c[i]==s)
		{
			return i;
		}
	}
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>cn>>pn&&cn+pn)
	{
		memset(num,0,sizeof(num));
		for(i=0;i<cn;++i)
		{
			cin>>c[i];
		}
		for(i=0;i<pn;++i)
		{
			cin>>j;
			cin>>s;
			t=GetC(s);
			ti[t][num[t]++]=j;
			sum[t]+=j;
		}
		ans=0;
		for(k=0;k<cn;++k)
		{
			memset(f,0,sizeof(f));
			f[0]=true;
			for(i=0;i<num[k];++i)
			{
				for(j=sum[k]>>1;j>=0;--j)
				{
					if(j-ti[k][i]<0)
					{
						break;
					}
					f[j]|=f[j-ti[k][i]];
				}
			}
			for(i=sum[k]>>1;i>=0;--i)
			{
				if(f[i])
				{
					break;
				}
			}
			ans+=sum[k]-i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
