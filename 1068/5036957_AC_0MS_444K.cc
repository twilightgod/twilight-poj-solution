#include<iostream>
using namespace std;

#define MAXN 50

int n,t,k,count1,sum;
bool s[MAXN];
int p[MAXN],pos[MAXN];

int main()
{
	//freopen("in_1068.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>p[i];
		}
		p[0]=0;
		k=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<p[i]-p[i-1];++j)
			{
				s[k++]=false;
			}
			pos[i]=k;
			s[k++]=true;
		}
		for(int i=1;i<=n;++i)
		{
			count1=0;
			sum=0;
			for(int j=pos[i];;--j)
			{
				if(s[j])
				{
					sum++;
					count1++;
				}
				else
				{
					sum--;
				}
				if(sum==0)
				{
					cout<<count1<<' ';
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}