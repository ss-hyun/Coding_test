// 백준 1697번 숨바꼭질
#include <iostream>
#include <queue>

inline int MIN(int x, int y){ return x < y ? x : y; }

using namespace std;

namespace g{
	int cmin, n, k;
	bool visit[100001];
}

int rec(int curr){
	if (curr <= g::n)
		return g::n - curr;
	if (curr == 1)
		return g::n + 1;
	if (curr & 1)
		return 1 + MIN(rec(curr - 1), rec(curr + 1));
	return MIN(1 + rec(curr >> 1), curr - g::n);
}

void p1697(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	queue<pair<int, int>> q; // first : 현재 위치, second : 이동 카운트

	cin >> g::n >> g::k;

	// bfs
	int curr, cnt;
	q.push({ g::n, 0 });
	while (true){
		curr = q.front().first; cnt = q.front().second;
		if (curr == g::k)
			break;
		q.pop();
		cnt++;
		if (curr + 1<100001 && !g::visit[curr + 1]){
			q.push({ curr + 1, cnt });
			g::visit[curr + 1] = true;
		}
		if (curr&&!g::visit[curr - 1]){
			q.push({ curr - 1, cnt });
			g::visit[curr - 1] = true;
		}
		if (curr<50001 && !g::visit[(curr << 1)]){
			q.push({ (curr << 1), cnt });
			g::visit[(curr << 1)] = true;
		}
	}

	cout << rec(g::k) << endl;
	cout << cnt;

	return;
}