#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <math.h>

using namespace std;

int t, n, k;
deque<char> line;
vector<int> number;

void init() {
	line.clear();
	number.clear();
}

int str_to_num(string s) {
	int num = 0, cnt = s.size();
	for (char c : s) {
		cnt--;
		if (isdigit(c))
			num += (c - '0') * pow(16, cnt);
		else 
			num += (c - 'A' + 10) * pow(16, cnt);
	}
	return num;
}

void get_num() {
	string s = "";
	int nn = n / 4;
	for (int j = 0; j < nn; j++) {
		for (int i = 0; i < n; i++) {
			s.push_back(line[i]);
			if (i % nn == nn - 1) {
				number.push_back(str_to_num(s));
				s.clear();
			}
		}
		line.push_front(line.back());
		line.pop_back();
	}
}

bool compare(int i, int j) {
	return j < i;
}

int pick_num() {
	sort(number.begin(), number.end(), compare);
	number.erase(unique(number.begin(), number.end()), number.end());
	return number[k-1];
}

int main() {
	char c;

	cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			cin >> c;
			line.push_back(c);
		}
		get_num();
		pick_num();
		cout << '#' << i+1 << ' ' << pick_num() << '\n';
	}


	return 0;
}