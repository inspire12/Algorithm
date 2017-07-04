/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int Answer;
stack<int> st;
int sub[1000003];
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
	for(test_case = 0; test_case  < T; test_case++)
	{
    int index =0;

		Answer = 0;
    int maxV = 0;
    int nowV = 0;
    string input;
    cin >> input;
    int len = input.size();
    bool preOpen = false;
    for(int i=0; i<len; i++){
      char cur = input.at(i);
      if(cur == '(' || cur == '{' || cur=='['){
        st.push(cur);
        if(preOpen){  //

        }
        preOpen = true;
      }else{
        if(st.empty()){

        }
        if(cur == ')'){
          if(st.top() =='('){
            nowV += 2;
            st.pop();
          }else{

          }
        }else if(cur == '}'){
          if(st.top() =='{'){
            nowV += 2;
            st.pop();
          }
        }else if(cur == ']'){
          if(st.top() =='['){
            nowV += 2;
            st.pop();
          }
        }
        preOpen = false;
      }
    }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
