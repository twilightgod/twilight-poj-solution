#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int i,j,m,n,r;
string a[101],b[101],s;
int f[101][101];
bool last;

void print(ostream& os,int i,int j)
{
        if(i==0||j==0)
        {
                return;
        }
        if(a[i]==b[j])
        {
                if(last)
                {
                        last=false;
                        print(os,i-1,j-1);
                        os<<a[i]<<'\n';
                }
                else
                {
                        print(os,i-1,j-1);
                        os<<a[i]<<' ';
                }
        }
        else if(f[i][j-1]>f[i-1][j])
        {
                print(os,i,j-1);
        }
        else
        {
                print(os,i-1,j);
        }
}

int main()
{
        //ifstream cin("d:\\input.txt");
        //ofstream cout("d:\\output.txt");
        r=0;
        while(1)
        {
                if(cin.eof())
                {
                        break;
                }
                m=1;
                while(cin>>s)
                {
                        if(s=="#")
                        {
                                break;
                        }
                        else
                        {
                                a[m++]=s;
                        }
                }

                n=1;
                while(cin>>s)
                {
                        if(s=="#")
                        {
                                break;
                        }
                        else
                        {
                                b[n++]=s;
                        }
                }
                
                memset(f,0,sizeof(f));
                for(i=1;i<m;++i)
                {
                        for(j=1;j<n;++j)
                        {
                                if(a[i]==b[j])
                                {
                                        f[i][j]=f[i-1][j-1]+1;
                                }
                                else if(f[i][j-1]>f[i-1][j])
                                {
                                        f[i][j]=f[i][j-1];
                                }
                                else
                                {
                                        f[i][j]=f[i-1][j];
                                }
                        }
                }
                //cout<<f[m-1][n-1]<<endl;
                last=true;
                print(cout,m-1,n-1);

        }

        return 0;
}