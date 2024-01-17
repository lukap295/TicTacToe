#include <iostream>
#include <string>
using namespace std;

void drawBoard(int player, int num) {
	char s;
	if (player == 1) {
		s == 'X';
	}
	else
		s == 'O';
	char board[3][3] = { {'0','1','2'},{'3','4','5'},{'6','7','8'} };
	int i, j;
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int player1 = 1, player2 = 2;
	
}