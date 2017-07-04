#include <iostream>
#include <stdio.h>
#define ll long long int
long long numbers[1000001];
long long prinum[10000];

using namespace std;
int main(){
  ll max,min;
  ll num;
  int prime = 0;
  int count = 0;
  cin << min << max;
  for(ll i= 2; i*i<= max; i++){
    ll x = min / (i*i);
    if(min % i*i!=0){
      x++;
    }
    while(x*(i*i) <= max){
      numbers[x*(i*i) - min] = 1;
      x++;
    }
  }
  for(int i=9; i<max-min; i++){
    if(numbers[i] == 0){
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
