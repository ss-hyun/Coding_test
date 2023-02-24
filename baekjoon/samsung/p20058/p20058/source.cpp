#include <iostream>
#include <vector>

using namespace std;

int n, q, ice[64][64], copy_ice[64][64], N;
bool is_visit[64][64];
vector<int> levels, store_rotate;

void ice_print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ice[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void sub_grid_rotate(int split, int r, int c, int size) {
	if (split--) {
		size /= 2;
		sub_grid_rotate(split, r, c, size);
		sub_grid_rotate(split, r + size, c, size);
		sub_grid_rotate(split, r, c + size, size);
		sub_grid_rotate(split, r + size, c + size, size);
	}
	else {
		for (int j = c; j < c + size; j++) {
			for (int i = r + size - 1; i > r - 1; i--) {
				store_rotate.push_back(ice[i][j]);
			}
		}
		int idx = 0;
		for (int i = r; i < r + size; i++) {
			for (int j = c; j < c + size; j++) {
				ice[i][j] = store_rotate[idx++];
			}
		}
		store_rotate.clear();
	}
}

inline int adj_ice(int r, int c) {
	int ice_num = 0;
	if (r && copy_ice[r - 1][c])
		ice_num++;
	if (r < N - 1 && copy_ice[r + 1][c])
		ice_num++;
	if (c && copy_ice[r][c - 1])
		ice_num++;
	if (c < N - 1 && copy_ice[r][c + 1])
		ice_num++;
	return ice_num;
}

void reduce_ice() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_ice[i][j] = ice[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (copy_ice[i][j] && adj_ice(i, j) < 3)
				ice[i][j]--;
		}
	}
}

void firestorm() {
	for (int level : levels) {
		sub_grid_rotate(n - level, 0, 0, N);
		// ice_print();
		reduce_ice();
		// ice_print();
	}
	return;
}

int find_ice_block(int r, int c) {
	if (!ice[r][c])
		return 0;

	is_visit[r][c] = true;

	int ice_block = 1;

	if (r && !is_visit[r-1][c])
		ice_block += find_ice_block(r - 1, c);
	if (r < N - 1 && !is_visit[r+1][c])
		ice_block += find_ice_block(r + 1, c);
	if (c && !is_visit[r][c-1])
		ice_block += find_ice_block(r, c - 1);
	if (c < N - 1 && !is_visit[r][c+1])
		ice_block += find_ice_block(r, c + 1);

	return ice_block;
}

int main() {
	// input
	cin >> n >> q;
	N = (1 << n);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ice[i][j];
		}
	}
	int t;
	for (int i = 0; i < q; i++) {
		cin >> t;
		levels.push_back(t);
	}


	firestorm();


	// output
	int total_ice = 0, max_ice_num = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			total_ice += ice[i][j];
			if (!is_visit[i][j]) {
				t = find_ice_block(i, j);
				if (t > max_ice_num) max_ice_num = t;
			}
		}
	}
	cout << total_ice << '\n' << max_ice_num;

	return 0;
}