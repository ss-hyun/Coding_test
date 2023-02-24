#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, student[21][21];
vector<int> like[401];

inline bool in(int i, int j) {
	return (i > 0 && j > 0 && i <= n && j <= n);
}

inline bool isEmpty(int i, int j) {
	return student[i][j] == 0;
}

int num_like(int i, int j, int s) {
	int num = 0;
	vector<int>::iterator it;

	if (in(i - 1, j)) {
		if (find(like[s].begin(), like[s].end(), student[i-1][j]) != like[s].end())
			num++;
	}
	if (in(i, j - 1)) {
		if (find(like[s].begin(), like[s].end(), student[i][j-1]) != like[s].end())
			num++;
	}
	if (in(i, j + 1)) {
		if (find(like[s].begin(), like[s].end(), student[i][j+1]) != like[s].end())
			num++;
	}
	if (in(i + 1, j)) {
		if (find(like[s].begin(), like[s].end(), student[i+1][j]) != like[s].end())
			num++;
	}

	return num;
}

int num_empty(int i, int j, int s) {
	int num = 0;

	if (in(i - 1, j) && isEmpty(i-1, j)) {
		num++;
	}
	if (in(i, j - 1) && isEmpty(i, j-1)) {
		num++;
	}
	if (in(i, j + 1) && isEmpty(i, j+1)) {
		num++;
	}
	if (in(i + 1, j) && isEmpty(i+1, j)) {
		num++;
	}

	return num;
}

int max_like, emp, r, c;

void check(int i, int j, int s) {
	int tmp;

	tmp = num_like(i, j, s);
	if (tmp > max_like) {
		max_like = tmp;
		emp = num_empty(i, j, s);
		r = i;
		c = j;
	}
	else if (tmp == max_like) {
		tmp = num_empty(i, j, s);
		if (tmp > emp) {
			emp = tmp;
			r = i;
			c = j;
		}
	}

}

void place(int s) {
	max_like = -1, emp = -1, r = 0, c = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (isEmpty(i, j)) check(i, j, s);
		}
	}

	student[r][c] = s;
}

int satisfied() {
	int num = 0;

	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tmp = num_like(i, j, student[i][j]);
			if (tmp == 1) 
				num += 1;
			if (tmp == 2)
				num += 10;
			if (tmp == 3)
				num += 100;
			if (tmp == 4)
				num += 1000;
		}
	}

	return num;
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << student[i][j] << ' ';
		}
		cout << '\n';
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	int s, tmp;
	for (int i = 0; i < n*n; i++) {
		cin >> s;
		for (int j = 0; j < 4; j++) {
			cin >> tmp;
			like[s].push_back(tmp);
		}
		place(s);
		//print();
	}

//	print();

	cout << satisfied() << '\n';

	return 0;
}