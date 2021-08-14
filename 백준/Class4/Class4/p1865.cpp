// 백준 1865번 웜홀
#include <iostream>

#define INT_MAX 0x7fffffff

using namespace std;

namespace s1865{
	// short_path : 1에서부터 i까지의 short path
	int n, m, w, undirected_graph[501][501], wormhole[501][501], short_path[501];
	
	bool bellman_ford(int start){
		int i, j, curr, connect;
		short_path[start] = 0;

		// edge relection n-1번
		for (i = 1; i < n; i++){
			for (curr = 1; j < n + 1; j++){

				for (connect = 1; connect < n + 1; connect++){
					if (undirected_graph[curr][connect] != INT_MAX){

					}
				}
			}
		}

		// all edge에 대해 edge relection 1번


		// 정상 종료, negative cycle 없음
		return true;
	}
}

using namespace s1865;

void p1865(){
	int tc, i, s, e, t, j;

	cin >> tc;
	while(tc--){
		cin >> n >> m >> w;
		
		// 초기화
		for (i = 1; i < n + 1; i++){
			for (j = 1; j < n + 1; j++){
				undirected_graph[i][j] = INT_MAX;
				wormhole[i][j] = 0;
			}
			short_path[i] = INT_MAX;
		}

		// 입력 & 그래프 구성
		for (i = 0; i < m; i++){
			cin >> s >> e >> t;
			if (undirected_graph[s][e]>t)
				undirected_graph[s][e] = t, undirected_graph[e][s] = t;
		}
		for (i = 0; i < w; i++){
			cin >> s >> e >> t;
			if (wormhole[s][e]>t)
				wormhole[s][e] = t;
		}

		// 벨만-포드 알고리즘 실행 & 결과 출력
		if (bellman_ford(1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return;
}