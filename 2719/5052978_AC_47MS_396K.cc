/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Faulty Odometer
*       ID             : 2719
*       Date           : 4/27/2009
*       Time           : 8:7:32
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

char s[11];
int n;

int main()
{
	//freopen("in_2719.txt","r",stdin);
	while(scanf("%s",&s))
	{
		if(s[0]=='0')
		{
			break;
		}
		printf("%s: ",s);
		for(int i=0;i<strlen(s);++i)
		{
			if(s[i]>'4')
			{
				s[i]--;
			}
		}
		n=strtol(s,NULL,9);
		printf("%d\n",n);
	}
	return 0;
}
