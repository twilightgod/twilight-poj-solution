#include<iostream>
using namespace std;

int a[6];
int sum,i,zero,test;
bool found;

void dfs(int dep,int total)
{
	if(total==sum)
	{
		found=true;
		return;
	}
	if(dep==6)
	{
		return;
	}
	int i;
	for(i=0;!found&&i<=a[dep];++i)
	{
		dfs(dep+1,total+i*(dep+1));
	}
}

int main()
{
	test=0;
	while(1)
	{
		test++;
		zero=0;
		sum=0;
		for(i=0;i<6;++i)
		{
			cin>>a[i];
			if(a[i]==0)
			{
				zero++;
			}
			if(a[i]>=12)
			{
				a[i]%=12;
			}
			sum+=a[i]*(i+1);
		}
		if(zero==6)
		{
			break;
		}
		cout<<"Collection #"<<test<<":\n";
		if(sum%2!=0)
		{
			cout<<"Can't be divided.\n\n";
		}
		else
		{
			sum>>=1;
			found=false;
			dfs(0,0);
			if(found)
			{
				cout<<"Can be divided.\n\n";
			}
			else
			{
				cout<<"Can't be divided.\n\n";
			}
		}
	}
}
