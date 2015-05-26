#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
#define MAX 64
 
int weight['Z'];
 
struct Piece
{
	char data;
	int weight;
	int row;
	int col;
};
 
 
bool BLess(Piece p1,Piece p2)
{
	if(p1.weight < p2.weight)
		return true;
	else if(p1.weight == p2.weight)
	{
		if(p1.row > p2.row)
			return true;
		else if(p1.row == p2.row && p1.col < p2.col)
			return true;
	}
 
	return false;
}
 
 
 
bool WLess(Piece p1,Piece p2)
{
	if(p1.weight < p2.weight)
		return true;
	else if(p1.weight == p2.weight)
	{
		if(p1.row < p2.row)
			return true;
		else if(p1.row == p2.row && p1.col < p2.col)
			return true;
	}
	return false;
}
 
 
int main()
{
//	freopen("in.txt","r",stdin);
	weight['K'] = 0;
	weight['Q'] = 1;
	weight['R'] = 2;
	weight['B'] = 3;
	weight['N'] = 4;
	weight['P'] = 5;
 
	Piece bp[MAX],wp[MAX];
	string str;
	int i,j,b,w;
	b = w = 0;
	for(i = 0;i < 17;++i)
	{
		cin >> str;
		if(i % 2 != 0)
		{
			for(j = 2;j <= 30;j += 4)
			{
				if(str[j] != ':' && str[j] != '.')
				{
					if(str[j] >= 'a' && str[j] <= 'z')
					{
						bp[b].data = str[j] - 'a' + 'A';
						bp[b].row = 8 - i / 2;
						bp[b].col = j / 4;
						bp[b].weight = weight[bp[b].data];
						++b;
					}
					else
					{
						wp[w].data = str[j];
						wp[w].row = 8 - i / 2;
						wp[w].col = j / 4;
						wp[w].weight = weight[wp[w].data];
						++w;
					}
				}
			}
		}
	}
 
	sort(bp,bp + b,BLess);
	sort(wp,wp + w,WLess);
 
	cout << "White: ";
	if(w >= 1)
	{
		if(wp[0].data != 'P')
			cout << wp[0].data;
		cout << (char)(wp[0].col + 'a') << wp[0].row;
	}
	for(i = 1;i < w;++i)
	{
		cout << ',';
		if(wp[i].data != 'P')
			cout << wp[i].data;
		cout << (char)(wp[i].col + 'a') <<wp[i].row ;
	}
	cout << endl;
 
	cout << "Black: ";
	if(w >= 1)
	{
		if(bp[0].data != 'P')
			cout << bp[0].data;
		cout << (char)(bp[0].col + 'a') << bp[0].row;
	}
	for(i = 1;i < b;++i)
	{
		cout << ',';
		if(bp[i].data != 'P')
			cout << bp[i].data;
		cout << (char)(bp[i].col + 'a') << bp[i].row;
	}
	cout << endl;
	return 0;
}