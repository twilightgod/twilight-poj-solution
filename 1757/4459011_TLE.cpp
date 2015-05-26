#include<iostream>
#include<fstream>
using namespace std;

#define MAXN 10000

int A[MAXN],low[MAXN],high[MAXN];
int N,i,j,l,k,total,test;

bool BinarySearch(int x,int _i,int _l)
{
        int p, q, i, L;
        
        p = 0;   /* Left border of the search  */
        q = N-1; /* Right border of the search */
        L = 0;   /* Comparison counter         */
        while (p <= q) {
                i = (p + q) / 2;
                ++L;
                if (A[i] == x) {
                        if(i==_i&&L==_l)
                        {
                                return true;
                        }
                        else
                        {
                                return false;
                        }
                }
                if (x < A[i])
                        q = i - 1;
                else
                        p = i + 1;
        }
        return false;
}

int main()
{
        //ifstream cin("d:\\input.txt");
        //ofstream cout("d:\\output.txt");
        for(i=0;i<MAXN;++i)
        {
                A[i]=i;
        }

        cin>>test;
        while(test--)
        {
                memset(low,-1,sizeof(low));
                memset(high,-1,sizeof(high));
                cin>>i>>l;
                total=0;
                for(N=1;N<=MAXN;++N)
                {
                        if(BinarySearch(i,i,l))
                        {
                                if(low[total]==-1)
                                {
                                        low[total]=N;
                                }
                                else
                                {
                                        high[total]=N;
                                }
                        }
                        else
                        {
                                if(low[total]!=-1)
                                {
                                        if(high[total]==-1)
                                        {
                                                high[total]=N-1;
                                        }
                                        total++;
                                }
                        }
                }
                if(low[total]!=-1)
                {
                        high[total]=MAXN;
                        total++;
                }
                cout<<total<<endl;
                for(i=0;i<total;++i)
                {
                        cout<<low[i]<<' '<<high[i]<<endl;
                }
                if(test!=0)
                {
                        cout<<endl;
                }
        }
        return 0;
}