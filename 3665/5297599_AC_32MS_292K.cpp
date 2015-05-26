#include <iostream>
using namespace std;

const int N = 1001;
const int T = 1001;

int R[N];

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, t;
	int maxi;

	while (cin>>n>>t)
	{
		maxi = -1;
		for (int i = 0; i < n; i++)
		{
			cin>>R[i];
			if (maxi == -1 || R[maxi] < R[i])
			{
				maxi = i;
			}
		}


		for (int i = 0; i < t; i++)
		{
			cout<<maxi + 1<<'\n';

			int m = R[maxi] / (n - 1);
			int mr = R[maxi] % (n - 1);

			int tmpmaxi = -1;

			for (int j = 0; j < n; j++)
			{
				if (j != maxi)
				{
					R[j] += m + (mr > 0 ? 1 : 0);
					mr--;

					if (tmpmaxi == -1 || R[tmpmaxi] < R[j])
					{
						tmpmaxi = j;
					}
				}
			}

			/*
			m = R[maxi] % (n - 1);

			
			int k = 0;
			while (m)
			{
				if (k != maxi)
				{
					R[k]++;
					m--;

					if (tmpmaxi == -1 || R[tmpmaxi] < R[k])
					{
						tmpmaxi = k;
					}
				}
				k++;
			}*/

			R[maxi] = 0;
			maxi = tmpmaxi;
		}
	}
	return 0;
}
