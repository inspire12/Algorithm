#include <stdio.h>
#include <utility>

#define MAX(a,b) a>b?a:b
int dp[1001][1001];

int input[1001];
int main(){
    int t,w;
    scanf("%d %d", &t, &w);
    for(int i=1; i<=t; i++){
        scanf("%d", &input[i]);
    }
    for(int i=1;i<=t;i++){
        for(int j=0; j<=i; j++){
            if(j<=w){
                if(j==0){
                    dp[i][j] = dp[i-1][j];
                }
                else if(j==i){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = MAX(dp[i-1][j-1],dp[i-1][j]);
                }

                if(j%2==1&& input[i]%2==0||j%2==0&& input[i]%2==1){
                    dp[i][j]+=1;
                }
            }
        }
    }
    int max = 0;
    for(int i=0; i<=w; i++){
        if(max < dp[t][i]) max = dp[t][i];
    }
    printf("%d\n", max);
}
