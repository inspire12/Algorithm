#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int Answer;
stack<char> st;
void clear(){
   while(!st.empty()){
     st.pop();
   }
}
int sub[1000003];
int index,indexCheck = 0;

int findTruemaxV(){
//  printf("\nj, bj : %d %d / ",j,bj);
  int ans = 0;
  for(int i=0; i<index; i++){
    ans += sub[i];
    sub[i] = 0;
  }
  cout << endl;
  index = 0;
  return ans;
}
int findFalsemaxV(){
  int ans = 0;
  for(int i=0; i<index; i++){
    if(ans < sub[i])ans = sub[i];
    cout << sub[i] + " ";
    sub[i] = 0;
  }
  cout << endl;
  index = 0;
  return ans;
}
int main(int argc, char** argv)
{
  // FILE * pFile;
  // pFile = freopen("outLargeA.txt","w",stdout);
	int T, test_case;
	cin >> T;
  cin.clear();
  while (cin.get() != '\n')
  {
      continue;
  }
	for(test_case = 0; test_case  < T; test_case++)
	{
    clear();
    string input;
    getline(cin,input);
    bool preOpen = false;
    int maxV = 0, index = 0, bIndex =0, subSize = 0;//, curV =0,
    int curV = 0;
    for(int i=0; i<input.size(); i++){
      char cur = input.at(i);
      if(cur == '['|| cur =='{' || cur =='('){
        st.push(cur);
        if(preOpen){
          indexCheck += 1;
        }
        preOpen = true;
      }else{
        if(st.empty()){
          //불가능 케이스 --> maxV에 저장하고 초기화
          curV = findTruemaxV();
          maxV = maxV > curV ? maxV: curV;
          continue;
        }
        if(cur == ']'){
          if(st.top() == '['){
            if(indexCheck > 0) index += 1;
      //      indexCheck--;
            sub[index]+=2;

            st.pop();
          }else{
            //불가능케이스
            curV = findFalsemaxV();
            maxV = maxV > curV ? maxV: curV;
            indexCheck = 0;
            clear();
          }
        }else if(cur == '}'){
          if(st.top() == '{'){
            if(indexCheck > 0) index += 1;
      //      indexCheck--;
            sub[index]+=2;
            st.pop();
          }else{
            curV = findFalsemaxV();
            maxV = maxV > curV ? maxV: curV;
            indexCheck = 0;
            clear();
          }
        }else if(cur == ')'){
          if(st.top() == '('){
            if(indexCheck > 0) index += 1;
        //    indexCheck--;
            sub[index]+=2;
            st.pop();
          }else{
            //불가능케이스
            curV = findFalsemaxV();
            maxV = maxV > curV ? maxV: curV;
            indexCheck = 0;
            clear();
          }
        }
        if(!preOpen){
          indexCheck -= 1;
        }
        preOpen = false;
        if(indexCheck==0){ //))
          curV = findTruemaxV();
          maxV = maxV > curV ? maxV: curV;
        }
      }
    }

    Answer = maxV;

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
  for(int i=0; i<=index; i++){
    sub[i]=0;
  }
//  fclose (stdout);

	return 0;//Your program should return 0 on normal termination.
}
