#include"iostream"
using namespace std;
int pri[2300]={2,3,5};
int isp(int a){
	for(int i=0;i<5000;i++){
		if(a%pri[i]==0)return 0;
		if(pri[i]*pri[i]>a)break;
	}
	return 1;
}
int main(){
	int k=3;
	
	for(int i=7;i<20000;i++){
		if(isp(i))pri[k++]=i;
	}
	int N,M[5000],max=0,ma=0,p;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>M[i];
		int h=M[i];
		for(int j=0;j<2300;j++){
			while(h%pri[j]==0){
				h/=pri[j];
			}
			if(h==1){
				if(pri[j]>max)max=pri[j];
				break;
			}
		}
		if(max>ma){ma=max;p=i;}
	}
	cout<<M[p]<<endl;
	return 0;
}
