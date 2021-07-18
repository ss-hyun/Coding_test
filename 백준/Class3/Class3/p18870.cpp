// 백준 18870번 좌표 압축
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int num[1000000], num_list[1000000];
unordered_map<int, int> coordinates(1000000);

void p18870(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, cnt = 0, i;

	cin >> n;
	
	for (i = 0; i < n; i++){
		cin >> num[i];
		if (coordinates.find(num[i]) == coordinates.end()){
			coordinates[num[i]];
			num_list[cnt] = num[i];
			cnt++;
		}
	}

	sort(num_list, num_list + cnt);

	for (i = 0; i < cnt; i++){
		coordinates[num_list[i]] = i;
	}

	for (i = 0; i < n; i++){
		cout << coordinates[num[i]] << ' ';
	}

	return;
}