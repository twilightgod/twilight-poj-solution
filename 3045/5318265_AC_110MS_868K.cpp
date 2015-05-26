#include"iostream"
#include"cstdlib"
#include"stdio.h"
using namespace std;

struct W{
	int w,s,m;
};

int cmp(const void *a,const void *b){
	if(((W*)a)->m == ((W*)b)->m){
		return ((W*)a)->w-((W*)b)->w;
	}
	return ((W*)a)->m-((W*)b)->m;
	
}

int main(){
	int N;
	W k[50000];
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&k[i].w,&k[i].s);
		k[i].m=k[i].w+k[i].s;
	}
	qsort(k,N,sizeof(k[0]),cmp);
	int max=-k[0].s;
	int m0=k[0].w;


	for(int i=1;i<N;i++){
		if(m0-k[i].s>max)max=m0-k[i].s;
		m0+=k[i].w;
	}
	cout<<max<<endl;
	return 0;
}
