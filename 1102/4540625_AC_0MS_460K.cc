/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : LC-Display
*       ID             : 1102
*       Date           : 1/7/2009
*       Time           : 23:23:50
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

#define MAXN 10
int n;
string str;
char mo[MAXN+1][MAXN][2*MAXN+3][MAXN+2];

int main()
{
//	freopen("in_1102.txt","r",stdin);
	memset(mo,' ',sizeof(mo));
	for (int s=1;s<=10;++s)
	{
		int h=2*s+3,w=s+2;
		for (int m=0;m<=9;++m)
		{
			if (m==4||m==5||m==6||m==8||m==9||m==0)
			{
				for (int i=1;i<h/2;++i)
				{
					mo[s][m][i][0]='|';
				}		
			}
			if (m==2||m==6||m==8||m==0)
			{
				for (int i=1;i<h/2;++i)
				{
					mo[s][m][i+s+1][0]='|';
				}		
			}
			if (m==1||m==2||m==3||m==4||m==7||m==8||m==9||m==0)
			{
				for (int i=1;i<h/2;++i)
				{
					mo[s][m][i][w-1]='|';
				}		
			}
			if (m==1||m==3||m==4||m==5||m==6||m==7||m==8||m==9||m==0)
			{
				for (int i=1;i<h/2;++i)
				{
					mo[s][m][i+s+1][w-1]='|';
				}		
			}
			if (m==2||m==3||m==5||m==6||m==7||m==8||m==9||m==0)
			{
				for (int j=1;j<=s;++j)
				{
					mo[s][m][0][j]='-';
				}
			}
			if (m==2||m==3||m==4||m==5||m==6||m==8||m==9)
			{
				for (int j=1;j<=s;++j)
				{
					mo[s][m][s+1][j]='-';
				}
			}
			if (m==2||m==3||m==5||m==6||m==8||m==9||m==0)
			{
				for (int j=1;j<=s;++j)
				{
					mo[s][m][h-1][j]='-';
				}
			}
		}
	}
	while (cin>>n&&n)
	{
		cin>>str;
		for (int i=0;i<2*n+3;++i,cout<<endl)
		{
			for (int k=0;k<str.length();++k)
			{
				if (k)
				{
					cout<<' ';
				}
				for (int j=0;j<n+2;++j)
				{
					cout<<mo[n][str[k]-'0'][i][j];
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
