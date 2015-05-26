/*
POJ 1700
http://poj.org/problem?id=1700

Crossing River
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 8978		Accepted: 3362
Description

A group of N people wishes to go across a river with only one boat, which can at most carry two persons. Therefore some sort of shuttle arrangement must be arranged in order to row the boat back and forth so that all people may cross. Each person has a different rowing speed; the speed of a couple is determined by the speed of the slower one. Your job is to determine a strategy that minimizes the time for these people to get across.
Input

The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. The first line of each case contains N, and the second line contains N integers giving the time for each people to cross the river. Each case is preceded by a blank line. There won't be more than 1000 people and nobody takes more than 100 seconds to cross.
Output

For each test case, print a line containing the total number of seconds required for all the N people to cross the river.
Sample Input

1
4
1 2 5 10
Sample Output

17
Source

POJ Monthly--2004.07.18
*/

#include<iostream>
#include<algorithm>
using namespace std;

int const MAXN = 1000;

int T, n;

//t[i]: Time for person i
int t[MAXN];

//f(i): Total time for first i+1 person(0-based)
int f(int i)
{
	//1 person
	if (i==0)
	{
		return t[0];
	}
	//2 persons
	if (i==1)
	{
		return t[1];
	}
	//3 persons, the fastest one take the others
	if (i==2)
	{
		return t[1] + t[0] + t[2];
	}

	/*
	Let the slowest two persons go to the other side and never come back.
	
	Method 1:
	0 i     ->
	0       <-
	0 i-1   ->
	0       <-

	Method 2:
	0 1     ->
    0       <-
    i i-1   ->
    1       <-

	f[i]=f[i-2]+min{t[i]+t[0]+t[i-1]+t[0], t[1]+t[0]+t[i]+t[1]}
	*/

	return f(i-2) + min(t[i] + t[0] + t[i-1] + t[0], t[1] + t[0] + t[i] + t[1]);
}

int main()
{
	//freopen("1700.txt", "r", stdin);

	//scanf("%d\n", &T);
	//while (T--)
	{
		scanf("%d\n", &n);
		for (int i=0;i<n;++i)
		{
			scanf("%d\n", t+i);
		}

		sort(t, t+n);

		printf("%d\n", f(n-1));
	}
}