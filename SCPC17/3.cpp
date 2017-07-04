/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int Answer;
int board[103][103];
int N, M;
void changeRow(int i){
  for(int u = 0; u<N; u++){
    if(board[i][u] ==0){
      board[i][u] = 1;
    }else{
      board[i][u] = 0;
    }
  }
}
void changeCol(int j){
  for(int u = 0; u<N; u++){
    if(board[u][j] ==0){
      board[u][j] = 1;
    }else{
      board[u][j] = 0;
    }
  }
}
bool check(){
  return true;
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
	for(test_case = 0; test_case  < T; test_case++)
	{
    cin >> N >>M;
    string input ="";
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        scanf("%d",&board[i][j]);
      }
    }
    for(int i=0; i<N; i++){
      if(board[i][0] == 0){
        changeRow(i);
        input += "R"+to_string(i) +"00 ";
      }
    }
    for(int j=0; j<M; j++){
      if(board[0][j] == 0){
        changeCol(j);
        input += "C"+to_string(j) +"00 ";
      }
    }
    Answer = 0;

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
    if(check()){
      cout << input << endl;
    }else{
      cout <<"Impossible"<<endl;
    }
	}

	return 0;//Your program should return 0 on normal termination.
}
