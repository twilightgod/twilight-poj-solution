#include<iostream>
using namespace std;

int Cj,Ci,Yi,S,N,w;
long long ans;

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&N,&S);
	scanf("%d%d",&Ci,&Yi);
	ans=Ci*Yi;
	Cj=Ci;
	w=1;
	N--;
	while(N--)
	{
		scanf("%d%d",&Ci,&Yi);
		if((Cj+S*w)<Ci)
		{
			ans+=(Cj+S*w)*Yi;
			w++;
		}
		else
		{
			ans+=Ci*Yi;
			Cj=Ci;
			w=1;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
