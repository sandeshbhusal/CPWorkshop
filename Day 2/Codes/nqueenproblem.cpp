#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > matrix;

bool isValid(matrix &board, int row, int col){	//checks if board[row][col] is valid to place queen
	for(int i =0; i<row; i++){
		if(board[i][col])return 0;
	}
	for(int i = row, j = col; i>=0 && j >= 0; i--, j--){
		if(board[i][j]) return 0;
	}
	for(int i = row, j = col; i>=0 && j<board.size(); i--, j++){
		if(board[i][j]) return 0;
	}
	return 1;	
}

bool solve(matrix &board, int row){				//solves using backtracking
	if (row >= board.size())return 1;
	for(int j = 0; j < board.size(); j++){
		if(isValid(board, row, j)){
			board[row][j] = 1;
			if(solve(board, row + 1))
				return 1;
			board[row][j] = 0; 
		}
	}
	return false;
}


int main(){
	int n;
	printf("Enter number of queens: ");
	scanf("%d", &n);
	matrix board(n, std::vector<int>(n, 0));	
	if(solve(board, 0) == 0){
		printf("There is no solution for n = %d\n", n);
	}
	else{													//Print solution
		for(int i = 0; i<board.size(); i++){
			for(int j = 0; j<board[0].size(); j++){
				printf(" %d",board[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}