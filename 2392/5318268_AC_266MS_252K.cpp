#include <iostream>
#include <algorithm>
using namespace std;

#define K 401
#define MAXIMUM 40001

bool f[MAXIMUM];
int h[K];
int maxh[K];
int c[K];
int order[K];

bool cmp(int a, int b)
{
	return maxh[a] < maxh[b];
}


int main()
{
	//freopen("in.txt", "r", stdin);

	int k;

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d", &h[i], &maxh[i], &c[i]);
	}

	int maxj = 0;

	int ii = 0;

	memset(f, false, sizeof(f));
	f[0] = true;

	for (int i = 0; i < k; i++)
	{
		order[i] = i;
	}

	sort(order, order + k, cmp);

	int jj = 0;
	while (jj < k)
	{
		ii = order[jj];

		for (int j = maxj; j >= 0; j--)
		{
			if (f[j] && j + h[ii] <= maxh[ii])
			{	
				//if (j + h[ii] <= MAXIMUM)
				{
					f[j + h[ii]] = true;

					if (j + h[ii] > maxj)
					{
						maxj =  j + h[ii];
					}
				}
			}
		}

		c[ii]--;

		if (c[ii] == 0)
		{
			jj++;
		}
	}

	for (int i = maxj; i >= 0; i--)
	{
		if (f[i])
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
