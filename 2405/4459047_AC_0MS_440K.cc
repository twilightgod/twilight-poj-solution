#include<iostream>
#include<math.h>
using namespace std;

int main()
{
        int d,v;
        while(cin>>d>>v&&d!=0&&v!=0)
        {
                printf("%.3f\n",pow(d*d*d-6/3.1415926*v,1.0/3));
        }
        return 0;
}