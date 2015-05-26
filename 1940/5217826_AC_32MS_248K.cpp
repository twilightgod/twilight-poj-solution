#include <iostream>
using namespace std;

#define N 100000

double mx[N], my[N];
double x[N], y[N];


int main()
{
	//freopen("in.txt", "r", stdin);

	int n;

	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &mx[i], &my[i]);

			mx[i] *= 2; my[i] *= 2;
		}

		double sum = 0.0;
		int flag = 1;

		for (int i = 1; i <= n; i++)
		{
			sum += mx[i] * flag;
			flag = -flag;
		}

		x[1] = sum / 2;

		for (int i = 2; i <= n; i++)
		{
			x[i] = mx[i - 1] - x[i - 1];
		}

		sum = 0.0;
		flag = 1;

		for (int i = 1; i <= n; i++)
		{
			sum += my[i] * flag;
			flag = -flag;
		}

		y[1] = sum / 2;

		for (int i = 2; i <= n; i++)
		{
			y[i] = my[i - 1] - y[i - 1];
		}

		printf("%d", n);

		for (int i = 1; i <= n; i++)
		{
			printf(" %.6lf %.6lf", x[i], y[i]);
		}

		printf("\n");
	}
	return 0;
}