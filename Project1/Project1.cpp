#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;

void Win() {
	cout << "You Won!" << endl;
}

void symbol(char loc[23][44], int score) {
	for (int a{}; a < 23; a++) {
		for (int b{}; b < 44; b++) {
			cout << loc[a][b];
		}
		cout << endl;
	}
	cout << "Score: " << score << endl;
}

void keydown(char loc[23][44], int x, int y, int score) {
	char key;
	key = _getch();
	if (key == 'w') {
		if (loc[y - 1][x] != '#') {
			if (loc[y - 1][x] == '.') {
				score = score + 1;
			}
			loc[y][x] = ' ';
			loc[y - 1][x] = '@';
			y = y - 1;
		}
	} else if (key == 's') {
		if (loc[y + 1][x] != '#') {
			if (loc[y + 1][x] == '.') {
				score = score + 1;
			}
			loc[y][x] = ' ';
			loc[y + 1][x] = '@';
			y = y + 1;
		}
	} else if (key == 'd') {
		if (loc[y][x + 1] != '#') {
			if (loc[y][x + 1] == '.') {
				score = score + 1;
			}
			loc[y][x] = ' ';
			loc[y][x + 1] = '@';
			x = x + 1;
		}
	} else if (key == 'a') {
		if (loc[y][x - 1] != '#') {
			if (loc[y][x - 1] == '.') {
				score = score + 1;
			}
			loc[y][x] = ' ';
			loc[y][x - 1] = '@';
			x = x - 1;
		}
	}
	system("cls");
	if (score == 421) {
		Win();
	}
	else {
		symbol(loc, score);
		keydown(loc, x, y, score);
	}
}

int main()
{

	SetConsoleTitle(TEXT("MeqaPacman"));
	srand(time(NULL));
	char loc[23][44] = { 
		{'#', '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'#', '@','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
		{'#', '.','.','#','#','#','#','#','#','.','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','.','.','#','#','.','.','#','#','#','#','#','#','.','.','#','#','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','#','#','#','#','.','.','#','#','.','.','.','.','.','.','#','#','.','.','#','#','.','.','#','#','#','#','#','#','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','.','.','.','.','.','.','.','.','#','.','#','#','.','#','.','.','#','#','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','.','.','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','.','.','#','#','.','.','.','.','.','.','.','.','#','#','.','.','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','#','#','.','.','.','.','.','.','.','.','#','#','.','.','#','#','#','#','.','.','#','#','#','#','#','#','.','.','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','.','.','#','#','.','.','.','.','.','.','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#'},
		{'#', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
		{'#', '.','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','#','#','#','#','.','.','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','#','#','#','#','.','.','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','.','.','.','.','.','.','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','.','.','#','#','.','.','#','#','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','.','.','#'},
		{'#', '.','.','.','.','.','.','#','#','.','.','#','#','.','.','.','.','.','.','#','#','.','.','#','#','.','.','#','#','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','.','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','.','.','.','.','.','.','.','.','#','#','#','#','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#'},
		{'#', '.','.','#','#','.','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#'},
		{'#', '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
		{'#', '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	};
	int x{ 1 }, y{ 1 };
	symbol(loc, 1);
	keydown(loc, x, y, 420);
}