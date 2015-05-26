#include <stdio.h>
#include <string.h>
    int main ()
    {
        char str[21];int len;int s[21];int i;
        while (EOF!=scanf ("%s",str))
        {
           len=strlen (str);
           for (i=0;i<len;i++)
             {  if (str[i]=='B'||str[i]=='F'||str[i]=='P'||str[i]=='V')
                  s[i]=1  ;           
               if (str[i]=='C'||str[i]=='G'||str[i]=='J'||str[i]=='K'||str[i]=='Q'||
               str[i]=='S'||str[i]=='X'||str[i]=='Z')
                   s[i]=2;  
               if (str[i]=='D'||str[i]=='T')
                    s[i]=3; 
                    if (str[i]=='L')
                   s[i]=4;
                    if (str[i]=='M'||str[i]=='N')
                    s[i]=5;
                     if (str[i]=='R')
                    s[i]=6;
                if (str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='H'||str[i]=='W'||str[i]=='Y')
                  s[i]=7 ;
               }   
                    if (s[0]!=7)   
                    	printf("%d",s[0]);  
            
            for (i=1;i<len;i++)
               if (s[i]!=7&&s[i]!=s[i-1])
                  printf("%d",s[i]);
                  printf("\n");
                  
                  
        }
        
         return 0;
    
    
    
    }

