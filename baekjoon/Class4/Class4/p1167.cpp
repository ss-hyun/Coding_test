// 백준 1167번 트리의 지름
#include <iostream>
#include <vector>

using namespace std;

namespace s1167{
	int v, diameter = 0;
	vector<pair<int, int>> adj_list[100001];
	bool visit[100001] = { false, };
	
	// 현재 노드에서 갈 수 있는 가장 깊은(긴) 거리를 리턴
	// 현재 노드를 기준으로 연결되어 있는 두 말단 노드 사이의 거리가
	// 지름의 후보면(= 현재의 지름보다 크면) 지름 update
	int dfs_len(int curr){
		// Max : 현재 노드 기준 최대 깊이(길이), max : 두번째 최대 깊이(길이)
		int Max = 0, max = 0, size = adj_list[curr].size(), i, len;
		visit[curr] = true;

		for (i = 0; i < size; i++){
			if (!visit[adj_list[curr][i].first]){
				len = dfs_len(adj_list[curr][i].first) + adj_list[curr][i].second;
				if (len > Max)
					max = Max, Max = len;
				else if (len > max)
					max = len;
			}
		}
		
		if (Max + max > diameter)
			diameter = Max + max;

		return Max;
	}
}

using namespace s1167;

void p1167(){
	int i, node, connect, dist;

	cin >> v;
	for (i = 0; i < v; i++){
		cin >> node;
		for (cin >> connect; connect != -1; cin >> connect){
			cin >> dist;
			adj_list[node].push_back({ connect, dist });
		}
	}

	dfs_len(1);
	cout << diameter << '\n';

	return;
}