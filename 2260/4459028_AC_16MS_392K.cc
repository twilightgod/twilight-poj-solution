#include<iostream>
using namespace std;
#define MAXN 101

int sc[MAXN],sr[MAXN];
int i,j,n,c,isc,isr,nsc,nsr;

int main()
{
        while(scanf("%d",&n)&&n!=0)
        {
                memset(sc,0,sizeof(sc));
                memset(sr,0,sizeof(sr));
                for (i=1;i<=n;++i)
                {
                        for (j=1;j<=n;++j)
                        {
                                scanf("%d",&c);
                                if (c==1)
                                {
                                        sc[j]++;
                                        sr[i]++;
                                }
                        }
                }
                nsc=nsr=0;
                for(i=1;i<=n;++i)
                {
                        if (sc[i]%2!=0)
                        {
                                nsc++;
                                isc=i;
                        }
                        if (sr[i]%2!=0)
                        {
                                nsr++;
                                isr=i;
                        }
                }
                if (nsr==0&&nsc==0)
                {
                        printf("OK\n");
                }
                else if(nsr==1&&nsc==1)
                {
                        printf("Change bit (%d,%d)\n",isr,isc);
                }
                else
                {
                        printf("Corrupt\n");
                }
        }

        return 0;
}