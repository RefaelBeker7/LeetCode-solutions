#include <stdio.h>
#include <stdbool.h>

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]


bool isValidUnit(char** board, int startx, int starty, int nx, int ny){
	bool ten[11] = { false };
	for (int i = startx; i<startx + nx; i++){
		for (int j = starty; j<starty + ny; j++){
			int x = board[i][j] == '.' ? 10 : board[i][j] - '0';
			if (x != 10 && ten[x] == true)
				return false;
			ten[x] = true;
		}
	}
	return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	int i, j;
	bool valid = true;

	//boardRowSize == boardColSize
	for (i = 0; i<boardRowSize; i++){
		//check every row and col
		valid = isValidUnit(board, 0, i, boardRowSize, 1) & isValidUnit(board, i, 0, 1, boardRowSize);
		if (valid == false)
			return false;
	}
	for (i = 0; i<7; i += 3){
		for (j = 0; j<7; j += 3){
			//check every 3*3 unit
			valid = isValidUnit(board, i, j, 3, 3);
			if (valid == false)
				return false;
		}
	}
	return true;
}