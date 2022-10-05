// 백준 11724번 연결 요소의 개수
#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

namespace s11724{
	int n, m, u, v;
	bool adj_matrix[1001][1001], is_visit[1001], in_group[1001];
	vector<int> adj_list[1001];
	list<unordered_set<int>> group;

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

	void grouping(int u, int v){
		if (in_group[u] || in_group[v]){
			list<unordered_set<int>>::iterator gu, gv;
			for (list<unordered_set<int>>::iterator iter = group.begin(); iter != group.end(); iter++){
				if ((*iter).find(u) != (*iter).end())
					gu = iter;
				if ((*iter).find(v) != (*iter).end())
					gv = iter;
			}
			if (!in_group[u]){
				(*gv).insert(u);
				in_group[u] = true;
			}
			else if (!in_group[v]){
				(*gu).insert(v);
				in_group[v] = true;
			}
			else{
				if (gu != gv){
					for (int x : (*gv)){
						(*gu).insert(x);
					}
					group.erase(gv);
				}
			}
		}
		else{
			unordered_set<int> s = { u, v };
			group.push_back(s);
			in_group[u] = true; in_group[v] = true;
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
		grouping(u, v);
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

	comp = 0;
	for (int i = 1; i < n + 1; i++){
		if (!in_group[i])
			comp++;
	}
	comp += group.size();
	cout << comp << endl;


	return;
}