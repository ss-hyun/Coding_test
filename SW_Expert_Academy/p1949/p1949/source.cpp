#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef struct grid {
	int r, c;
}grid;

int t, n, k, map[8][8];
vector<grid> top, track;

int find_max() {
	int m = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > m)
				m = map[i][j];
		}
	}
	return m;
}

vector<grid> temp;
bool visit[8][8], usek;
void find_tracks(grid g);

void next_step(grid n, int h) {
	if (map[n.r][n.c] < h) {
		find_tracks(n);
	}
	else if (!usek) {
		usek = true;
		for (int i = 1; i <= k; i++) {
			if (map[n.r][n.c]-i < h) {
				map[n.r][n.c] -= i;
				find_tracks(n);
				map[n.r][n.c] += i;
				break;
			}
		}
		usek = false;
	}
}

void find_tracks(grid g) {
	if (visit[g.r][g.c])
		return;
	visit[g.r][g.c] = true;
	temp.push_back(g);

	if (temp.size() > track.size())
		track = temp;

	int height = map[g.r][g.c];
	grid next;
	if (g.r != 0) {
		next.r = g.r - 1; next.c = g.c;
		next_step(next, height);
	}
	if (g.c != 0) {
		next.r = g.r; next.c = g.c - 1;
		next_step(next, height);
	}
	if (g.r != n - 1) {
		next.r = g.r + 1; next.c = g.c;
		next_step(next, height);
	}
	if (g.c != n - 1) {
		next.r = g.r; next.c = g.c + 1;
		next_step(next, height);
	}

	temp.pop_back();
	visit[g.r][g.c] = false;
}

void find_track() {
	int high = find_max();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == high)
				top.push_back({ i, j });
		}
	}
	for (grid g : top) {
		find_tracks(g);
	}
}

void init() {
	memset(map, 0, sizeof(map));
	top.clear();
	track.clear();
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		cin >> n >> k;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++)
				cin >> map[r][c];
		}
		find_track();
		cout << '#' << i + 1 << ' ' << track.size() << '\n';
	}

	return 0;
}