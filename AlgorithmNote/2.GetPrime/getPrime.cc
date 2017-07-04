#include <stdio.h>
 
 int main(){
 
     int m, n;
     bool isPrime = true;
     scanf("%d %d",&m,&n);
 //  if(m<2) printf("%d\n",2);
     for(int i=m; i<=n ;i++){
         if(i==1) continue;
         isPrime = true;
         for(int j=2; j*j <=i; j++)
             if(i%j==0){isPrime = false; break;}
         if(isPrime )printf("%d\n",i);
     }
 }
