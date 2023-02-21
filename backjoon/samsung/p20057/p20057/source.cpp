#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define NONE 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
#define UP 4

// a: amout of sand, 둘레 2줄은 격자 바깥, 격자 시작 a[2][2], 끝 a[n+1][n+1]
int n, a[503][503], move_root[503][503], change_sand[5][5], center;
int mv[5][2] = { {0,0},{0,-1},{1,0},{0,1},{-1,0} }; // [direc][r:0, c:1]

void a_print() {
	for (int i = 0; i < n + 4; i++) {
		for (int j = 0; j < n + 4; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void change_print() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << change_sand[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

inline void record_root(int direc, int len, int *r, int *c) {
	for (int i = 0; i < len; i++) {
		move_root[*r][*c] = direc;
		(*r) += mv[direc][0];
		(*c) += mv[direc][1];
	}
}

void tornado_move_root() {
	int mv_len = 1, r = center, c = center;

	while (1) {
		record_root(LEFT, mv_len, &r, &c);
		if (r == 2 && c == 1)
			break;
		
		record_root(DOWN, mv_len, &r, &c);
		mv_len++;
		
		record_root(RIGHT, mv_len, &r, &c);
		record_root(UP, mv_len, &r, &c);
		mv_len++;
	}

	move_root[2][2] = NONE;
}

inline int pos(int d1, int d2, int rc) {
	return 2 + mv[d1][rc] + mv[d2][rc];
}

void record_change_amount(int direc, int amount) {	
	// d1: same, d2: +90 degree, d3: -90 degree, d4: opposite
	int d1 = direc, d2 = ((direc & 0x3) + 1), d3 = (((direc - 2) & 0x3) + 1), d4= (((direc + 1) & 0x3) + 1);
	int sum = 0;
	//cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4 << endl;

	change_sand[2][2] = -amount;

	sum += change_sand[pos(d1, d1, 0)][pos(d1, d1, 1)] = (int)(0.05 * amount);
	sum += change_sand[pos(d1, d2, 0)][pos(d1, d2, 1)] = (int)(0.1 * amount);
	sum += change_sand[pos(d1, d3, 0)][pos(d1, d3, 1)] = (int)(0.1 * amount);
	sum += change_sand[pos(d2, NONE, 0)][pos(d2, NONE, 1)] = (int)(0.07 * amount);
	sum += change_sand[pos(d3, NONE, 0)][pos(d3, NONE, 1)] = (int)(0.07 * amount);
	sum += change_sand[pos(d2, d2, 0)][pos(d2, d2, 1)] = (int)(0.02 * amount);
	sum += change_sand[pos(d3, d3, 0)][pos(d3, d3, 1)] = (int)(0.02 * amount);
	sum += change_sand[pos(d2, d4, 0)][pos(d2, d4, 1)] = (int)(0.01 * amount);
	sum += change_sand[pos(d3, d4, 0)][pos(d3, d4, 1)] = (int)(0.01 * amount);
	
	change_sand[pos(d1, NONE, 0)][pos(d1, NONE, 1)] = amount - sum;
}

void move_tornado() {
	int r = center, c = center, sand, direc;

	while (move_root[r][c]) {
		direc = move_root[r][c];
		//cout << "Direc: " << direc << endl;
		//cout << "r,c: " << r << ',' << c << endl;
		//a_print();

		r += mv[direc][0];
		c += mv[direc][1];

		sand = a[r][c];
		//cout << "Sand: " << sand << endl;
		//cout << "r,c: " << r << ',' << c << endl;

		memset(change_sand, 0, sizeof(change_sand));
		record_change_amount(direc, sand);
		//change_print();

		for (int i = -2; i < 3; i++) {
			for (int j = -2; j < 3; j++) {
				a[r + i][c + j] += change_sand[2 + i][2 + j];
			}
		}
	}
}

inline int raw_sum(int r) {
	int sum = 0;
	for (int i = 0; i < n + 4; i++)
		sum += a[r][i];
	return sum;
}

inline int col_sum(int c) {
	int sum = 0;
	for (int i = 2; i < n + 2; i++)
		sum += a[i][c];
	return sum;
}

int amount_sand_outside() {
	int sum = 0;
	sum += raw_sum(0);
	sum += raw_sum(1);
	sum += raw_sum(n + 2);
	sum += raw_sum(n + 3);

	sum += col_sum(0);
	sum += col_sum(1);
	sum += col_sum(n + 2);
	sum += col_sum(n + 3);

	return sum;
}

int main() {
	// input
	cin >> n;
	for (int i = 2; i < n + 2; i++) {
		for (int j = 2; j < n + 2; j++) {
			cin >> a[i][j];
		}
	}
	center = (n + 3) / 2;

	// write tornado move root
	tornado_move_root();

	// move tornado & record sand amount change
	move_tornado();
	//a_print();
	// output: caculate to the amount of sand outside of the grid
	cout << amount_sand_outside();

	return 0;
}


/*

토네이도 시전

> 토네이도 이동
> 가운데부터 시작, 나선형으로 좌측 방향부터 이동

>> 토네이도 이동 시, 모래가 흩날림
>> move x -> y 일때, 아래의 비율과 위치로 y에 있는 모래가 이동
	      0.02
	 0.1  0.07	0.01
0.05  a	    y     x
     0.1  0.07  0.01
	      0.02
>> 남은 모래는 a 위치로 모두 이동
>> 격자 밖으로 이동 가능

>>> 토네이도 소멸 시 격자 밖으로 나간 모래의 양?

- N은 홀수, 3~499
- 모래의 양 (input) 0~1000
- 가운데 칸의 모래의 양 0

*/