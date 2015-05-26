#include<stdio.h>
#include<string.h>
int n,o,z,x;
bool god;
char*c,b[11];
struct N
{
	bool e;
	int p[10];
}a[70001];
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
				for(c=b;*c;c++)
				{
					int&t=a[o].p[*c-'0'];
					if(!t){t=++n;memset(a+n,0,sizeof(N));}
					o=t;
					if(a[o].e){god=true;goto l;}
				}
				for(int i=0;i<10;++i)
				{
					if(a[o].p[i])
					{
						god=true;goto l;
					}
				}
				a[o].e=true;
			}
		}
l:		if(x>0) while(x--) gets(b);
		puts(god?"NO":"YES");
	}
	return 0;
}
