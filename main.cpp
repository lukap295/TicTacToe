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
		if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
			return 1;
		}
		else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
			return 2;
		}
		for (j = 0;j < 3;j++) {
			if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') {
				return 1;
			}
			else if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O') {
				return 2;
			}
		}
	}
	if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'))
		return 1;
	else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'))
		return 2;
	else
		return 0;
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
			cout << board[i][j] << "  ";
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
	while (vect.size() < 9) {
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
					break;
				}
			}
		}
		if (vect.size() == 9) {
			break;
		}
		drawBoard(board);
		if (gameover(board) == 1) {
			cout << "Player1 is the winner!" << endl;
			return 0;
		}
		else if (gameover(board) == 2) {
			cout << "Player2 is the winner!" << endl;
			return 0;
		}
		else
			goto player2;
		player2:
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
					break;
				}
			}
		}
		drawBoard(board);
		if (gameover(board) == 1) {
			cout << "Player1 is the winner!" << endl;
			return 0;
		}
		else if (gameover(board) == 2) {
			cout << "Player2 is the winner!" << endl;
			return 0;
		}
		else
			continue;
	}
	if (gameover(board) == 0) {
		cout << "It's a draw!" << endl;
	}
	
}
