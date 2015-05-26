import java.util.*;

public class Main {
          static final int MAX = 1000000000;
          public static void main(String[] args) {
              // TODO Auto-generated method stub
              Scanner sc = new Scanner(System.in);
              int w = sc.nextInt();
              int h = sc.nextInt();
              int[][] b = new int[h+2][w+2];
              int[][] l = new int[h+2][w+2];
              for(int i=1;i<=h;i++){
                  for(int j=1;j<=w;j++){
                      b[i][j] = sc.nextInt();
                  }
              }
              
              for(int i=1;i<=h;i++){
                  for(int j=1;j<=w;j++){
                      l[i][j] = MAX;
                  }
              }
              
              while(true){
                  boolean end = true;
                  for(int i=1;i<=h;i++){
                      for(int j=1;j<=w;j++){
                          if(l[i][j]>b[i][j]){
                              if(l[i][j]>l[i-1][j]){
                                  l[i][j] = Math.max(l[i-1][j], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i+1][j]){
                                  l[i][j] = Math.max(l[i+1][j], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i][j-1]){
                                  l[i][j] = Math.max(l[i][j-1], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i][j+1]){
                                  l[i][j] = Math.max(l[i][j+1], b[i][j]);
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
                                  l[i][j] = Math.max(l[i-1][j], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i+1][j]){
                                  l[i][j] = Math.max(l[i+1][j], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i][j-1]){
                                  l[i][j] = Math.max(l[i][j-1], b[i][j]);
                                  end = false;
                              }
                              if(l[i][j]>l[i][j+1]){
                                  l[i][j] = Math.max(l[i][j+1], b[i][j]);
                                  end = false;
                              }                            
                          }
                      }
                  }
                  if(end) break;
              }
              
              long sum = 0;
              for(int i=1;i<=h;i++){
                  for(int j=1;j<=w;j++){
                      sum += l[i][j] - b[i][j];
                  }
              }
              
              System.out.println(sum);
          }
}