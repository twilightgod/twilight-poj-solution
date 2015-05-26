#include<iostream>
using namespace std;
int main()
{
int test,m,n,i;

cin>>test;
i=0;
while(test--)
{
 scanf("%d%d",&m,&n);
 printf("Scenario #%d:\n",++i);
 if( (m*n)%2 == 0)
  printf("%d.00\n",m*n);
 else
  printf("%d.41\n",m*n);
 printf("\n");
}
return 0;

}
