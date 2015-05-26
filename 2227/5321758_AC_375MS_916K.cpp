/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Wedding Juicer
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2227
*       ID             : 2227atwiki
*       Date           : 6/22/2009
*       Time           : 22:11:36
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
using namespace std;

const int MAX = 1000000000;
const int MAXN = 302;
int w,h;
int b[MAXN][MAXN],l[MAXN][MAXN];

inline int max1(int x,int y)
{
	return x>y?x:y;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2227atwiki.txt","r",stdin);
#endif

	scanf("%d%d",&w,&h);
             
              for(int i=1;i<=h;i++){
                  for(int j=1;j<=w;j++){
                      scanf("%d",&b[i][j]);
                  }
              }
              
              for(int i=1;i<=h;i++){
                  for(int j=1;j<=w;j++){
                      l[i][j] = MAX;
                  }
              }
              
              while(true){
                  bool end = true;
                  for(int i=1;i<=h;i++){
                      for(int j=1;j<=w;j++){
                          if(l[i][j]>b[i][j]){
                              if(l[i][j]>l[i-1][j]){
                                  l[i][j] = max1(l[i-1][j], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i+1][j]){
                                  l[i][j] = max1(l[i+1][j], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i][j-1]){
                                  l[i][j] = max1(l[i][j-1], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i][j+1]){
                                  l[i][j] = max1(l[i][j+1], b[i][j]);
                                  end = false;
                              }                            
                          }
                      }
                  }
                  if(end) break;
                  
                  for(int j=w;j>=1;j--){
                      for(int i=h;i>=1;i--){
                          if(l[i][j]>b[i][j]){
                              if(l[i][j]>l[i-1][j]){
                                  l[i][j] = max1(l[i-1][j], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i+1][j]){
                                  l[i][j] = max1(l[i+1][j], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i][j-1]){
                                  l[i][j] = max1(l[i][j-1], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i][j+1]){
                                  l[i][j] = max1(l[i][j+1], b[i][j]);
                                  end = false;
                              }                            
                          }
                      }
                  }
                  if(end) break;
              }
              
              long long sum = 0;
              for(int i=1;i<=h;i++){
                  for(int j=1;j<=w;j++){
                      sum += l[i][j] - b[i][j];
                  }
              }
              printf("%I64d\n",sum);

	return 0;
}
