/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Biorhythms
*       ID             : 1006
*       Date           : 12/11/2008
*       Time           : 20:6:4
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int p,e,i,d,ca;

int main()
{
	//freopen("in_1006.txt","r",stdin);
	ca=0;
	while (cin>>p>>e>>i>>d)
	{
		if (p==-1&&e==-1&&i==-1&&d==-1)
		{
			break;
		}
		for (int k=d+1;;++k)
		{
			if ((k-p)%23==0&&(k-e)%28==0&&(k-i)%33==0)
			{
				printf("Case %d: the next triple peak occurs in %d days.\n",++ca,k-d);
				break;
			}
		}
	}
	return 0;
}
