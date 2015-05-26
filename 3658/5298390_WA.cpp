/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Artificial Lake
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3658
*       ID             : 3658
*       Date           : 6/14/2009
*       Time           : 22:24:33
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define MAXSIZE 100002
#define MAXH    1000001

struct Level
{
	int w, h;
	int x;
};

long long time1[MAXSIZE];
long long ct;
long long su=0;


bool cmp(Level l1, Level l2)
{
	return l1.h < l2.h;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3658.txt","r",stdin);
#endif
	int n;
	Level le;
	list<Level> ll;

	scanf("%d", &n);

	le.h = MAXH;
	le.w = 1;
	le.x = 0;
	ll.push_back(le);

	for (int i = 0; i < n; i++)
	{
		le.x++;
		scanf("%d %d", &le.w, &le.h);
		ll.push_back(le);
		su+=le.w;
	}

	le.x++;
	le.h = MAXH;
	ll.push_back(le);

	list<Level>::iterator iter;
	iter = min_element(ll.begin(), ll.end(), cmp);
	//time1[iter->x] = iter->w;

	ct=0;

	int kk=n;

	while (kk--)
	{
		list<Level>::iterator left = iter; left--;
		list<Level>::iterator right = iter; right++;

		if (left->h < right->h)
		{
			time1[iter->x] = ct + iter->w;
			ct += ((long long)(left->h - iter->h)) * (iter->w);

		    left->w += iter->w;
			ll.erase(iter);

			iter = left;
			left--;

			while (left->h < iter->h)
			{
				iter = left;
				left++;
			}
		}
		else if (left->h > right->h)
		{
			time1[iter->x] = ct + iter->w;
			ct += ((long long)(right->h - iter->h)) * (iter->w);

		    right->w += iter->w;
			ll.erase(iter);

			iter = right;
			right++;

			while (right->h < iter->h)
			{
				iter = right;
				right++;
			}
		}
		else
		{
			time1[iter->x]=ct+su;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%I64d\n", time1[i + 1]);
	}


	return 0;
}
