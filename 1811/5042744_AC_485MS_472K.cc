#include  <iostream> 
#include  <cstdlib> 
#include  <ctime> 

using namespace std; 

const  int  times  =  20; 

int      count_factors  =  0; 
__int64  all_factors[100]; 
long     primes_count, primes[1229]; 

void     bulid_prime_table() 
{ 
    long  k, j, count, flag; 
     
    primes[0] = 2;   
    count = 1; 
     
    for (k = 3; k < 10000; k += 2) 
    { 
        flag = 1; 
         
        for (j = 0; j < count; ++j) 
        { 
            if (k % primes[j] == 0) 
            { 
                flag = 0; 
                break; 
            } 
        } 
         
        if ( flag == 1 ) 
        { 
            primes[count++] = k;  
        }            
    } 

    primes_count = count; 
}   
   
__int64 Multi_Modular( __int64 a, __int64 b, __int64 n) 
{ 
    __int64  back = 0, temp = a % n; 
     
    while ( b > 0 ) 
    { 
        if ( ((b >> 1) << 1) != b ) 
        { 
            if ( (back = back + temp) > n ) 
                 back -= n; 
        } 
         
        if ( (temp <<= 1) > n ) 
            temp -= n; 
             
        b >>= 1; 
    } 
     
    return   back; 
} 

__int64  Modular_Exponent(__int64  a, __int64  b, __int64  N) 
{ 
    __int64  d = 1; 
    __int64  t = a; 
     
    while (b > 0) 
    { 
        if ( ((b >> 1) << 1) != b ) 
        { 
            d = Multi_Modular(d, t, N); 
        } 
         
        b >>= 1; 
         
        t = Multi_Modular(t, t, N); 
    } 

    return  d;         
} 
     
int  Witness(__int64  a, __int64  N) 
{ 
    int      t = 0;     
    __int64  u = N - 1; 
     
    while ( ((u >> 1) << 1) == u ) 
    { 
        u >>= 1; 
        t++; 
    } 

    __int64  x_i; 
    __int64  x_i_1 = Modular_Exponent(a, u, N);    

    for (int i = 1; i <= t; ++i) 
    { 
        x_i = Multi_Modular(x_i_1 , x_i_1, N); 

        if ( x_i == 1 && x_i_1 != 1 && x_i_1 != N - 1 ) 
        { 
            return  1; 
        } 

        x_i_1 = x_i; 
    } 

    if ( x_i != 1 ) 
    { 
        return  1; 
    } 
    else 
    { 
        return  0; 
    }                 
    
} 

int  Miller_Rabin(__int64  N) 
{ 
    for (int k = 0; k < primes_count;  ++k) 
    { 
        if ( N == primes[k] ) 
        {   
            return  1; 
        } 
    } 
          
    if ( ((N >> 1) << 1) == N ) 
    {         
        return  0; 
    } 
     
    __int64  a; 
     
    for (int j = 0; j < times; ++j) 
    { 
        a = rand() % (N - 1) + 1; 

        if ( Witness(a, N) == 1 ) // 寻找N是合数的证明  
        { 
            return  0; 
        } 
    } 
     
    return  1;         
}    

__int64  gcd(__int64  a, __int64  b) 
{ 
    __int64  c; 
     
    while (b)  
    { 
        c  =  b; 
        b  =  a % b; 
        a  =  c; 
    } 
     
    return a; 
}     

__int64  Pollard_Rho(__int64  N) 
{ 
    __int64  d;     
    __int64  x = rand() % N; 
    __int64  y = x; 
     
    int  i = 1; 
    int  k = 2; 
     
    while (1) 
    { 
        i++; 
         
        x = Multi_Modular(x + 1, x - 1, N); 
         
        d = gcd(2 * N + y - x, N); 

        if ( d != 1 && d != N ) 
        { 
            return  d; 
        } 
            
        if ( i == k ) 
        { 
            y = x; 
            k += k; 
        } 
    }             
} 

void  Find_All_Factors(__int64  N) 
{     
    if ( Miller_Rabin(N) == 1 ) 
    { 
        all_factors[count_factors++] = N;  
    } 
    else 
    { 
        __int64  factor = Pollard_Rho(N); 

        Find_All_Factors(factor); 
        Find_All_Factors(N / factor); 
    }     
}   

__int64  Min_Factor(__int64  N) 
{ 
    for (int k = 0; k < primes_count;  ++k) 
    { 
        if ( N % primes[k] == 0 ) 
        {   
            return  primes[k]; 
        } 
    } 
             
    count_factors = 0; 
     
    Find_All_Factors(N); 
     
    __int64  min = all_factors[0]; 
     
    for (int k = 1; k < count_factors; ++k) 
    { 
        if ( all_factors[k] < min ) 
        { 
            min = all_factors[k]; 
        } 
    } 
     
    return  min; 
} 
   
int main() 
{ 
    int      T; 
    __int64  N; 
     
    srand( time(NULL) );  
     
    bulid_prime_table(); 
     
    cin >> T; 

    while(T--) 
    { 
        cin >> N; 

        if (Miller_Rabin(N)) 
        { 
            cout << "Prime" << endl; 
        } 
        else 
        { 
            cout << Min_Factor(N) << endl; 
        } 
    }     
     
    return  0; 
}    
