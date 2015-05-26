#include<iostream>
using namespace std;

int main()
{
        int a,b,c,best,n,test;
        cin>>test;
        while(test--)
        {
                cin>>n;
                if(n==1)
                {
                        best=6;
                }
                else
                {
                best=2147483647;
                for(a=1;a<=n;++a)
                {
                        for(b=1;b<=n/2/a;++b)
                        {
                                if(n%(a*b)==0)
                                {
                                        c=n/(a*b);
                                        if(2*(a*b+a*c+b*c)<best)
                                        {
                                                best=2*(a*b+a*c+b*c);
                                        }
                                }

                        }
                }
                }
                cout<<best<<endl;
        }
        return 0;
}