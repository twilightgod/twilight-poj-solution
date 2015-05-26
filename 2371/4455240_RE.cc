#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAXN 5000

int a[MAXN];
int n,k;
string s;

int main()
{
	//freopen("in_2371.txt","r",stdin);
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		getchar();
		getline(cin,s);
		cin>>k;
		for(int i=0;i<k;++i)
		{
			int q;
			cin>>q;
			cout<<a[q-1]<<endl;
		}
	}
	return 0;
}
