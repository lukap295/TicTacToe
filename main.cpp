#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gameover(char board[][3]) {
	int i, j;
	int num = 0, num2 = 0;
	char x = 'X';
	char o = 'O';
	for (i = 0;i < 3;i++) {
		if (board[i][0] == board[i][1] == board[i][2] == 'X') {
			return 1;
		}
		else if (board[i][0] == board[i][1] == board[i][2] == 'O') {
			return 2;
		}
		for (j = 0;j < 3;j++) {
			if (board[0][j] == board[1][j] == board[2][j] == 'X') {
				return 1;
			}
			else if (board[0][j] == board[1][j] == board[2][j] == 'O') {
				return 2;
			}
		}
	}
}

int used(vector<int>& vect, int num) {
	int i;
	for (i = 0; i < vect.size();i++) {
		if (vect[i] == num) {
			return 0;
		}
	}
	return 1;
}
void drawBoard(char board[][3]) {
	int i, j;
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<int> vect;
	int player1 = 1, player2 = 2;
	int x, o;
	int i, j;
	char toc;
	char board[3][3] = { {'0','1','2'},{'3','4','5'},{'6','7','8'} };
	drawBoard(board);
	while (true) {
		cout << "Player1: " << endl;
		cout << "Unesi broj polja: " << endl;
		cin >> x;
		while(used(vect, x) == 0) {
			cout << "Unesi ponovo: " << endl;
			cin >> x;
		}
		vect.push_back(x);
		toc = x + '0';
		for (i = 0;i < 3;i++) {
			for (j = 0;j < 3;j++) {
				if (board[i][j] == toc) {
					board[i][j] = 'X';
				}
			}
		}
		drawBoard(board);
		cout << "Player2: " << endl;
		cout << "Unesi broj polja: " << endl;
		cin >> x;
		while (used(vect, x) == 0) {
			cout << "Unesi ponovo: " << endl;
			cin >> x;
		}
		vect.push_back(x);
		toc = x + '0';
		for (i = 0;i < 3;i++) {
			for (j = 0;j < 3;j++) {
				if (board[i][j] == toc) {
					board[i][j] = 'O';
				}
			}
		}
		drawBoard(board);
	}
	
}