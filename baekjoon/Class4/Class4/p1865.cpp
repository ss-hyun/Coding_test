// 백준 1865번 웜홀
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

#define MAX_INIT 0x3fffffff

using namespace std;

namespace s1865{
	// short_path : 1에서부터 i까지의 short path
	int n, m, w, short_path[501];
	vector<pair<int,int>> adj_list[501];

	bool bellman_ford(int start){
		int i, curr;
		short_path[start] = 0;

		// edge relection n-1번
		for (i = 1; i < n; i++){
			for (curr = 1; curr < n + 1; curr++){
				for (auto connect : adj_list[curr]){
					if (short_path[connect.first] > short_path[curr] + connect.second)
						short_path[connect.first] = short_path[curr] + connect.second;
				}
			}
		}

		// all edge에 대해 edge relection 1번
		for (curr = 1; curr < n + 1; curr++){
			for (auto connect : adj_list[curr]){
				if (short_path[connect.first] > short_path[curr] + connect.second)
					return false;
			}
		}

		// 정상 종료, negative cycle 없음
		return true;
	}
}

using namespace s1865;

void p1865(){
	int tc, i, s, e, t, j;

	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d%d", &n, &m, &w);
		
		// 초기화
		for (i = 1; i < n + 1; i++){
			adj_list[i].clear();
			short_path[i] = MAX_INIT;
		}

		// 입력 & 그래프 구성
		for (i = 0; i < m; i++){
			scanf("%d%d%d", &s, &e, &t);
			adj_list[s].push_back({ e, t });
			adj_list[e].push_back({ s, t });
		}
		for (i = 0; i < w; i++){
			scanf("%d%d%d", &s, &e, &t);
			adj_list[s].push_back({ e, -t });
		}

		// 벨만-포드 알고리즘 실행 & 결과 출력
		if (bellman_ford(1))
			printf("NO\n");
		else
			printf("YES\n");
	}

	return;
}