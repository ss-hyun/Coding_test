// 백준 15650번 N과 M(2)
#include <iostream>
#include <vector>

using namespace std;

namespace s11725{
	vector<int> tree[100001];
	int par[100001];
	bool visit[100001];

	void dfs(int curr){
		int next, size = tree[curr].size();
		visit[curr] = true;

		for (next = 0; next < size; next++){
			if (!visit[tree[curr][next]]){
				par[tree[curr][next]] = curr;
				dfs(tree[curr][next]);
			}
		}
		
		return;
	}
}

using namespace s11725;

void p11725(){
	int a, b, i, n;

	cin >> n;
	for (i = 1; i < n; i++){
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	dfs(1);

	n++;
	for (i = 2; i < n; i++)
		cout << par[i] << '\n';

	return;
}