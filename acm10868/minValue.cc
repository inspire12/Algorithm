#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<pair<int, int> > array;

int main(){
    int n,m,a,b;
    scanf("%d %d", &n, &m);

    for(int i=0; i< n; i++){
        int input;
        scanf("%d", &input);
        array.push_back(make_pair(input,i));
    }
    sort(array.begin(), array.end());
   
    int min;
    while(m--){
        scanf("%d %d", &a, &b);
        a= a-1; b=b-1;
        for(int i =0; i < n; i++){
            if(array.at(i).second >= a && (array.at(i).second <=b)){
                min = array.at(i).first;
                break;
            }
        }
        printf("%d\n",min);
    }
}
     