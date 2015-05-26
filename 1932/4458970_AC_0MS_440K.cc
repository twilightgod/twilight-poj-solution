#include <iostream>
#include <fstream>
using namespace std;

#define MAXINT 2147483647
#define MAXE 10201
#define MAXV 101

struct Node
{
        int v,next;
};

int nv,ne,i,j,k,ei,times,temp,v;
bool relax;

int w[MAXV];
int dis[MAXV];
int lastup[MAXV];
Node ge[MAXE];
int gv[MAXV];

int main()
{

        while(scanf("%d",&nv)!=EOF&&nv!=-1)
        {
                //input
                memset(gv,0xff,sizeof(int)*(nv+1));
                memset(lastup,0,sizeof(int)*(nv+1));
                ne=-1;
                for(i=1;i<=nv;++i)
                {
                        scanf("%d %d",&w[i],&ei);
                        w[i]*=-1;
                        for(j=0;j<ei;++j)
                        {
                                scanf("%d",&k);
                                ne++;
                                ge[ne].v=k;
                                ge[ne].next=gv[i];
                                gv[i]=ne;
                        }
                }
                //bellman-ford
                for(i=1;i<=nv;++i)
                        dis[i]=MAXINT;
                dis[1]=-100;
                for(times=1;;times++)
                {
                        relax=false;
                        for(i=1;i<=nv-1;++i)
                        {
                                if(dis[i]<0)
                                {
                                        temp=gv[i];
                                        while(temp!=-1)
                                        {
                                                v=ge[temp].v;
                                                if(dis[i]+w[i]<0&&dis[v]>dis[i]+w[i])
                                                {
                                                        dis[v]=dis[i]+w[i];
                                                        lastup[v]=times;
                                                        relax=true;
                                                }
                                                temp=ge[temp].next;
                                        }
                                }
                        }
                        //done
                        if(relax==false||dis[nv]<0)
                        {
                                break;
                        }
                        //cycle
                        if(times==nv-1)
                        {
                                for(i=1;i<=nv;++i)
                                {
                                        if(lastup[i]!=nv-1)
                                        {
                                                dis[i]=MAXINT;  
                                        }
                                }
                                memset(w,0,sizeof(int)*(nv+1));
                        }
                }
                //output
                if(dis[nv]<0)
                {
                        printf("winnable\n");
                }
                else
                {
                        printf("hopeless\n");
                }
        }
        return 0;
}