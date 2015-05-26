#include <iostream>

using namespace std;

#define MAXN 1000
char buf[MAXN];


int main()
{
	//freopen("in.txt", "r", stdin);

	while (cin.getline(buf,sizeof(buf)))
	{
		char *p = &buf[2];
		double r = 0.0;
		double base = 8.0;
		int len = 0;

		while (*p)
		{
			r += (*p-'0')/base;
			base *= 8;
			p++;
			len++;
		}


		//output
		printf("%s [8] = 0.",buf);
		for (int i=0;i<3*len;i++)
		{
			r *= 10;
			printf("%d",(int)r);
			r -= (int)r;
		}

		printf(" [10]\n");
	}
	return 0;
}
