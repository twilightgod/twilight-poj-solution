#include<iostream>
using namespace std;

int n;
double d;

int main()
{
	//freopen("in_2239.txt","r",stdin);
	while(cin>>d&&d)
	{
		n=(int)d;
		for(int b=0x8000000;;b>>=1)
		{
			if(b&n)
			{
				n^=b;
				break;
			}
		}
		cout<<(n<<1)+1<<endl;
	}
	return 0;
}
