/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Specialized Four-Digit Numbers
*       ID             : 2196
*       Date           : 5/12/2009
*       Time           : 16:44:28
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

char str[10];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2196.txt","r",stdin);
#endif
	for(int i=2992;i<10000;++i)
	{
		int dec=0;
		sprintf(str,"%d",i);
		for(int j=0;j<4;++j)
		{
			dec+=str[j]-'0';
		}
		int hex=0;
		sprintf(str,"%4x",i);
		for(int j=0;j<4;++j)
		{
			if(str[j]!=' ')
			{
				if(str[j]<='9')
				{
					hex+=str[j]-'0';
				}
				else
				{
					hex+=str[j]-'a'+10;
				}
			}
		}
		int dx=0;
		int n=i;
		while(n)
		{
			dx+=n%12;
			n/=12;
		}
		
		if(dec==hex&&hex==dx)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
