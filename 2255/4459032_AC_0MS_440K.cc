#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void work(ostream& cout,string &s1,string &s2)
{
        if(s1.length()==0)
        {
                return;
        }
        if(s1.length()==1)
        {
                cout<<s1[0];
                return;
        }
        int p1;
        string l1,r1,l2,r2;
        p1=s2.find(s1[0]);
        l1=s1.substr(1,p1);
        l2=s1.substr(p1+1,s2.length()-p1-1);
        r1=s2.substr(0,p1);
        r2=s2.substr(p1+1,s2.length()-p1-1);
        work(cout,l1,r1);
        work(cout,l2,r2);
        cout<<s1[0];
}
int main()
{
        //ifstream cin("e:\\in.txt");
        //ofstream cout("e:\\out.txt");
        string s1,s2;
        while(cin>>s1>>s2)
        {
                work(cout,s1,s2);
                cout<<endl;
        }
        return 0;
}