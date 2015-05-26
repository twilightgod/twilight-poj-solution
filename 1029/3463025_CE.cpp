#include <iostream.h> 
int n,k; 
int p[100]; 
char b[100]; 
int left[100][500]; 
int right[100][500]; 
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
            cin>>left[i][j]; 
        for ( j=0; j<p[i]; j++) 
            cin>>right[i][j]; 
        cin>>b[i]; 
    } 
    for ( int a=1; a<=n; a++) { 
        for ( int q=0; q<2; q++) { 
            flag = true; 
            for ( int i=0; i<k; i++) { 
                if ( b[i]=='=' ) 
                    if ( isIn(left[i],p[i],a) || isIn(right[i],p[i],a) ) { 
                        flag = false; break; } 
                if ( b[i]=='<' ) 
                    if ( !(isIn(left[i],p[i],a) && q==0) && !(isIn(right[i],p[i],a) && q==1) ) { 
                        flag = false; break; } 
                if ( b[i]=='>' ) 
                    if ( !(isIn(left[i],p[i],a) && q==1) && !(isIn(right[i],p[i],a) && q==0) ) { 
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
