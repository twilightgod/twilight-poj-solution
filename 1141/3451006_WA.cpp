#include<iostream>
#include<string>
using namespace std;
#define MAXN 300

int i,j,p,n,k;
string s;
int f[MAXN][MAXN];
int pos[MAXN][MAXN];

inline bool fit(int p1,int p2)
{
	return (s[p1]=='('&&s[p2]==')')||(s[p1]=='['&&s[p2]==']');
}

void print(int p1,int p2)
{
	if(p1==p2)
	{
		if(s[p1]==']'||s[p1]=='[')
		{
			cout<<"[]";
		}
		else
		{
			cout<<"()";
		}
		return;
	}
	if(p2-p1==1&&f[p1][p2]==0)
	{
		cout<<s[p1]<<s[p2];
		return;
	}
	if(pos[p1][p2]==-1)
	{
		cout<<s[p1];
		print(p1+1,p2-1);
		cout<<s[p2];
		return;
	}
	print(p1,pos[p1][p2]);
	print(pos[p1][p2]+1,p2);
}

int main()
{
//	freopen("d:/in.txt","r",stdin);
	while(getline(cin,s))
	{
		if(s=="")
		{
			cout<<endl;
			continue;
		}
		n=s.length();
		for(i=0;i<n;++i)
		{
			f[i][i]=1;
		}
		for(i=0;i<n-1;++i)
		{
			if(fit(i,i+1))
			{
				f[i][i+1]=0;
			}
			else
			{
				f[i][i+1]=2;
				pos[i][i+1]=i;
			}
		}
		for(p=2;p<n;++p)
		{
			for(i=0;i<n-p;++i)
			{
				j=i+p;
				if(fit(i,j))
				{
					f[i][j]=f[i+1][j-1];
					pos[i][j]=-1;
				}
				else
				{
					f[i][j]=200;
					for(k=i;k<j;++k)
					{
						if(f[i][k]+f[k+1][j]<f[i][j])
						{
							f[i][j]=f[i][k]+f[k+1][j];
							pos[i][j]=k;
						}
					}
				}
			}
		}
		//cout<<f[0][n-1]<<endl;
		print(0,n-1);
		cout<<endl;
	}
	return 0;
}