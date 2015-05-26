#include<iostream>
using namespace std;
int leap(int x)//判断闰年函数 
{
if((x%4==0 && x%100!=0) || x%400==0)
return 1;
else return 0;
}
int main()
{
char week[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int year[2]={365,366};
int month[2][13]={0, 31,28,31,30,31,30,31,31,30,31,30,31,
                    0,31,29,31,30,31,30,31,31,30,31,30,31
       };//个人觉得这样处理闰年跟非闰年的年份跟月份，很方便，很好。
int days,ofweek,i,j;
while(scanf("%d",&days) && days!=-1)
{
   ofweek=days%7;//处理日历的星期 
   for(i=2000;days>=year[leap(i)];i++)
{ 
   days-=year[leap(i)];//重复减去一年的日数直至days小于366或365 
    } 
for(j=0;days>=month[leap(i)][j];j++)
{
    days-=month[leap(i)][j];//此时的i为上个循环结束的值，重复减去每个月数，直至days小于当前月 
}
printf("%d-%02d-%02d %s\n",i,j,days+1,week[ofweek]);//%02d 表示把对应的整数格式化为两位数字的字符串
}
system("pause");
return 0;
}