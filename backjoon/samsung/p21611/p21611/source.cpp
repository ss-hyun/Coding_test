#include <iostream>
#include <vector>

using namespace std;

int n, m, loc_number[49][49], cur, shark, r, c, ans;
vector<int> bead[2], ice;

#define before (cur ? 0 : 1)
#define next (cur ? 0 : 1)
#define L (3)
#define D (2)
#define R (4)
#define U (1)

int record(int way, int dist, int num) {
	int addr, addc;
	switch (way)
	{
	case L:
		addr = 0; addc = -1; break;
	case D:
		addr = 1; addc = 0; break;
	case R:
		addr = 0; addc = 1; break;
	case U:
		addr = -1; addc = 0; break;
	default:
		addr = 0; addc = 0; break;
	}

	for (int i = 0; i < dist; i++) {
		r += addr; c += addc;
		loc_number[r][c] = ++num;
	}

	return num;
}

void init() {
	cur = 0;
	bead[0].assign(n*n, 0);
	bead[1].reserve(n*n);
	ice.reserve(24);
	shark = n / 2;
	r = shark, c = shark;
	int num = 0;
	for (int i = 0; i < shark; i++) {
		num = record(L, 2 * i + 1, num);
		num = record(D, 2 * i + 1, num);
		num = record(R, 2 * i + 2, num);
		num = record(U, 2 * i + 2, num);
	}
	num = record(L, n - 1, num);
	//if (num != n * n - 1) 
	//	cout << "init fail!" << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bead[cur][loc_number[i][j]];
		}
	}
}

void blzad(int d, int s) {
	int addr, addc, nt = next;
	switch (d)
	{
	case L:
		addr = 0; addc = -1; break;
	case D:
		addr = 1; addc = 0; break;
	case R:
		addr = 0; addc = 1; break;
	case U:
		addr = -1; addc = 0; break;
	default:
		addr = 0; addc = 0; break;
	}
	r = c = shark;
	for (int i = 0; i < s; i++) {
		r += addr; c += addc;
		ice.push_back(loc_number[r][c]);
	}

	vector<int>::iterator it = ice.begin();
	for (int i = 0; i < bead[cur].size(); i++) {
		if (it == ice.end() || *it != i)
			bead[nt].push_back(bead[cur][i]);
		else it++;
	}
	bead[cur].clear();
	cur = nt;
	ice.clear();
}

void bomb() {
	int cnt, num, nt = next;
	
	while (bead[cur].size() != bead[nt].size()) {
		bead[nt].clear();
		cnt = 0, num = 0;
		bead[nt].push_back(0);
		for (int number : bead[cur]) {
			if (num == number) {
				cnt++;
			}
			else {
				if (cnt < 4) {
					if (num) {
						while (cnt--) bead[nt].push_back(num);
					}
				}
				else
					ans += num * cnt;
				cnt = 1;
				num = number;
			}
		}
		if (cnt < 4 && num) {
			while (cnt--) bead[nt].push_back(num);
		}
		else
			ans += num * cnt;
		cur = nt; nt = next;
	}
}

void change() {
	int cnt = 0, num = 0, nt = next;
	vector<int>::iterator it = bead[cur].begin();
	bead[nt].clear();
	bead[nt].push_back(0);
	while (it != bead[cur].end()) {
		if (num == *it) {
			cnt++;
		}
		else {
			if (num) {
				bead[nt].push_back(cnt);
				bead[nt].push_back(num);
				if (bead[nt].size() == n * n)
					break;
			}
			num = *it; cnt = 1;
		}
		it++;
	}
	if (num && bead[nt].size() != n * n) {
		bead[nt].push_back(cnt);
		bead[nt].push_back(num);
	}
	bead[cur].clear();
	cur = nt;
}

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bead[cur].size() > loc_number[i][j])
				cout << bead[cur][loc_number[i][j]] << ' ';
			else
				cout << "0 ";
		}
		cout << '\n';
	}
	for (int i : bead[cur])
		cout << i << ' ';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	init();
	int d, s;
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		blzad(d, s);
		bomb();
		change();
	}
	cout << ans;

	return 0;
}