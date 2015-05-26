#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 1500

int main()
{
        //ifstream cin("d:\\B.1.dat");
        //ifstream cin("d:\\input.txt");
        int a[MAXN];
        int i,j,n,m,t,test,times,total;
        cin>>test;
        while (test--)
        {
                cin>>n>>t>>m;
                for (i=0;i<m;++i)
                {
                        cin>>a[i];
                }
                times=ceil((double)m/n);
                sort(a,a+m);
                total=0;
                if(m%n==0)
                {
                        for(i=1;i<=times;++i)
                        {
                                if(a[i*n-1]>total)
                                {
                                        total=a[i*n-1];
                                }
                                total+=2*t;
                        }
                }
                else
                {
                        total=a[m%n-1]+t*2;
                        for(i=1;i<=times-1;++i)
                        {
                                if(a[i*n+m%n-1]>total)
                                {
                                        total=a[i*n+m%n-1];
                                }
                                total+=2*t;
                        }
                }
                cout<<total-t<<' '<<times<<endl;
        }
        return 0;
}