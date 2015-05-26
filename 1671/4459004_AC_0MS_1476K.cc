#include<iostream>
using namespace std;
#define MAXN 51

const int Base=100000;
const int Capacity=100;

struct BigInt{
    int Len;
    int Data[Capacity];
    BigInt():Len(0){}
    BigInt(const BigInt &V):Len(V.Len){memcpy(Data,V.Data,Len*sizeof*Data);}
    BigInt(int V):Len(0){for(;V>0;V/=Base) Data[Len++]=V%Base;}
    BigInt &operator=(const BigInt &V){Len=V.Len;memcpy(Data,V.Data,Len*sizeof*Data);return *this;}
    int &operator[](int Index){return Data[Index];}
    int operator[](int Index)const{return Data[Index];}
};

BigInt operator+(const BigInt &A,const BigInt &B){
    int i,Carry(0);
    BigInt R;
    for(i=0;i<A.Len||i<B.Len||Carry>0;i++){
        if(i<A.Len) Carry+=A[i];
        if(i<B.Len) Carry+=B[i];;
        R[i]=Carry%Base;
        Carry/=Base;
    }
    R.Len=i;
    return R;
}

BigInt operator*(const BigInt &A,const int &B){
    int i;
    int Carry(0);
    BigInt R;
    for(i=0;i<A.Len||Carry>0;i++){
        if(i<A.Len) Carry+=int(A[i])*B;
        R[i]=Carry%Base;
        Carry/=Base;
    }
    R.Len=i;
    return R;
}

ostream &operator<<(ostream &Out,const BigInt &V){
    int i;
    Out<<(V.Len==0 ? 0:V[V.Len-1]);
    for(i=V.Len-2;i>=0;i--) for(int j=Base/10;j>0;j/=10) Out<<V[i]/j%10;
    return Out;
}

BigInt p[MAXN][MAXN];
int i,j,n;

int main()
{
        p[1][0].Len=1;
        p[1][0][0]=0;
        p[1][1].Len=1;
        p[1][1][0]=1;
        for (i=2;i<=MAXN-1;++i)
        {
                for (j=1;j<=MAXN-1;++j)
                {
                        p[i][j]=p[i-1][j]*j+p[i-1][j-1];
                }
        }

        

        while(cin>>n&&n!=0)
        {
                BigInt sum(0);
                for(i=1;i<=n;++i)
                {
                        sum=sum+p[n][i];
                }
                cout<<n<<' '<<sum<<endl;
        }
        return 0;
}