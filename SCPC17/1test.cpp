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
int j,bj;

int findmaxV(){
  int a = 0, b = 0;
  for(int i=j; i>=0&&i>=j-bj; i--){
    a += sub[i];
  }
  for(int i=0; i<j-bj; i++){
    b+= sub[i];
  }
  //debug
  for(int i=0; i<=j; i++){
//    cout << sub[i] << " ";
    sub[i] = 0;
  }
//  cout << endl;
 //cout << a << b ;
  j = 0; bj = 0;
  return a>b? a: b;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	// freopen("input.txt", "r", stdin);

	 cin >> T;
   cin.clear();
  while (cin.get() != '\n')
  {
      continue;
  }
	for(test_case = 0; test_case  < T; test_case++)
	{
    string input;
    getline(cin,input);
    bool preOpen = false;
    int maxV = 0;
    j =0,bj = 0;
    for(int i=0; i<input.size(); i++){
      char cur = input.at(i);
      if(cur == '['|| cur =='{' || cur =='('){
        st.push(cur);
        if(preOpen){
          j++;
        }
        preOpen = true;
      }else{
        if(!preOpen){
          bj++;
          //for (int i = j-bj; i< j; i++ ){ }
        }
        preOpen = false;

        if(st.empty()){
          //불가능 케이스 --> maxV에 저장하고 초기화

          int tmp =  findmaxV();
          maxV = maxV > tmp  ? maxV:tmp ;
          continue;
        }
        if(cur == ']'){
          if(st.top() == '['){
            sub[j]+=2;
            st.pop();
          }else{
            //불가능케이스
            int tmp =  findmaxV();
            maxV = maxV > tmp  ? maxV:tmp ;
            clear();
          }
        }else if(cur == '}'){
          if(st.top() == '{'){
            sub[j]+=2;
            st.pop();
          }else{
            //불가능케이스
            int tmp =  findmaxV();
            maxV = maxV > tmp  ? maxV:tmp ;
            clear();
          }
        }else if(cur == ')'){
          if(st.top() == '('){
            sub[j]+=2;
            st.pop();
          }else{
            //불가능케이스
            int tmp =  findmaxV();
            maxV = maxV > tmp  ? maxV:tmp ;
            clear();
          }
        }
      }
    }
    int tmp =  findmaxV();
    maxV = maxV > tmp  ? maxV:tmp ;
    Answer = maxV;

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
//  cout << findmaxV(0,0);
	return 0;//Your program should return 0 on normal termination.
}
