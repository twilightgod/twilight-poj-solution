/*
ID: dd.ener1
PROG: ditch
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

const int maxn=1024,OO=1000000000;
struct edge{
	int x,y;//两个顶点 
	int c;//容量 
	int f;
	edge *next,*back;
	edge(){}
	edge(int x,int y,int c,edge* next):x(x),y(y),c(c),f(0),next(next),back(0){}
	void* operator new(size_t, void *p){
		return p;
	}
}*E[maxn];
int N,S,T;

int Q[maxn];
int D[maxn];
void DFS()
{
    memset(D,-1,sizeof(D));
    int head=0,tail=0;
    Q[tail++]=S;
    D[S]=0;
    for(;;){
        int i=Q[head++];
        for(edge* e=E[i];e;e=e->next){
            if(e->c==0)continue;
            int j=e->y;
            if(D[j]==-1){
                D[j]=D[i]+1;
                Q[tail++]=j;
                if(j==T)return;
            }
        }
        if(head==tail)break;
    }
}
edge* cur[maxn];
edge* path[maxn];
int flow()
{
    int res=0;
    int path_n;
    for(;;){
        DFS();
        if(D[T]==-1)break;
        memcpy(cur,E,sizeof(E));
        path_n=0;
        int i=S;
        for(;;){
            if(i==T){
                int mink=0;
                int delta=INT_MAX;
                for(int k=0;k<path_n;++k){
                    if(path[k]->c < delta){
                        delta = path[k]->c;
                        mink=k;
                    }
                }
                for(int k=0;k<path_n;++k){
                    path[k]->c -= delta;
                    path[k]->back->c += delta;
                }
                path_n=mink;
                i=path[path_n]->x;
                res+=delta;
            }
            edge* e;
            for(e=cur[i];e;e=e->next){
                if(e->c==0)continue;
                int j=e->y;
                if(D[i]+1==D[j])break;
            }
            cur[i]=e;
            if(e){
                path[path_n++]=e;
                i=e->y;
            }
            else{
                D[i]=-1;
                if(path_n==0)break;
                path_n--;
                i=path[path_n]->x;
            }
        }
    }
    return res;
}
void input(){
	int m;
	scanf("%d%d",&m,&N);
	memset(E,0,sizeof(E));
	edge* data=new edge[2*m];
	while(m--){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		E[x]=new((void*)data++) edge(x,y,w,E[x]);
		E[y]=new((void*)data++) edge(y,x,0,E[y]);
		E[x]->back = E[y];
		E[y]->back = E[x];
	}
	S=1;
	T=N;
}
int main(){
	//freopen("ditch.in","r",stdin);
	//freopen("ditch.out","w",stdout);
	input();
	int res=flow();
	printf("%d\n",res);
}
