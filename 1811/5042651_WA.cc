/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Prime Test
*       ID             : 1811
*       Date           : 4/24/2009
*       Time           : 22:46:1
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

long long n;
int t;

long long BitLength(long long x)
{
	long long d = 0;
	while (x > 0) {
		x >>= 1;
		d++;
	}
	return d;
}

long long BitAt(long long x, long long i)
{
	return ( x & (1 << (i-1)) );
}

long long Modular_Expoent(long long a,long long b,long long n)
{
	long long i, y=1;
	for(i = BitLength(b); i > 0; i--)
	{ 
		y = (y*y)%n;
		if(BitAt(b,i) > 0)
			y = (y*a)%n;
	}
	return y;
}

long long gcd(long long a,long long b)
{
	while(b)
	{
		long long t=a;
		a=b;
		b=t%b;
	}
	return a;
}

long long Gen_rand(long long range_min,long long range_max)
{
	return (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
		+ range_min;
}


long long Mul64(long long a,long long b,long long c)
{
	if(b<10)
	{
		return (a*b)%c;
	}
	return ((Mul64(a,b/2,c)*2)%c+a*(b%2))%c;
}

/*
int Witness(long long a,long long n)
{
long long i,x0,x1;
x0=a;
for(i = (long long)ceil(log((double)n-1)/log(2.0))-1; i >= 0; i--)
{
//x1=Modular_Expoent(x0,2,n);
x1=Mul64(x0,x0,n);
if(x1==1&&x0!=1&&x0!=n-1)
{
return true;
}
x0=x1;
}
return (x1==1?0:1);  
}
*/

int Witness(long long a,long long n)
{
	long long i,d=1,x;
	for(i = (long long)ceil(log((double)n-1)/log(2.0))-1; i >= 0; i--)
	{
		x=d,  d=Mul64(d,d,n);/*(d*d)%n;*/
		if ((d==1)&&(x!=1)&&(x!=n-1)) 
			return 1;
		if (((n-1)&(1<<i))>0) 
			d=Mul64(d,a,n);/*(d*a)%n;*/
	}
	return (d==1?0:1);  
}

long long  Miller_Rabin(long long n,long long s)
{
	long long j,a;
	for(j = 0; j < s; j++)
	{
		//a = rand()*(n-2) / RAND_MAX + 1;
		a=Gen_rand(1,n-1);
		if(Witness(a,n)) 
			return 0;
	}
	return 1;  
}

__int64 PollardRho (const __int64 &test)
{
	__int64 y,x,x2,Gcd;
	int i,k;
	const __int64 &c=rand() % (test - 1) + 1;
	y = x =x2= rand () % test;
	i = 1;
	k = 2;
	do
	{
		i++;
		if(i>200000)
		{
			return -1;
		}
		Gcd = gcd (2 * test + y - x,test);
		if (Gcd > 1 && Gcd < test)
		{
			return Gcd;
		}
		if (i == k)
		{
			y = x;
			k *= 2;
		}
		//x = (x * x + test - c) % test;
		//x=(Modular_Expoent(x,2,test) + c)%test;
		x=(Mul64(x,x,test)+c)%test;
	}while (x != y);

	return test;
}

/*
long long Pollard_rho(long long n)
{
srand(time(NULL));
long long i=1;
long long x=43;//Gen_rand(0,n-1);
long long y=x;
long long k=2;
while(1)
{
i++;
x=(x*x-1)%n;
long long d=gcd(y>=x?y-x:x-y,n);
if(d!=1&&d!=n)
{
return d;
break;
}
if(i==k)
{
y=x;
k<<=1;
}
}
}
*/
int main()
{
	//freopen("in_1811.txt","r",stdin);
	srand(time(NULL));
	//cin>>t;
	//cout<<Mul64(16,16,10)<<endl;
	scanf("%d",&t);
	while(t--)
	{
		//cin>>n;
		scanf("%I64d",&n);
		if(Miller_Rabin(n,2))
		{
			printf("Prime\n");
		}
		else
		{
			long long ans=PollardRho(n);
			if(ans==-1)
			{
				printf("Prime\n");
			}
			else
			{
				printf("%I64d\n",ans);
			}
		}
	}
	return 0;
}
