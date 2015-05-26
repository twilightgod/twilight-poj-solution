#include"iostream"
#include"cstdlib"
using namespace std;
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(){
    int N,S,c=0;
    int ls[20000];
    cin>>N>>S;
    for(int i=0;i<N;i++){
         cin>>ls[i];
    }
    qsort(ls,N,sizeof(ls[0]),cmp);
    int i,j=0;
    for(i=N-1;i>=1;i--){
            if(ls[0]+ls[i]<=S)break;
    }
    c+=i-j;
    for(j=1;j<i;j++){
       for(;i>j;i--){
           if(ls[j]+ls[i]<=S){
              c+=i-j;
              break;
           }
       }
    }
     cout<<c<<endl;
    return 0;
} 

