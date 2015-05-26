/*  
ID: twentsk1  
PROG: ditch  
LANG: C++  
*/  
#include <iostream>   
using namespace std;   
#define DES n   
#define N n   
#define VS 1001   
#define ES 2000   
#define inf 1000000   
int pre[ES];   
int tail[VS];   
int len[ES];   
int to[ES];   
int op[ES];   
int es=0;   
  
int h[VS];   
int vh[VS];   
int map[VS][VS];   
int n,m;   
int init()   
{   
    es=0;   
    memset(pre,255,sizeof(pre));   
    memset(tail,255,sizeof(tail));   
}   
  
int addedge(int x,int y,int w)   
{   
    pre[++es]=tail[x];   
    tail[x]=es;   
    len[es]=w;   
    to[es]=y;   
    return es;   
}   
void add2edge(int x,int y,int w)   
{   
    int o=addedge(x,y,w);   
    int p=addedge(y,x,0);   
    op[o]=p;   
    op[p]=o;   
}   
int aug(int u,int t)   
{   
    if (u==DES)return t;   
    int l=t,d;   
    int minh=N-1;   
    for (int p=tail[u];p>0;p=pre[p])   
    {   
        if (len[p]>0)   
        {   
            if (h[to[p]]+1==h[u])   
            {   
                d=aug(to[p],l<len[p]?l:len[p]);   
                len[p]-=d;   
                len[op[p]]+=d;   
                l-=d;   
                if (h[1]>=N)return t-l;   
                if (l==0)break;   
            }   
            if (h[to[p]]<minh)minh=h[to[p]];   
        }   
           
    }   
    if (l==t)   
    {   
        vh[h[u]]--;   
        if (vh[h[u]]==0)h[1]=N;   
        h[u]=minh+1;   
        vh[h[u]]++;   
    }   
    return t-l;   
}   
int maxflow()   
{   
    memset(h,0,sizeof(h));   
    memset(vh,0,sizeof(vh));     
    vh[0]=N;   
    int ans=0;   
    while (h[1]<N)   
    {   
        ans+=aug(1,inf);   
    }   
    return ans;   
}   
int input()   
{   
    memset(map,0,sizeof(map));   
        for (int i=1;i<=m;i++)   
        {   
            int x,y,w;   
            cin>>x>>y>>w;   
            add2edge(x,y,w);   
        }   
  
}   
int main(int argc, char**argv) {   
    
    while(cin>>m>>n)   
    {   
        init();   
        input();   
        cout<<maxflow()<<endl;   
    }   
    return 0;   
}  
