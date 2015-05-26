#include<iostream>
using namespace std;

#define MAXN 14

int ans[MAXN]={0,1,6,4,29,168,440,1871,7631,1739,93312,459900,1358656,2504880};
int n;

int main()
{
    while(cin>>n&&n) cout<<ans[n]<<endl;
    return 0;
}
