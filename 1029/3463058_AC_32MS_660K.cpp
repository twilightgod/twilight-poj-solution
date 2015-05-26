#include <iostream> 
using namespace std;
int n,k; 
int p[100]; 
char b[100]; 
int left1[100][500]; 
int right1[100][500]; 
int found; 
int fa; 
bool flag; 
bool isIn(int* arr,int len,int a) { 
    for ( int i=0; i<len; i++) 
        if ( arr[i]==a ) 
            return true; 
    return false; 
} 
int main() { 
    cin>>n>>k; 
    found = 0; 
    for ( int i=0; i<k; i++) { 
        cin>>p[i]; 
        for ( int j=0; j<p[i]; j++) 
            cin>>left1[i][j]; 
        for ( int j=0; j<p[i]; j++) 
            cin>>right1[i][j]; 
        cin>>b[i]; 
    } 
    for ( int a=1; a<=n; a++) { 
        for ( int q=0; q<2; q++) { 
            flag = true; 
            for ( int i=0; i<k; i++) { 
                if ( b[i]=='=' ) 
                    if ( isIn(left1[i],p[i],a) || isIn(right1[i],p[i],a) ) { 
                        flag = false; break; } 
                if ( b[i]=='<' ) 
                    if ( !(isIn(left1[i],p[i],a) && q==0) && !(isIn(right1[i],p[i],a) && q==1) ) { 
                        flag = false; break; } 
                if ( b[i]=='>' ) 
                    if ( !(isIn(left1[i],p[i],a) && q==1) && !(isIn(right1[i],p[i],a) && q==0) ) { 
                        flag = false; break; } 
            } 
            if ( flag ) { 
                if ( fa!=a ) { 
                    found++; 
                    fa = a; 
                } 
            } 
        } 
    } 
    if ( found!=1 ) cout<<'0'; 
    if ( found==1 ) cout<<fa; 
    return 0; 
} 
