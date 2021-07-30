// 백준 15650번 N과 M(2)
#include <iostream>

using namespace std;

void p15650(){
	int n, m, i, change, limit, seq[8];
	
	cin >> n >> m;

	for (i = 0; i < m; i++)
		seq[i] = i + 1;
	change = m - 1, limit = n;

	while(true){
		for (i = 0; i < m; i++)
			cout << seq[i] << ' ';
		cout << '\n';
		if (seq[0] == n - m + 1)
			break;
		while (seq[change] == limit)
			change--, limit--;
		for (++seq[change++]; change < m; change++)
			seq[change] = seq[change - 1] + 1;
		change--, limit = n;
	}

	return;
}