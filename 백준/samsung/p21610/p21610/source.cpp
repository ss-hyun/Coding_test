#include <iostream>
#include <vector>

using namespace std;

int n, m, water[50][50], d, s, move_c, move_r, total_water;
bool is_cloud[50][50];
vector<pair<int,int>> cloud;

#define LEFT 1
#define UPLEFT 2
#define UP 3
#define UPRIGHT 4
#define RIGHT 5
#define DOWNRIGHT 6
#define DOWN 7
#define DOWNLEFT 8

void init_cloud() {
	cloud.reserve(100);
	cloud.push_back({ n-1, 0 });
	cloud.push_back({ n-1, 1 });
	cloud.push_back({ n-2, 0 });
	cloud.push_back({ n-2, 1 });
}

void move_and_rain(int d, int s) {
	switch (d)
	{
	case LEFT:
		move_c = -s;
		move_r = 0;
		break;
	case UPLEFT:
		move_c = -s;
		move_r = -s;
		break;
	case UP:
		move_c = 0;
		move_r = -s;
		break;
	case UPRIGHT:
		move_c = s;
		move_r = -s;
		break;
	case RIGHT:
		move_c = s;
		move_r = 0;
		break;
	case DOWNRIGHT:
		move_c = s;
		move_r = s;
		break;
	case DOWN:
		move_c = 0;
		move_r = s;
		break;
	case DOWNLEFT:
		move_c = -s;
		move_r = s;
		break;
	default:
		move_c = 0;
		move_r = 0;
		break;
	}

	for (int i = 0; i < cloud.size(); i++) {
		cloud[i].first += move_r;
		while (cloud[i].first > n - 1) cloud[i].first -= n;
		while (cloud[i].first < 0) cloud[i].first += n;
		cloud[i].second += move_c;
		while (cloud[i].second > n - 1) cloud[i].second -= n;
		while (cloud[i].second < 0) cloud[i].second += n;

		is_cloud[cloud[i].first][cloud[i].second] = true;
		water[cloud[i].first][cloud[i].second] += 1;
	}
}

void copy_water() {
	for (pair<int, int> c : cloud) {
		if (c.first - 1 > -1 && c.second - 1 > -1 && water[c.first - 1][c.second - 1])
			water[c.first][c.second]++;
		if (c.first - 1 > -1 && c.second + 1 < n && water[c.first - 1][c.second + 1])
			water[c.first][c.second]++;
		if (c.first + 1 < n && c.second + 1 < n && water[c.first + 1][c.second + 1])
			water[c.first][c.second]++;
		if (c.first + 1 < n && c.second - 1 > -1 && water[c.first + 1][c.second - 1])
			water[c.first][c.second]++;
	}
	cloud.clear();
}

void make_cloud() {
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n;j++) {
			if (is_cloud[i][j]) 
				is_cloud[i][j] = false;
			else if (water[i][j] > 1) {
				water[i][j] -= 2;
				cloud.push_back({ i, j });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> water[i][j];
		}
	}

	init_cloud();
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		move_and_rain(d, s);
		copy_water();
		make_cloud();
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			total_water += water[i][j];
		}
	}

	cout << total_water << '\n';

	return 0;
}