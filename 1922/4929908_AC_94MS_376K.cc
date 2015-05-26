#include<iostream>
#include<math.h>
using namespace std;

int n,v,s;
double best,t;

int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>n&&n)
	{
		best=1e20;
		for(int i=0;i<n;++i)
		{
			cin>>v>>s;
			if(s>=0)
			{
				t=4.5/((double)v/3600)+s;
				if(best>t)
				{
					best=t;
				}
			}
		}
		cout<<(int)ceil(best)<<endl;
	}
	return 0;
}

