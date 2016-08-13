#include <stdio.h>
#define MAX(a,b) a>b?a:b 

int inputTriangle[501][501];
int dpTriangle[501][501];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            scanf("%d", &inputTriangle[i][j]);
        }
    }
    dpTriangle[0][0] = inputTriangle[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0)
                dpTriangle[i][j] = dpTriangle[i-1][j];
            else if(j==i)
                dpTriangle[i][j] = dpTriangle[i-1][j-1];
            else
                dpTriangle[i][j] =  MAX(dpTriangle[i-1][j-1],dpTriangle[i-1][j]);

            dpTriangle[i][j]+=inputTriangle[i][j];
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(max < dpTriangle[n-1][i]) max = dpTriangle[n-1][i];
    }
    printf("%d\n", max);
}
