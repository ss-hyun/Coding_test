// 백준 1967 트리의 지름
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

namespace s1967 {
	vector<pair<int,int>> adj_list[10001];
	int max = 0, n;

	int dfs(int curr) {
		int max1 = 0, max2 = 0, tmp;

		for (pair<int,int> next : adj_list[curr]) {
			tmp = dfs(next.first) + next.second;
			if (tmp > max1) {
				max2 = max1;
				max1 = tmp;
			}
			else if (tmp > max2) {
				max2 = tmp;
			}
		}
		
		if (max1 > 0) {
			tmp = max1;
			if (max2 > 0)
				tmp += max2;
			if (max < tmp)
				max = tmp;
		}

		return max1;
	}
}

using namespace s1967;

void p1967() {
	int i, p, c, w;

	cin >> n;

	for (i = 1; i < n; i++) {
		cin >> p >> c >> w;
		adj_list[p].push_back({ c, w });
	}
	
	dfs(1);
	
	cout << s1967::max;

	return;
}