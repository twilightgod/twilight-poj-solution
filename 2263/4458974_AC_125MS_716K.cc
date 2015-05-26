#include<iostream>
#include<fstream>
#include<map>
#include<string>

using namespace std;
#define MAXN 201
#define MAXINT 2147483647

int nv,n,ne,i,j,k,i1,i2,test;
map<string,int> m;
int w[MAXN][MAXN];
int dis[MAXN][MAXN];
string s1,s2;

inline int max(int x,int y)
{
        return x>y?x:y;
}

inline int min(int x,int y)
{
        return x<y?x:y;
}

inline int GetIndex(string s)
{
        map<string,int>::iterator it;
        it=m.find(s);
        if (it==m.end())
        {
                m.insert(make_pair(s,n));
                n++;
                return n-1;
        }
        else
        {
                return (*it).second;
        }
}

int main()
{
        //ifstream cin("d:\\input.txt");
        //ofstream cout("d:\\output.txt");
        test=0;
        while (cin>>nv>>ne&&(nv!=0||ne!=0))
        {
                n=0;
                test++;
                for (i=0;i<nv;++i)
                {
                        for (j=0;j<nv;++j)
                        {
                                dis[i][j]=MAXINT;
                        }
                }
                memset(w,-1,sizeof(w));
                m.clear();

                for (i=0;i<ne;++i)
                {
                        cin>>s1>>s2>>k;
                        i1=GetIndex(s1);
                        i2=GetIndex(s2);
                        w[i1][i2]=max(w[i1][i2],k);
                        w[i2][i1]=max(w[i2][i1],k);
                }

                for(i=0;i<nv;++i)
                {
                        for(j=0;j<nv;++j)
                        {
                                if(i==j)
                                {
                                        dis[i][j]=0;
                                }
                                else if(w[i][j]!=-1)
                                {
                                        dis[i][j]=w[i][j];
                                }
                        }
                }
for(k=0;k<nv;++k)
                for(i=0;i<nv;++i)
                        for(j=0;j<nv;++j)
                                
                                        if(dis[i][k]!=MAXINT&&dis[k][j]!=MAXINT&&i!=j)
                                        {
                                                if(i==0&&j==3&&k==2)
                                                {
                                                        bool b;
                                                        b=true;
                                                }
                                                if(dis[i][j]==MAXINT)
                                                {
                                                        dis[i][j]=min(dis[i][k],dis[k][j]);
                                                }
                                                else
                                                {
                                                        dis[i][j]=max(dis[i][j],min(dis[i][k],dis[k][j]));
                                                }
                                        }
                cin>>s1>>s2;
                i1=GetIndex(s1);
                i2=GetIndex(s2);
                cout<<"Scenario #"<<test<<endl;
                cout<<dis[i1][i2]<<" tons\n\n";
        }
                
        return 0;
}