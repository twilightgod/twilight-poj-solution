/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Phone numbers
*       ID             : 1732
*       Date           : 12/4/2008
*       Time           : 22:45:59
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//dp  O(s.length * n)
//f[i]=min{
//            f[i-dic[j].length()]+1   s.t.  i-len>=0&&s[i-len ... i]==dic[j]
//            +Inf
//        }
//u[i] remember the best choice
#include<iostream>
#include<string>
using namespace std;

#define MAXN 1010
#define MAXW 500010
#define MAXINT 0x7fffffff

const char CONVERSE[26] = {'2','2','2','3','3','3','4','4','1','1','5','5','6','6','0','7','0','7','7','8','8','8','9','9','9','0'};

int u[MAXN];
int f[MAXN];
string s;
string dic[MAXW];
string dico[MAXW];
int n;
bool first;

//check whether s[i-len ... i]==dic[j]
bool Fit(int i,int j)
{
	for (int k=i-1,l=dic[j].length()-1;l>=0;--k,--l)
	{
		if (dic[j][l]!=s[k])
		{
			return false;
		}
	}
	return true;
}

//print the words in best plan
void Print(int i)
{
	if (i==0)
	{
		return;
	}
	Print(i-dic[u[i]].length());
	if (!first)
	{
		cout<<' ';
	}
	else
	{
		first=false;
	}
	cout<<dico[u[i]];
}

int main()
{
	//freopen("in_1732.txt","r",stdin);
	while(cin>>s)
	{
		//input
		cin>>n;
		for (int i=0;i<n;++i)
		{
			cin>>dico[i];
			dic[i]=dico[i];
			//convert the letters to digits
			for (int j=0;j<dic[i].length();++j)
			{
				dic[i][j]=CONVERSE[dic[i][j]-'a'];
			}
		}
		//dp
		f[0]=0;
		for (int i=1;i<=s.length();++i)
		{
			f[i]=MAXINT;
			u[i]=-1;
			for (int j=0;j<n;++j)
			{
// 				int k=dic[j].length();
// 				if (i-k>=0)
				if (i-dic[j].length()>=0)
				{
					if (Fit(i,j))
					{
						if (f[i-dic[j].length()]+1<f[i])
						{
							f[i]=f[i-dic[j].length()]+1;
							u[i]=j;
						}
					}
				}
			}
		}
		//print answer
		if (f[s.length()]==MAXINT)
		{
			cout<<"No solution.\n";
		}
		else
		{
			first=true;
			Print(s.length());
			cout<<endl;
		}
	}
	return 0;
}
