#include <stdio.h>
#include <assert.h>

char w[1000][20];
int d[1000];
int n,m,i,j,k,sum;
char buf[1000];

main(){
   scanf("%d%d",&m,&n);
   for (i=0;i<m;i++) {
      scanf(" %s %d",w[i],&d[i]);
      assert(strlen(w[i]) <= 16);
   }
   for (i=0;i<n;i++) {
      sum = 0;
      while (scanf(" %s",buf) && strcmp(buf,".")) {
         assert(strlen(buf) <= 16);
         for (j=0;j<m && strcmp(buf,w[j]);j++);
         if (j < m) sum += d[j];
      }
      printf("%d\n",sum);
   }
}

