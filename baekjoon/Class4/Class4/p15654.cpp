// 백준 15654번 N과 M (5)
#include <iostream>

namespace s15654{
	int n, m, seq[8], index_seq[8];
	bool use[8] = { false, };
}

using namespace s15654;
using namespace std;

void search_seq(int curr){
	int i, j;
	for (i = 0; i < n; i++){
		if (!use[i]){
			index_seq[curr] = i, use[i] = true;
			if (curr < m - 1)
				search_seq(curr + 1);
			else{
				for (j = 0; j < m; j++)
					cout << seq[index_seq[j]] << ' ';
				cout << '\n';
			}
			use[i] = false;
		}
	}
}

void p15654(){
	int i, j, tmp;

	// input
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> seq[i];

	// sorting
	for (i = n; i > 0; i--){
		for (j = 1; j < i; j++){
			if (seq[j - 1] > seq[j]){
				tmp = seq[j - 1];
				seq[j - 1] = seq[j];
				seq[j] = tmp;
			}
		}
	}

	// search and print seqence
	search_seq(0);

	return;
}