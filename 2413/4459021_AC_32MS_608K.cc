#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int Base=100000000;
const int Capacity=100;


struct BigInt{
    int Len;
    int Data[Capacity];
    BigInt() : Len(0) {}
    BigInt (const BigInt &V) : Len(V.Len) { memcpy (Data, V.Data, Len*sizeof*Data);}
    BigInt(int V) : Len(0) {for(;V>0;V/=Base) Data[Len++]=V%Base;}
    BigInt &operator=(const BigInt &V) {Len=V.Len; memcpy(Data, V.Data, Len*sizeof*Data); return *this;}
    int &operator[] (int Index) {return Data[Index];}
    int operator[] (int Index) const {return Data[Index];}
};

int compare(const BigInt &A, const BigInt &B){
    if(A.Len!=B.Len) return A.Len>B.Len ? 1:-1;
    int i;
    for(i=A.Len-1;i>=0 && A[i]==B[i];i--);
    if(i<0)return 0;
    return A[i]>B[i] ? 1:-1;
}

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

istream &operator>>(istream &In,BigInt &V){
    char Ch;
    for(V=0;In>>Ch;){
        V=V*10+BigInt(Ch-'0');
        if(In.peek()<=' ') break;
    }
    return In;
}

ostream &operator<<(ostream &Out,const BigInt &V){
    int i;
    Out<<(V.Len==0 ? 0:V[V.Len-1]);
    for(i=V.Len-2;i>=0;i--) for(int j=Base/10;j>0;j/=10) Out<<V[i]/j%10;
    return Out;
}

BigInt f[479];

int lower_bound(BigInt& a,bool &e)
{
        int l=0,r=478,mid,res;
        while(l<=r)
        {
                mid=(l+r)>>1;
                res=compare(f[mid],a);
                if(res==0)
                {
                        e=true;
                        return mid;
                }
                else if(res==1)
                {
                        r=mid-1;
                }
                else
                {
                        l=mid+1;
                }
        }
        e=false;
        return l;
}

int main()
{
//      ifstream cin("d:\\input.txt");
//      ofstream cout("d:\\output1.txt");
        int count=3,i;
        f[0].Len=1;
        f[0].Data[0]=1;
        f[1].Len=1;
        f[1].Data[0]=2;

        //cout<<f[1]<<endl<<f[2]<<endl;
        for(i=2;i<479;++i)
        {
                f[i]=f[i-1]+f[i-2];
//              cout<<f[i]<<endl;
        }

        BigInt x,y;
        bool e1,e2;
        int lx,ly,res;
        while((cin>>x>>y)&&((compare(x,BigInt(0))!=0)||(compare(y,BigInt(0))!=0)))
        {
                lx=lower_bound(x,e1);
                ly=lower_bound(y,e2);
                res=ly-lx;
                if(e1&&e2||!e1&&e2)
                {
                        res++;
                }
                cout<<res<<endl;


        }

        return 0;
}