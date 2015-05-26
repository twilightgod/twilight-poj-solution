#include<stdio.h>
#include<string.h>
int n,o,z,x;
bool god;
char b[11];
struct N
{
	int p[26];
}a[100001];
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d\n",&z);
	while(z--)
	{
		scanf("%d\n",&x);
		n=0;
		god=false;
		memset(a,0,sizeof(N));
		while(x--)
		{
			gets(b);
			{
				o=0;
				int len=strlen(b);
				for(int i=0;i<len;++i)
				{
					int&t=a[o].p[b[i]-'a'];
					if(i==len-1&&t){god=true;goto l;}
					if(!t){t=++n;memset(a+n,0,sizeof(N));o=t;}
				}
			}
		}
l:		if(x>=0) while(x--) gets(b);
		puts(god?"NO":"YES");
	}
	return 0;
}
