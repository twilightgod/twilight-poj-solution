/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : IP Address
*       ID             : 2105
*       Date           : 12/5/2008
*       Time           : 22:40:30
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

int n,sum;
const int bin[8]={128,64,32,16,8,4,2,1};
string s;

int main()
{
	//freopen("in_2105.txt","r",stdin);
	cin>>n;
	while (n--)
	{
		cin>>s;
		for (int i=0;i<4;++i)
		{
			sum=0;
			for (int j=0;j<8;++j)
			{
				sum+=s[i*8+j]=='1'?bin[j]:0;
			}
			if (i!=0)
			{
				cout<<'.';
			}
			cout<<sum;
		}
		cout<<endl;
	}
	return 0;
}
