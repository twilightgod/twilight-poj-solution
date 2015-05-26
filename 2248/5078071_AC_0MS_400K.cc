/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Addition Chains
*       ID             : 2248
*       Date           : 5/1/2009
*       Time           : 13:10:57
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int ans[101][11]={
{1,1},
{2,1,2},
{3,1,2,3},
{3,1,2,4},
{4,1,2,3,5},
{4,1,2,3,6},
{5,1,2,3,4,7},
{4,1,2,4,8},
{5,1,2,3,6,9},
{5,1,2,3,5,10},
{6,1,2,3,4,7,11},
{5,1,2,3,6,12},
{6,1,2,3,5,8,13},
{6,1,2,3,4,7,14},
{6,1,2,3,5,10,15},
{5,1,2,4,8,16},
{6,1,2,4,8,9,17},
{6,1,2,3,6,9,18},
{7,1,2,3,4,8,11,19},
{6,1,2,3,5,10,20},
{7,1,2,3,4,7,14,21},
{7,1,2,3,4,7,11,22},
{7,1,2,3,5,10,13,23},
{6,1,2,3,6,12,24},
{7,1,2,3,5,10,15,25},
{7,1,2,3,5,8,13,26},
{7,1,2,3,6,9,18,27},
{7,1,2,3,4,7,14,28},
{8,1,2,3,4,7,11,18,29},
{7,1,2,3,5,10,15,30},
{8,1,2,3,4,7,14,17,31},
{6,1,2,4,8,16,32},
{7,1,2,4,8,16,17,33},
{7,1,2,4,8,9,17,34},
{8,1,2,3,4,7,14,21,35},
{7,1,2,3,6,9,18,36},
{8,1,2,3,5,8,16,21,37},
{8,1,2,3,4,8,11,19,38},
{8,1,2,3,5,8,13,26,39},
{7,1,2,3,5,10,20,40},
{8,1,2,3,5,10,20,21,41},
{8,1,2,3,4,7,14,21,42},
{8,1,2,3,5,10,20,23,43},
{8,1,2,3,4,7,11,22,44},
{8,1,2,3,5,10,15,30,45},
{8,1,2,3,5,10,13,23,46},
{9,1,2,3,4,7,10,20,27,47},
{7,1,2,3,6,12,24,48},
{8,1,2,3,6,12,24,25,49},
{8,1,2,3,5,10,15,25,50},
{8,1,2,3,6,12,24,27,51},
{8,1,2,3,5,8,13,26,52},
{9,1,2,3,5,6,12,24,29,53},
{8,1,2,3,6,9,18,27,54},
{9,1,2,3,4,7,11,22,33,55},
{8,1,2,3,4,7,14,28,56},
{9,1,2,3,4,7,14,28,29,57},
{9,1,2,3,4,7,11,18,29,58},
{9,1,2,3,4,7,14,28,31,59},
{8,1,2,3,5,10,15,30,60},
{9,1,2,3,5,7,14,28,33,61},
{9,1,2,3,4,7,14,17,31,62},
{9,1,2,3,4,7,14,21,42,63},
{7,1,2,4,8,16,32,64},
{8,1,2,4,8,16,32,33,65},
{8,1,2,4,8,16,17,33,66},
{9,1,2,3,4,8,16,32,35,67},
{8,1,2,4,8,9,17,34,68},
{9,1,2,3,5,8,16,32,37,69},
{9,1,2,3,4,7,14,21,35,70},
{10,1,2,3,4,7,8,16,32,39,71},
{8,1,2,3,6,9,18,36,72},
{9,1,2,3,6,9,18,36,37,73},
{9,1,2,3,5,8,16,21,37,74},
{9,1,2,3,5,10,15,25,50,75},
{9,1,2,3,4,8,11,19,38,76},
{9,1,2,4,5,9,18,36,41,77},
{9,1,2,3,5,8,13,26,39,78},
{10,1,2,3,4,7,9,18,36,43,79},
{8,1,2,3,5,10,20,40,80},
{9,1,2,3,5,10,20,40,41,81},
{9,1,2,3,5,10,20,21,41,82},
{9,1,2,3,5,10,20,40,43,83},
{9,1,2,3,4,7,14,21,42,84},
{9,1,2,3,5,10,20,40,45,85},
{9,1,2,3,5,10,20,23,43,86},
{10,1,2,3,4,7,10,20,40,47,87},
{9,1,2,3,4,7,11,22,44,88},
{10,1,2,3,4,7,11,22,44,45,89},
{9,1,2,3,5,10,15,30,45,90},
{10,1,2,3,4,7,11,22,44,47,91},
{9,1,2,3,5,10,13,23,46,92},
{10,1,2,3,4,7,14,17,31,62,93},
{10,1,2,3,4,7,10,20,27,47,94},
{10,1,2,3,4,7,11,22,44,51,95},
{8,1,2,3,6,12,24,48,96},
{9,1,2,3,6,12,24,48,49,97},
{9,1,2,3,6,12,24,25,49,98},
{9,1,2,3,6,12,24,48,51,99},
{9,1,2,3,5,10,15,25,50,100}
};

int n;
int main()
{
while(scanf("%d",&n)&&n)
{
for(int i=1;i<=ans[n-1][0];++i)
{
printf("%d ",ans[n-1][i]);
}
printf("\n");
}
return 0;
}