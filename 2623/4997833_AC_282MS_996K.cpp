#include<iostream>
#include<queue>
using namespace std;

priority_queue<unsigned int> pq;
int n;
double ans;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n/2+1;++i)
	{
		int t;
		scanf("%d",&t);
		pq.push(t);
	}
	for(int i=n/2+1;i<n;++i)
	{
		int t;
		scanf("%d",&t);
		pq.push(t);
		pq.pop();
	}
	ans=pq.top();
	if(n%2==0)
	{
		pq.pop();
		ans+=pq.top();
		ans/=2;
	}
	printf("%.1lf\n",ans);
	return 0;
}

