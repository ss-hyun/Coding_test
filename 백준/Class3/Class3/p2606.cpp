// 백준 2606번 바이러스
#include <iostream>
#include <vector>

using namespace std;

// 인접 행렬
namespace matrix{
	bool visit[101] = { false, };
	bool connect[101][101];

	int dfs(int curr, int tot){
		visit[curr] = true;
		int virus = 1;
		for (int i = 1; i <= tot; i++){
			if (!visit[i] && connect[curr][i])
				virus += dfs(i, tot);
		}
		return virus;
	}
}

// 인접 리스트
namespace adjlist{
	bool visit[101] = { false, };
	vector<int> connect[101];

	int dfs(int curr, int tot){
		visit[curr] = true;
		int virus = 1;
		for (int next : connect[curr]){
			if (!visit[next])
				virus += dfs(next, tot);
		}
		return virus;
	}
}

void p2606(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int computer, npair;
	cin >> computer >> npair;

	int a, b;
	for (int i = 0; i < npair; i++){
		cin >> a >> b;
		matrix::connect[a][b] = true; matrix::connect[b][a] = true;
		adjlist::connect[a].push_back(b); adjlist::connect[b].push_back(a);
	}

	cout << matrix::dfs(1, computer) - 1 << '\n';
	cout << adjlist::dfs(1, computer) - 1 << '\n';

	return;
}