#include <iostream>
using namespace std;

int main()
{
	int c,ci,n,i,sum,nn;
	double avg,rate;
	int a[1000];
	cin>>c;
	for(ci=0;ci<c;++ci)
	{
		cin>>n;
		sum=0;
		for(i=0;i<n;++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		avg=sum/n;
		nn=0;
		for(i=0;i<n;++i)
		{
			if (a[i]>avg)
			{
				nn++;
			}
		}
		printf("%.3f",nn*100.0/n);
		cout<<"%\n";

	}
	return 0;
}