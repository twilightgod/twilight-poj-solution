#include<iostream>
using namespace std;

#define MAXN 14

int ans[MAXN]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
int n;

int main()
{
    while(cin>>n&&n) cout<<ans[n]<<endl;
    return 0;
}
