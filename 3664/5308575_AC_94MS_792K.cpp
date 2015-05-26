#include<algorithm>
#include<iostream>
using namespace std;

#define MAXN 50000

struct Cow
{
	int a;
	int b;
	int index;
};

bool cmp1(Cow x,Cow y)
{
	return x.a>y.a;
}

bool cmp2(Cow x,Cow y)
{
	return x.b<y.b;
}

Cow c[MAXN];
int n,k;

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&c[i].a,&c[i].b);
		c[i].index=i+1;
	}
	sort(c,c+n,cmp1);
	Cow *winner=max_element(c,c+k,cmp2);
	printf("%d\n",winner->index);
	return 0;
}
