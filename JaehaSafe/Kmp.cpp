#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> getPartialMatchNaive(const string& N){
  int m = N.size();
  vector<int> pi(m,0);
  for(int begin =1; begin < m; begin++){
    for(int i=0; i+begin<m; i++){
      //cout << i+begin << pi[begin+1] << " ";
      if(N[begin + i] != N[i])break;
      pi[begin + i] = max(pi[begin + i], i+1);
    }
    for(int kk: pi){
  //    cout << kk <<" ";
    }
  //  cout << "/";
  }
  return pi;
}

vector<int > getPartialMatch(const string& N){
  int m = N.size();
  vector<int> pi(m,0);

  int begin = 1, matched = 0;
  while(begin + matched < m){
    if(N[begin + matched] == N[matched]){
      matched++;
      pi[begin + matched -1] = matched;
    }else{
      if(matched == 0){
        begin++;
      }else{
        begin+=matched - pi[matched-1];
        matched = pi[matched-1];
      }
    }
  }
  return pi;
}

vector<int> kmpSearch(const string& original, const string& target){
  int n = original.size(), m = target.size();
  vector<int> ret;
  vector<int> pi = getPartialMatch(target);
  int begin = 0, matched = 0;
  while(begin <= n-m){
    if(matched < m && original[begin+matched] == target[matched]){
      matched++;
      if(matched == m )ret.push_back(begin);
    }else{
      if(matched == 0){
        begin++;
      }else{
        begin += matched - pi[matched-1];
        matched = pi[matched-1];
      //  printf("%d %c |",begin,original[begin]);
      }
    }
  }
  return ret;
}


int shiftLeft(const string& original, const string& target){
  return kmpSearch(original + original, target)[0];
}
int shiftRight(const string& original, const string& target){
  return kmpSearch(target + target, original)[0];
}

int main(){
  int c; scanf("%d",&c);
  while(c--){
    int N; cin >> N;
    int ans = 0;
    //초가화
    string now; cin >> now;
    for(int i=0; i<N; i++){
      string target[104];
      cin >> target[i];
      int tmp;
      if(i%2==0){
        tmp = shiftRight(now, target[i]);
      }else{
        tmp = now.size() - shiftRight(now, target[i]);
      }
      now = target[i];
  //    cout << tmp << " ";
      ans+= tmp;
    }
    cout << ans <<endl;
  }
}
