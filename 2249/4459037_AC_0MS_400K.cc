#include<iostream>
using namespace std;

int m,n,i;
double res,c1,c2;

int main()
{
        //freopen("d:\\input.txt","r",stdin);
        //freopen("d:\\output.txt","w",stdout);
        while(scanf("%d %d",&m,&n)&&!(m==0&&n==0))
        {

                if(n<(m>>1))
                {
                        n=m-n;
                }
                c1=m;
                c2=m-n;
                res=1;
                for (i=m;i>=n+1;--i)
                {
                        res*=c1/c2;
                        c1--;
                        c2--;
                }
                printf("%.0f\n",res);

        }
        return 0;
}