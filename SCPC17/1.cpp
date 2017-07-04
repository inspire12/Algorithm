/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
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
int j,bj,subJ;

int findmaxV(){
  int a = 0, b = 0;
  for(int i=j; i>=0&&i>=j-bj; i--){
    a += sub[i];
  }
  for(int i=0; i<j-bj; i++){
    b+= sub[i];
  }
  //debug
  //printf("\nj, bj : %d %d : ",j,bj);
  for(int i=0; i<=j; i++){
  //  cout << sub[i] << " ";
    sub[i] = 0;
  }
  cout << endl;
 //cout << a << b ;
  j = 0; bj = 0;
  return a>b? a: b;
}
int findmaxV2(){
  int maxV1 =0;
  for(int i=0; i<j; i++){
    if(maxV1 < sub[i]) maxV1 = sub[i];
  //    cout << sub[i] << " ";
    sub[i] = 0;
  }
  return maxV1;
}
int main(int argc, char** argv)
{
//   FILE * pFile;
//   pFile = freopen("outLargeA.txt","w",stdout);
	int T, test_case;
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
        if(!preOpen){
          subJ++;
        }
        preOpen = true;
      }else{
        if(st.empty()){
          //불가능 케이스 --> maxV에 저장하고 초기화
          int tmp =  findmaxV2();
          maxV = maxV > tmp  ? maxV:tmp ;
          continue;
        }
        if(cur == ']'){
          if(st.top() == '['){
            j+= subJ;
            subJ = 0;
            sub[j]+=2;
            st.pop();
          }else{
            //불가능케이스
            int tmp =  findmaxV2();
            preOpen = true;
            maxV = maxV > tmp  ? maxV:tmp ;
            clear();
          }
        }else if(cur == '}'){
          if(st.top() == '{'){
            j+= subJ;
            subJ = 0;
            sub[j]+=2;
            st.pop();
          }else{
            //불가능케이스
            int tmp =  findmaxV2();
            preOpen = true;
            maxV = maxV > tmp  ? maxV:tmp;
            clear();
          }
        }else if(cur == ')'){
          if(st.top() == '('){
            j+= subJ;
            subJ = 0;
            sub[j]+=2;
            st.pop();
          }else{
            //불가능케이스
            int tmp =  findmaxV2();
            preOpen = true;
            maxV = maxV > tmp  ? maxV:tmp ;
            clear();
          }
        }
        if(!preOpen){
          bj++;
          //for (int i = j-bj; i< j; i++ ){ }
        }
        preOpen = false;

      }
    }
    int tmp =  findmaxV2();
    maxV = maxV > tmp  ? maxV:tmp ;
    Answer = maxV;


		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
//  fclose (stdout);
//  cout << findmaxV(0,0);
	return 0;//Your program should return 0 on normal termination.
}
