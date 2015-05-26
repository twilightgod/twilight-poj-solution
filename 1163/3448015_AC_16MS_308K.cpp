#include<iostream>
using namespace std;

int i,n,j;
int a[101][101];

int main()
{
	while (cin>>n)
	{
		for (i=0;i<n;++i)
		{
			for (j=0;j<i+1;++j)
			{
				cin>>a[i][j];
			}
		}
		for (i=n-2;i>=0;--i)
		{
			for (j=0;j<i+1;++j)
			{
				if (a[i+1][j]>a[i+1][j+1])
				{
					a[i][j]+=a[i+1][j];
				}
				else
				{
					a[i][j]+=a[i+1][j+1];
				}
			}
		}
		cout<<a[0][0]<<endl;
	}
	return 0;
}