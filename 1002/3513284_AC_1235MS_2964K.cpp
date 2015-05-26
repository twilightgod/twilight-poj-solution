#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define MAXN 100000

int i,j,n,t;
int pad[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
bool god;
char buf[1000];
string tel[MAXN];

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n)
	{
		for(i=0;i<n;++i)
		{
			scanf("%s",&buf);
			t=0;
			tel[i].resize(7);
			for(j=0;t<7&&j<strlen(buf);++j)
			{
				if(buf[j]!='-')
				{
					if(buf[j]>='A'&&buf[j]<='Z')
					{
						tel[i][t++]=pad[buf[j]-'A']+48;
					}
					else
					{
						tel[i][t++]=buf[j];
					}
				}
			}
		}
		god=true;
		sort(tel,tel+n);
		for(i=0;i<n;)
		{
			t=1;
			for(j=i+1;j<n&&tel[j]==tel[i];++j)
			{
				t++;
			}
			if(t>1)
			{
				god=false;
				printf("%c%c%c-%c%c%c%c %d\n",tel[i][0],tel[i][1],tel[i][2],
					tel[i][3],tel[i][4],tel[i][5],tel[i][6],t);
			}
			i=j;
		}
		if(god)
		{
			cout<<"No duplicates.\n";
		}
	}
	return 0;
}
