#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;
char board[10][10];
int x = 0, y = 0;

enum FIELDS {
	FLD_EMPTY = ' ',
	FLD_TAKE = '*',
	FLD_WALL = 'X',
	FLD_PLAYER = '@',
	FLD_QUEST = '?',
	FLD_ARROW = '>',
};

enum GAMESTATE {
	GS_START, GS_END,
};
void set_fields() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = FLD_EMPTY;
		}
	}
}

void draw_board() {
	cout << string(5, '\n');
	for (int i = 0; i < 12; i++) {
		if (i == 1)
			cout << " O";
		else
			cout << " H";
	}

	cout << endl;
	for (int i = 0; i < 10; i++) {
		if (i != 0)
			cout << endl;
		if (i != 10)
			cout << " " << "H";

		for (int j = 0; j < 10; j++) {
			if (j == 0)
				cout << " ";

			cout << board[i][j] << " ";
			if (j == 9)
				cout << "H";
		}
	}
	cout << endl;

	for (int i = 0; i < 12; i++) {
		if (i == 10)
			cout << " O";
		else
			cout << " H";
	}
}

int main() {
	GAMESTATE game_state;
	game_state = GS_START;
	set_fields();
	draw_board();
	board[x][y] = FLD_PLAYER;
	char kierunek;
	char answer, good_answer = 'c';
	bool quest = false;
	system("cls");
//RYSOWANIE SCIAN

	for (int i = 0; i < 3; i++)
		board[i][1] = FLD_WALL;
	for (int i = 0; i < 4; i++)
		board[4][i] = FLD_WALL;
	board[3][3] = FLD_WALL;
	board[1][3] = FLD_WALL;
	board[1][4] = FLD_WALL;
	board[0][6] = FLD_WALL;
	board[1][8] = FLD_WALL;
	board[1][9] = FLD_WALL;
	for (int i = 2; i < 9; i++)
		board[i][5] = FLD_WALL;
	for (int i = 6; i < 10; i++)
		board[2][i] = FLD_WALL;
	board[8][0] = FLD_WALL;
	for (int i = 1; i < 5; i++)
		board[6][i] = FLD_WALL;
	board[7][2] = FLD_WALL;
	board[7][3] = FLD_WALL;
	board[8][3] = FLD_WALL;
	for (int i = 0; i < 4; i++)
		board[9][i] = FLD_WALL;
	board[8][6] = FLD_WALL;
	for (int i = 4; i < 10; i++)
		board[i][8] = FLD_WALL;
	board[5][7] = FLD_WALL;
	board[6][7] = FLD_WALL;
	board[8][2] = FLD_QUEST;
	board[0][9] = FLD_TAKE;


//////////////
	do {
		draw_board();
		cout << endl << "Podaj kierunek:" << endl;
		kierunek = getch();
		if (kierunek == 's') {

			if ((x + 1 > 9) or (board[x + 1][y] == FLD_WALL)) {
				cout << "SCIANA!";
				Sleep(300);
			} else {
				x++;

				board[x - 1][y] = FLD_EMPTY;
				board[x][y] = FLD_PLAYER;
			}
		} else if (kierunek == 'd') {

			if ((y + 1 > 9) or (board[x][y + 1] == FLD_WALL)) {
				cout << "SCIANA!";
				Sleep(300);
			}

			else {
				y++;

				board[x][y - 1] = FLD_EMPTY;
				board[x][y] = FLD_PLAYER;
			}
		} else if (kierunek == 'a') {
			if ((y - 1 < 0) or (board[x][y - 1] == FLD_WALL)) {
				cout << "SCIANA!";
				Sleep(300);
			}

			else {
				y--;

				board[x][y + 1] = FLD_EMPTY;
				board[x][y] = FLD_PLAYER;
			}
		} else if (kierunek == 'w') {

			if ((x - 1 < 0) or (board[x - 1][y] == FLD_WALL)) {
				cout << "SCIANA!";
				Sleep(300);
			} else {
				x--;

				board[x + 1][y] = FLD_EMPTY;
				board[x][y] = FLD_PLAYER;
			}
		}

		if ((board[8][2] == FLD_PLAYER) && (quest == false)) {
			cout << "Aby przejść dalej musisz rozwiązać zagadkę." << endl;
			cout << "Zagadka Sfinksa:" << endl;
			cout << "Rano chodzi na czterech łapach," << endl
					<< "wieczorem na trzech," << endl
					<< "A w południe na dwóch?" << endl;
			cout << "a) pies," << endl << "b) niedźwiedź," << endl
					<< "c) człowiek," << endl << "d) inne zwierze" << endl;
			cout << "Podaj odpowiedź: " << endl;
			cin >> answer;
			if (answer == good_answer) {
				board[8][3] = FLD_EMPTY;
				quest = true;
			}
		}
		if (quest != true)
			board[8][2] = FLD_QUEST;
		else
			board[8][2] = FLD_ARROW;
		if ((board[0][9] == FLD_EMPTY) && (board[9][9] == FLD_PLAYER))
			game_state = GS_END;

		system("cls");
	} while (game_state != GS_END);
	draw_board();
	cout << endl << "GRATULACJE! \nUdało ci się przejść cały labirynt.";
	return 0;
}
*/
