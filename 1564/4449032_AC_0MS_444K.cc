/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sum It Up
*       ID             : 1564
*       Date           : 12/3/2008
*       Time           : 12:53:57
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

/*
find 是否找到解
t 要达到的总和
n 可用数字的个数
len 解的长度
a[] 可用的数字
res[] 储存解
*/
bool find;
int t,n,len;
int a[12],res[12];

/*
index 当前搜索的可用数字的索引号
sum 当前搜索的累计总和
c 前一个搜索状态是否使用了a[index]
*/
void dfs(int index,int sum,bool c)
{
	//达到边界条件,输出
	if(sum==t)
	{
		::find=true;
		for(int i=0;i<len;++i)
		{
			if(i!=0)
			{
				cout<<'+';
			}
			cout<<res[i];
		}
		cout<<endl;
		return;
	}

	//剪枝,因为a[]是以非递增序列给出,如果剩下的数字最大情况下都不够凑出t则不用继续
	if(sum+(n-index-1)*a[index]<t)
	{
		return;
	}

	//如果加上下一个数字超过t,则不能用这个数字
	//如果前一个状态没有使用a[index],且a[index+1]==a[index],那么再用a[index+1]就会造成重复,所以不能使用
	if(sum+a[index+1]>t||!c&&a[index+1]==a[index])
	{
		//只用考虑不加a[index+1]的情况
		dfs(index+1,sum,false);
	}
	else
	{
		//加上a[index+1]的情况
		len++;
		res[len-1]=a[index+1];
		dfs(index+1,sum+a[index+1],true);
		len--;

		//不加a[index+1]的情况
		dfs(index+1,sum,false);
	}
}

int main()
{
	do
	{
		//读入
		cin>>t>>n;
		if(t==0&&n==0)
		{
			break;
		}
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
		}

		//初始化
		len=0;
		::find=false;
		cout<<"Sums of "<<t<<":\n";
		for(int i=0;i<n;++i)
		{
			//某一数字有重复只要做从这一数字的第一个开始的搜索即可
			if(i==0||i!=0&&a[i]!=a[i-1])
			{
				len=1;
				res[0]=a[i];
				dfs(i,a[i],true);
			}
		}

		//无解的情况
		if(!::find)
		{
			cout<<"NONE\n";
		}
	}while(1);
}
