/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Number-guessing Game
*       ID             : 3589
*       Date           : 5/8/2009
*       Time           : 12:14:39
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string s1,s2;
int a,b,t;

int main()
{
	//freopen("in_3589.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2;
		a=b=0;
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j)
			{
				if(s1[i]==s2[j])
				{
					if(i==j)
					{
						a++;
					}
					else
					{
						b++;
					}
				}
			}
		}
		cout<<a<<'A'<<b<<"B\n";
	}
	return 0;
}
