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
    string input;
    getline(cin,input);
    bool preOpen = false;
    int maxV = 0,index = 0;
    int countOpen = 0, tmpLen = 0;
    for(int i=0; i<input.size(); i++){
      char cur = input.at(i);
      if(cur == '['|| cur =='{' || cur =='('){
        st.push(cur);
      
      }else{
        if(st.empty()){
          //불가능 케이스 --> maxV에 저장하고 초기화
          //

          tmpLen = 0; countOpen = 0;
          clear();
          continue;
        }
        if(cur == ']'){
          if(st.top() == '['){
            tmpLen+=2;
            st.pop();
          }else{
            //불가능케이스 2가지 경우
            /*
              1. 앞과 연속
               -
              2. 앞과 불연속 -> maxV 남기고 다 초기화
            */
            index ++;
            sub[index] +=tmpLen;
            tmpLen = 0;
            clear();

          }
        }else if(cur == '}'){
          if(st.top() == '{'){
            tmpLen+=2;
            st.pop();
          }else{
            //불가능케이스

            clear();
          }
        }else if(cur == ')'){
          if(st.top() == '('){
            tmpLen+=2;
            st.pop();
          }else{
            //불가능케이스
            int tmp =  findmaxV();
            maxV = maxV > tmp  ? maxV:tmp ;
            clear();
          }
        }
        if(!preOpen){
          bj++;
        }
        preOpen = false;

      }
    }
    int tmp =  findmaxV();
    maxV = maxV > tmp  ? maxV:tmp ;
    Answer = maxV;


		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
  //fclose (stdout);
//  cout << findmaxV(0,0);
	return 0;//Your program should return 0 on normal termination.
}
