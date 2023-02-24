#include <iostream>
#include <vector>

using namespace std;

int m, s, smell[4][4], shark_r, shark_c, cur;
vector<int> fish[2][4][4];

int move_direc[8][2] = {
	{ 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 },
	{ 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }
};

#define VANISH 4

void init() {
	for (int n = 0; n < 2; n++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				fish[n][i][j].reserve(1000000);
			}
		}
	}
}

void move_fish() {
	int bf = cur ? 0 : 1, r, c, cnt;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int f : fish[bf][i][j]) {
				for (cnt = 0; cnt < 8; cnt++) {
					r = i + move_direc[f - 1][0];
					c = j + move_direc[f - 1][1];
					if (r > -1 && r < 4 && c > -1 && c < 4 && smell[r][c] == 0
												&& !(r == shark_r && c == shark_c)) {
						fish[cur][r][c].push_back(f);
						break;
					}
					f = f == 1 ? 8 : f - 1;
				}
				if (cnt == 8)
					fish[cur][i][j].push_back(f);
			}
		}
	}
}

int fish_num[4][4], max_fish, visit[4][4];
vector<pair<int, int>> tmp(3), stemp;
void move(int n, int r, int c, int sum) {
	bool push = false;

	if (n == 3)
		goto first;

	if (!visit[r][c]) {
		if (fish_num[r][c] != 0) {
			sum = sum + fish_num[r][c];
			tmp.push_back({ r, c });
			push = true;
		}
	}
	visit[r][c]++;

	if (n == 0) {
		if (max_fish < sum) {
			max_fish = sum;
			shark_r = r;
			shark_c = c;
			stemp.assign(tmp.begin(), tmp.end());
		}
		goto end;
	}


first:
	if (r != 0) {
		move(n - 1, r - 1, c, sum);
	}
	if (c != 0) {
		move(n - 1, r, c - 1, sum);
	}
	if (r != 3) {
		move(n - 1, r + 1, c, sum);
	}
	if (c != 3) {
		move(n - 1, r, c + 1, sum);
	}
	
end:
	if (n != 3) visit[r][c]--;
	if (push) tmp.pop_back();
	return;
}

void move_shark() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fish_num[i][j] = fish[cur][i][j].size();
		}
	}

	tmp.clear();
	stemp.clear();
	max_fish = -1;

	move(3, shark_r, shark_c, 0);

	for (pair<int,int> i : stemp) {
		smell[i.first][i.second] += 4;
		fish[cur][i.first][i.second].clear();
	}
}

void rm_smell_cp_fish() {
	int bf = cur ? 0 : 1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			smell[i][j] >>= 1;
			fish[cur][i][j].insert(fish[cur][i][j].end(), fish[bf][i][j].begin(), fish[bf][i][j].end());
			fish[bf][i][j].clear();
		}
	}
}

int main() {
	int r, c, d, total_fish = 0;

	init();

	cin >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> d;
		fish[cur][r - 1][c - 1].push_back(d);
	}
	cin >> shark_r >> shark_c;
	shark_r--;
	shark_c--;

	for (int i = 0; i < s; i++) {
		cur = cur ? 0 : 1;
		move_fish();
		move_shark();
		rm_smell_cp_fish();
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			total_fish += fish[cur][i][j].size();
		}
	}

	cout << total_fish;

	return 0;
}