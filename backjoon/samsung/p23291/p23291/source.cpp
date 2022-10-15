#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, cnt;
vector<vector<int>> fishbowls;

void init() {
	cnt = 0;
	vector<int> fishbowl;
	fishbowls.push_back(fishbowl);
}

void print() {
	for (vector<int> fishbowl : fishbowls) {
		for (int fish : fishbowl) {
			cout << fish << ' ';
		}
		cout << '\n';
	}
}

int diff_fish_num() {
	int min_fish = 100001, max_fish = -1;
	for (int fish : fishbowls[0]) {
		if (fish > max_fish) max_fish = fish;
		if (fish < min_fish) min_fish = fish;
	}
	return max_fish - min_fish;
}

void add_fish() {
	int min_fish = 100001;
	for (int fish : fishbowls[0])
		if (fish < min_fish) min_fish = fish;
	for (int i = 0; i < fishbowls[0].size(); i++) {
		if (fishbowls[0][i] == min_fish)
			fishbowls[0][i]++;
	}
}

void roll() {
	vector<vector<int>> next;
	vector<int> fishbowl;
	fishbowl.push_back(fishbowls[0].front());
	next.push_back(fishbowl);
	fishbowl.clear();
	fishbowl.insert(fishbowl.begin(), fishbowls[0].begin() + 1, fishbowls[0].end());
	next.push_back(fishbowl);
	fishbowls = next;
	while (fishbowls.size() <= fishbowls.back().size() - fishbowls[0].size()) {
		next.clear();
		fishbowl.clear();
		for (int i = 0; i < fishbowls[0].size(); i++) {
			for (int j = fishbowls.size() - 1; j >= 0; j--) {
				fishbowl.push_back(fishbowls[j][i]);
			}
			next.push_back(fishbowl);
			fishbowl.clear();
		}
		fishbowl.insert(fishbowl.begin()
			, fishbowls[fishbowls.size() - 1].begin() + fishbowls[0].size()
			, fishbowls[fishbowls.size() - 1].end());
		next.push_back(fishbowl);
		fishbowls = next;
	}
}

void move_fish() {
	int fish;
	vector<vector<int>> next(fishbowls);
	for (int i = 0; i < fishbowls.size(); i++) {
		for (int j = 0; j < fishbowls[i].size(); j++) {
			if (j != fishbowls[i].size()-1) {
				fish = (fishbowls[i][j] - fishbowls[i][j + 1]) / 5;
				next[i][j] += -fish;
				next[i][j+1] += fish;
			}
			if (i != fishbowls.size() - 1) {
				fish = (fishbowls[i][j] - fishbowls[i+1][j]) / 5;
				next[i][j] += -fish;
				next[i+1][j] += fish;
			}
		}
	}
	fishbowls = next;
}

void flat() {
	vector<vector<int>> next;
	vector<int> fishbowl;
	for (int i = 0; i < fishbowls[0].size(); i++) {
		for (int j = fishbowls.size() - 1; j >= 0; j--) {
			fishbowl.push_back(fishbowls[j][i]);
		}
	}
	fishbowl.insert(fishbowl.end()
		, fishbowls[fishbowls.size() - 1].begin() + fishbowls[0].size()
		, fishbowls[fishbowls.size() - 1].end());
	fishbowls.clear();
	fishbowls.push_back(fishbowl);
}

void divide_half() {
	vector<vector<int>> next;
	vector<int> fishbowl;
	int size = fishbowls[0].size() / 2;

	// step 1
	fishbowl.insert(fishbowl.begin(), fishbowls[0].begin(), fishbowls[0].begin() + size);
	reverse(fishbowl.begin(), fishbowl.end());
	next.push_back(fishbowl);
	fishbowl.clear();
	fishbowl.insert(fishbowl.begin(), fishbowls[0].begin() + size, fishbowls[0].end());
	next.push_back(fishbowl);
	fishbowl.clear();

	//step 2
	fishbowls.clear();
	size /= 2;

	fishbowl.insert(fishbowl.begin(), next[1].begin(), next[1].begin() + size);
	reverse(fishbowl.begin(), fishbowl.end());
	fishbowls.push_back(fishbowl);
	fishbowl.clear();
	fishbowl.insert(fishbowl.begin(), next[0].begin(), next[0].begin() + size);
	reverse(fishbowl.begin(), fishbowl.end());
	fishbowls.push_back(fishbowl);
	fishbowl.clear();

	fishbowl.insert(fishbowl.begin(), next[0].begin() + size, next[0].end());
	fishbowls.push_back(fishbowl);
	fishbowl.clear();
	fishbowl.insert(fishbowl.begin(), next[1].begin() + size, next[1].end());
	fishbowls.push_back(fishbowl);
}

int main() {
	int temp;
	cin >> n >> k;
	init();
	for (int i = 0; i < n; i++) {
		cin >> temp;
		fishbowls[0].push_back(temp);
	}

	while (diff_fish_num() > k) {
		add_fish();
		roll();
		move_fish();
		flat();
		divide_half();
		move_fish();
		flat();
		cnt++;
	}

	cout << cnt;

	return 0;
}