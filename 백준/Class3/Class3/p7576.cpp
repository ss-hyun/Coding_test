// 백준 7576번 토마토
#include <iostream>
#include <deque>

using namespace std;
int state_tomato[1000][1000];;

void p7576(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int m, n;
	deque<pair<int, int>> list_ripen;

	cin >> m >> n;
	int num_tomato = m*n, ripen_tomato = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> state_tomato[i][j];
			if (state_tomato[i][j] == -1)
				num_tomato--;
			else if (state_tomato[i][j] == 1){
				list_ripen.push_back({ i, j });
				ripen_tomato++;
			}
		}
	}
	list_ripen.push_back({ -1, -1 });

	pair<int, int> direction[4] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
	int day = 0, yesterday = -1, a, b;
	while (ripen_tomato != num_tomato){
		if (ripen_tomato == yesterday){
			cout << -1;
			return;
		}
		yesterday = ripen_tomato; day++;
		while(1){
			if (list_ripen[0].first == -1 && list_ripen[0].second == -1)
				break;
			for (int k = 0; k < 4; k++){
				a = list_ripen[0].first + direction[k].first;
				b = list_ripen[0].second + direction[k].second;
				if (a > -1 && a < n && b > -1 && b < m){
					if (state_tomato[a][b] == 0){
						state_tomato[a][b] = 1;
						ripen_tomato++;
						list_ripen.push_back({ a, b });
					}
				}
			}
			list_ripen.pop_front();
		}
		list_ripen.pop_front();
		list_ripen.push_back({ -1, -1 });
	}
	cout << day;

	return;
}