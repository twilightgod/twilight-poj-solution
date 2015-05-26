
#include <stdio.h>
int main()
{
double ct, pt;
scanf("%lf", &pt);
while(scanf("%lf", &ct)!=EOF && (int)ct!=999)
{
printf("%.2lf\n", ct-pt);
pt=ct;
}
puts("End of Output");
return 0;
}