// 백준 11726번 2*n 타일링
#include <iostream>

using namespace std;

void p11726(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, bf1, bf2, n_method = 1;
	cin >> n;

	bf1 = 1, bf2 = 1;

	for (int i = 2; i < n + 1; i++){
		n_method = (bf1 + bf2) % 10007;
		bf1 = bf2;
		bf2 = n_method;
	}

	cout << n_method << '\n';

	return;
}