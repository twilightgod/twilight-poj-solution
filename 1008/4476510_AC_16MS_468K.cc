/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Maya Calendar
*       ID             : 1008
*       Date           : 12/11/2008
*       Time           : 19:35:29
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string H[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
string T[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int n,y1,y2,y,d1,d2,d,m1,m2;
string s;

int GetHMonth(string str)
{
	for (int i=0;i<19;++i)
	{
		if (str==H[i])
		{
			return i;
		}
	}
}

int main()
{
	//freopen("in_1008.txt","r",stdin);
	cin>>n;
	cout<<n<<endl;
	while(n--)
	{
		cin>>d1;
		getchar();
		cin>>s>>y1;
		d=y1*365+d1+GetHMonth(s)*20;
		y2=d/260;
		d2=d%260;
		m2=d2%20;
		d2=d2%13+1;
		cout<<d2<<' '<<T[m2]<<' '<<y2<<endl;
	}
	return 0;
}
