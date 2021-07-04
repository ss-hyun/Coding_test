#include <iostream>

using namespace std;

// 백준 1012번 유기농 배추
void dfs(int x, int y, int n, int m, bool field[][50]){
	// 위, 아래, 왼, 오른 순서로 확인
	field[y][x] = false;
	if (y && field[y - 1][x])
		dfs(x, y - 1, n, m, field);
	if (y < n - 1 && field[y + 1][x])
		dfs(x, y + 1, n, m, field);
	if (x && field[y][x - 1])
		dfs(x - 1, y, n, m, field);
	if (x < m - 1 && field[y][x + 1])
		dfs(x + 1, y, n, m, field);
	return;
}
void p1012(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n, m, k, x, y, ans;
	bool field[50][50] = { false, };
	cin >> t;
	while (t--){
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++){
			cin >> x >> y;
			field[y][x] = true;
		}
		ans = 0;
		for (int i = 0; i < m;i++){
			for (int j = 0; j < n; j++){
				if (field[j][i]){
					dfs(i, j, n, m, field);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}

	return;
}