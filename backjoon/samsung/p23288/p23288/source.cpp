#include <iostream>
#include <memory.h>

using namespace std;

int n, m, k, map[20][20], direc, r, c, score;
int mv[4][2] = {
	{ 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }
};
int dice[6] = { 3,5,4,2,6,1 };//E,S,W,N,B,U

#define E 0
#define S 1
#define W 2
#define N 3
#define B 4
#define U 5

inline void clockwise() {
	direc = direc == 3 ? 0 : direc + 1;
}

inline void declockwise() {
	direc = direc == 0 ? 3 : direc - 1;
}

void init() {
	direc = 0;
	r = 0;
	c = 0;
	score = 0;
}

void move_dice() {
	int tmp;
	switch (direc)
	{
	case E:
		if (c == m - 1) {
			direc = W;
			move_dice();
			return;
		}
		tmp = dice[B]; dice[B] = dice[E]; dice[E] = dice[U];
		dice[U] = dice[W]; dice[W] = tmp;
		break;
	case S:
		if (r == n - 1) {
			direc = N;
			move_dice();
			return;
		}
		tmp = dice[B]; dice[B] = dice[S]; dice[S] = dice[U];
		dice[U] = dice[N]; dice[N] = tmp;
		break;
	case W:
		if (c == 0) {
			direc = E;
			move_dice();
			return;
		}
		tmp = dice[B]; dice[B] = dice[W]; dice[W] = dice[U];
		dice[U] = dice[E]; dice[E] = tmp;
		break;
	case N:
		if (r == 0) {
			direc = S;
			move_dice();
			return;
		}
		tmp = dice[B]; dice[B] = dice[N]; dice[N] = dice[U];
		dice[U] = dice[S]; dice[S] = tmp;
		break;
	default:
		break;
	}
	r += mv[direc][0];
	c += mv[direc][1];
}

bool visit[20][20];
int movable(int row, int column, int integer) {
	if (row == -1 || column == -1 || row == n || column == m 
		|| visit[row][column] || map[row][column] != integer)
		return 0;
	int num = 0;
	visit[row][column] = true;
	for (int i = 0; i < 4; i++)
		num += movable(row + mv[i][0], column + mv[i][1], integer);
	return ++num;
}

void get_score() {
	memset(visit, 0, sizeof(visit));
	score += map[r][c] * movable(r, c, map[r][c]);
}

void rotate() {
	if (dice[B] > map[r][c])
		clockwise();
	else if (dice[B] < map[r][c])
		declockwise();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		move_dice();
		get_score();
		rotate();
	}

	cout << score;

	return 0;
}