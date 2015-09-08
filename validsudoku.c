#include <stdio.h>

// Use -1 to indicate the empty cell

int checkBoard(int board[][9]){

	// Check the cols
	for(int i=0; i<9; i++){
		int check[9] = {0,0,0,0,0,0,0,0,0};
		for(int j=0; j<9; j++){
			if(board[i][j] != -1){
				if(check[board[i][j]-1])
					return 0;
				check[board[i][j]-1] = 1;
			}
		}
	}

	// Check the rows
	for(int j=0; j<9; j++){
		int check[9] = {0,0,0,0,0,0,0,0,0};
		for(int i=0; i<9; i++){
			if(board[i][j] != -1){
				if(check[board[i][j]-1])
					return 0;
				check[board[i][j]-1] = 1;
			}
		}
	}

	//check each 3*3 matrix
	for(int block=0; block<9; block++){
		for(int i=block/3*3; i<block/3*3+3; i++){
			int check[9] = {0,0,0,0,0,0,0,0,0};
			for(int j=block%3*3; j<block%3*3+3; j++){
				if(board[i][j] != -1){
					if(check[board[i][j]-1])
						return 0;
					check[board[i][j]-1] = 1;
				}
			}
		}
	}
	return 1;
}

int main(){

	int board[9][9];
	printf("\nEnter the board elements:\n");
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &board[i][j]);
		}
	}
	
	int result = checkBoard(board);
	if(result)
		printf("\nValid board!\n");
	else
		printf("\nInvalid board!");

	return 1;
}

