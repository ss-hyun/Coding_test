// 백준 1697번 숨바꼭질
#include <iostream>

using namespace std;

int n[11];

void p9095(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	n[1] = 1; n[2] = 2; n[3] = 4;
	for (int i = 4; i < 11; i++){
		n[i] = n[i - 3] + n[i - 2] + n[i - 1];
	}

	int t, tmp;
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> tmp;
		cout << n[tmp] << '\n';
	}

	return;
}