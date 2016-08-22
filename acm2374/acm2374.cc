#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> A;
int output=0;
int Part(int preMax, int x, int y){
    int maxValue=A[x],minValue=A[x];
    for(int i=x; i<=y; i++){
        if(A[i]>maxValue) maxValue = A[i];
        if(A[i]<minValue) minValue = A[i];
    }
    int maxLoc = 0;
    for(int i=x; i<=y;i++){
        if(A[i]==maxValue) maxLoc = i;
    }
//  printf("%d %d %d %d\n", x, y, preMax, maxValue);
    //output += preMax-maxValue;
//  printf("%d\n", preMax-maxValue);

    if(x>=y){output+=preMax-maxValue; return preMax-maxValue;}
    else if(x==maxLoc) {output+= preMax-maxValue; return Part(maxValue,x+1,y);}
    else if(y==maxLoc) {output+= preMax-maxValue; return Part(maxValue,x,y-1);}
    else{
        output+= preMax-maxValue;
        return Part(maxValue,x,maxLoc-1)+Part(maxValue,maxLoc+1,y);
    }
}

int main(){
    int input;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &input);
        A.push_back(input);
    }
    int maxValue = *max_element(A.begin(), A.end());
    //printf("%d\n", Part(maxValue, 0, n-1));
    Part(maxValue,0,n-1);
    printf("%d\n", output);
}