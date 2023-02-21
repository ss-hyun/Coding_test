#include <iostream>
#include <vector>
#include <deque>
#include <stdio.h>

using namespace std;

typedef struct position {
	int r, c;
}position;

typedef struct fireBall {
	int m, d, s;
}fireBall;

int n, m, k;
deque<fireBall> fireball[50][50];
int num_fireball[50][50];
vector<position> pos_fireball;

// direc[][0]: r, direc[][1]: c
int direc[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

void print_fireball() {
	return;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cout << num_fireball[r][c] << '/' << fireball[r][c].size() << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (fireball[r][c].size()) {
				printf("<%d, %d>\n", r, c);
				for (fireBall f : fireball[r][c]) {
					printf("\tm: %d, s: %d, d: %d\n", f.m, f.s, f.d);
				}
			}
		}
	}
	cout << endl;
}

int main() {
	// input
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		fireBall f; int r, c;
		cin >> r >> c >> f.m >> f.s >> f.d;
		r--; c--;
		fireball[r][c].push_back(f);
		if (!num_fireball[r][c]) pos_fireball.push_back({ r, c });
		num_fireball[r][c]++;
	}

	// order to move
	for (int i = 0; i < k; i++) {
		//cout << "fireball position num: " << pos_fireball.size() << endl;
		print_fireball();
		// step 1: move fireball
		for (position p : pos_fireball) {
			for (int j = 0; j < num_fireball[p.r][p.c]; j++) {
				fireBall f = fireball[p.r][p.c][j];
				int r = p.r, c = p.c;
				r += (direc[f.d][0] * f.s) % n;
				if (r < 0) r += n;
				else if (r > n - 1) r -= n;

				c += (direc[f.d][1] * f.s) % n;
				if (c < 0) c += n;
				else if (c > n - 1) c -= n;

				fireball[r][c].push_back(f);
				//printf("%d,%d > %d,%d\tm: %d, s: %d, d: %d\n", p.r, p.c, r, c, f.m, f.s, f.d);
			}
		}
		//print_fireball();
		pos_fireball.clear();

		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				if (num_fireball[r][c]) {
					fireball[r][c].erase(fireball[r][c].begin(), fireball[r][c].begin() + num_fireball[r][c]);
					num_fireball[r][c] = 0;
				}
				if (fireball[r][c].size() != 0) {
					num_fireball[r][c] = fireball[r][c].size();
					pos_fireball.push_back({ r,c });
				}
			}
		}
		//cout << "fireball position num: " << pos_fireball.size() << endl;
		print_fireball();

		// step 2: if, num_fireball >= 2
		for (int j = 0; j < pos_fireball.size(); j++) {
			position p = pos_fireball[j];
			if (num_fireball[p.r][p.c] > 1) {
				int m = 0, s = 0;
				int odd = 0, even = 0;
				for (fireBall f : fireball[p.r][p.c]) {
					m += f.m;
					s += f.s;
					if (f.d & 1) odd++;
					else even++;
				}

				m = m / 5;
				s = s / num_fireball[p.r][p.c];

				fireball[p.r][p.c].clear();
				if (m) {
					num_fireball[p.r][p.c] = 4;
					if (odd && even) {	// mismatch - 1,3,5,7
						fireball[p.r][p.c].push_back({ m,1,s });
						fireball[p.r][p.c].push_back({ m,3,s });
						fireball[p.r][p.c].push_back({ m,5,s });
						fireball[p.r][p.c].push_back({ m,7,s });
					}
					else {	// all odd or all even - 0,2,4,6
						fireball[p.r][p.c].push_back({ m,0,s });
						fireball[p.r][p.c].push_back({ m,2,s });
						fireball[p.r][p.c].push_back({ m,4,s });
						fireball[p.r][p.c].push_back({ m,6,s });
					}
				}
				else {
					num_fireball[p.r][p.c] = 0;
					pos_fireball.erase(pos_fireball.begin() + j);
					j--;
				}
			}
		}
	}

	int m_sum = 0;
	for (position p : pos_fireball) {
		for (fireBall f : fireball[p.r][p.c]) {
			m_sum += f.m;
		}
	}

	cout << m_sum;

	return 0;
}