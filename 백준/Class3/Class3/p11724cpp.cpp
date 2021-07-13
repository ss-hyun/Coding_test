// 백준 11724번 연결 요소의 개수
#include <iostream>
#include <vector>

using namespace std;

namespace s11724{
	int n, m, u, v;
	bool adj_matrix[1001][1001], is_visit[1001];
	vector<int> adj_list[1001];
	void m_dfs(int curr){
		is_visit[curr] = true;
		for (int i = 1; i < n + 1; i++){
			if (adj_matrix[curr][i] && !is_visit[i])
				m_dfs(i);
		}
		return;
	}
	void l_dfs(int curr){
		is_visit[curr] = true;
		for (int i = 0; i < adj_list[curr].size(); i++){
			if (!is_visit[adj_list[curr][i]])
				l_dfs(adj_list[curr][i]);
		}
	}
}

using namespace s11724;

void p11724(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		adj_matrix[u][v] = true;
		adj_matrix[v][u] = true;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	int comp = 0;
	for (int i = 1; i < n + 1; i++){
		if (!is_visit[i]){
			m_dfs(i); comp++;
		}
	}
	cout << comp << endl;

	comp = 0;
	for (int i = 1; i < n + 1; i++){
		is_visit[i] = false;
	}
	for (int i = 1; i < n + 1; i++){
		if (!is_visit[i]){
			l_dfs(i); comp++;
		}
	}
	cout << comp << endl;


	return;
}