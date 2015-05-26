#include<iostream>
#include<fstream>
using namespace std;

int main()
{
        //ifstream cin("e:\\in.txt");
        //ofstream cout("e:\\out.txt");
        int i,j;
        while(cin>>i>>j)
        {
                if(i==0&&j==0)
                {
                        break;
                }
                if(i<j)
                {
                        swap(i,j);
                }
                if(i==j)
                {
                        cout<<"Stan wins"<<endl;
                        continue;
                }
                int time=0,k,d;
                while(1)
                {
                        k=i%j;
                        d=i/j;
                        if(k==0||d>1)
                        {
                                break;
                        }
                        time++;
                        i=j;
                        j=k;
                }
                if(time%2==0)
                {
                        cout<<"Stan wins"<<endl;
                }
                else
                {
                        cout<<"Ollie wins"<<endl;
                }
        }
        return 0;
}