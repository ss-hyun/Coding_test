// 백준 11399번 ATM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void p11399(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, tmp;
	vector<int> time;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		time.push_back(tmp);
	}
	sort(time.begin(), time.end());

	tmp = 0;
	for (int i = 0; i < n; i++){
		tmp += (n - i)*time[i];
	}
	cout << tmp;

	return;
}