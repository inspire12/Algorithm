/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;

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
		Answer = 0;
    bool trade = false;
    int N,stock,buy = 1,sold = 1e+9,count = 0;
    cin >> N;
    for(int i=0;i<N;i++){
      cin >> stock;
      if(trade == false){ //구매할 때는 최대한 작게
        if(stock < sold){ // 주식을 이걸로 구입//1 차적으론 여기
          buy = stock;
          trade = true;
        }else if(stock > sold){   // stock이 sold보다 더 큰게 있으면 그걸로 선택
          sold = stock;
        }
      }else{  //판매할 때
        if(stock < buy){ // stock이 buy보다 더 작은 게 있으면 그걸로 선택
          buy = stock;
        }else if(stock > buy){  // 판매할 대상을 찾음
          sold = stock;
          trade = false;
          count++;
        }
      }
      //printf("%d %d %d %d %d\n",stock, buy, sold, count, trade);
    }
    Answer = count*2;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
