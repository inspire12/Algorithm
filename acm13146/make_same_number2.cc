#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
long long int A[1000001];
vector<long long int> v;
int main(){
    int n;
    long long int output=0;
    scanf("%d",&n);
    for(int i=0; i<n ;i++){
        scanf("%lld", &A[i]);
        if(v.empty()) v.push_back(A[i]);
        else{
            while(v.back()<A[i]){
                int del = v.back();
                v.pop_back();

                if(v.empty() || v.back()>A[i]){
                    output+= A[i]-del;
                    break;
                }else{
                    output+= v.back()-del;
                }
            }
            v.push_back(A[i]);
        }
//      printf("de %d %d %d ", output, v.front(), v.back());
    }
//  printf("\n");
    if(v.size()>1)  output += v.front() - v.back() ;
    printf("%lld\n", output);
}
