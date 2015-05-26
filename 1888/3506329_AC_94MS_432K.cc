#include<iostream>
#include<iomanip>
using namespace std;
#define MAXN 10

char mat1[MAXN][MAXN],mat2[MAXN][MAXN];
int num[MAXN][MAXN];
int i,j,k,m,n,test,c;
bool first;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	test=0;
	first=true;
	while(cin>>m&&m)
	{
		if(first)
		{
			first=false;
		}
		else
		{
			cout<<endl;
		}
		printf("puzzle #%d:\n",++test);
		cin>>n;
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				cin>>mat1[i][j];
				mat2[i][j]=mat1[i][j];
			}
		}

		c=0;
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				if(mat1[i][j]!='*'&&(i==0||j==0||mat1[i][j-1]=='*'||mat1[i-1][j]=='*'))
				{
					num[i][j]=++c;
				}
			}
		}


		cout<<"Across\n";
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				if(mat1[i][j]!='*')
				{
					cout<<setw(3)<<num[i][j]<<'.';
					for(k=j;k<n&&mat1[i][k]!='*';++k)
					{
						cout<<mat1[i][k];
						mat1[i][k]='*';
					}
					cout<<endl;
				}
			}
		}
		cout<<"Down\n";
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				if(mat2[i][j]!='*')
				{
					cout<<setw(3)<<num[i][j]<<'.';
					for(k=i;k<m&&mat2[k][j]!='*';++k)
					{
						cout<<mat2[k][j];
						mat2[k][j]='*';
					}
					cout<<endl;
				}
			}
		}
	}
	return 0;
}
