#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int reverse(int a)
{
        int b=0;
        while(a)
        {
                b=10*b+(a%10);
                a/=10;
        }
        return b;
}

int main()
{
        //ifstream cin("e:\\in.txt");
        //ofstream cout("e:\\out.txt");

        string s1,s2,s3;
        int n,ni,i,j,k;

        cin>>n;
        for(ni=0;ni<n;++ni)
        {
                cin>>i>>j;
                cout<<reverse(reverse(i)+reverse(j))<<endl;
        }

        
        return 0;
}