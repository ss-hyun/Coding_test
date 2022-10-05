// 백준 1753번 최단경로
#include <iostream>
#include <vector>
#include <queue>
#define INT_MAX 0x7fffffff

using namespace std;

namespace s1753{
	struct edge{ int node, weight; };

	vector<edge> adj_list[20001];
	bool pick[20001] = { false, };
	int short_path[20001];

	bool operator<(edge a, edge b){
		return a.weight > b.weight;
	}
	priority_queue<edge> possible_list;

	void dijkstra(int curr){
		int w;
		pick[curr] = true;

		for (edge next : adj_list[curr]){
			w = short_path[curr] + next.weight;
			if (w < short_path[next.node]){
				short_path[next.node] = w;
				possible_list.push({ next.node, w });
			}
		}

		while (!possible_list.empty()){
			w = possible_list.top().node;
			possible_list.pop();
			if (!pick[w]){
				dijkstra(w);
			}
		}

		return;
	}
}

using namespace s1753;

void p1753(){
	int V, E, K, u, v, w, i;

	cin >> V >> E >> K;
	for (i = 0; i < E; i++){
		cin >> u >> v >> w;
		adj_list[u].push_back({ v, w });
	}

	V++;
	for (i = 1; i < V; i++)
		short_path[i] = INT_MAX;
	short_path[K] = 0;

	dijkstra(K);

	for (i = 1; i < V; i++){
		if (pick[i])
			cout << short_path[i] << '\n';
		else
			cout << "INF\n";
	}

	return;
}