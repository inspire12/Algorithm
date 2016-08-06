#include <stdio.h>

int main(){
    int n,m;
    scanf("%d",&n);
    int itr;
    int loc=0;
    int value=0;
    while(n!=0){
        scanf("%d",&m);
        loc=0;
        value=0;
        for(itr =0; itr<n; n--){
            loc+=m%n;
            value+=m/n;
            if(loc>=n){loc=loc%n; value+=1;}
            if(loc==0||loc==1)break;
            loc-=1;
        }
        printf("%d %d\n",n-1,value);
        scanf("%d",&n);
    }
}
