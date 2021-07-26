// 백준 1149번 RGB거리
#include <iostream>

using namespace std;

#define R 0
#define G 1
#define B 2

void p1149(){
	// min[i] : 0 - r, 1 - g, 2 - b
	int n, min[2][3], i, r, g, b;
	bool curr;
	
	cin >> n;
	curr = 0;
	cin >> min[0][R] >> min[0][G] >> min[0][B];
	for (i = 1; i < n; i++){
		curr = !curr;
		cin >> r >> g >> b;
		min[curr][R] = r + (min[!curr][G] < min[!curr][B] ? min[!curr][G] : min[!curr][B]);
		min[curr][G] = g + (min[!curr][R] < min[!curr][B] ? min[!curr][R] : min[!curr][B]);
		min[curr][B] = b + (min[!curr][R] < min[!curr][G] ? min[!curr][R] : min[!curr][G]);
	}
	
	if (min[curr][R] < min[curr][G])
		cout << (min[curr][R] < min[curr][B] ? min[curr][R] : min[curr][B]);
	else
		cout << (min[curr][G] < min[curr][B] ? min[curr][G] : min[curr][B]);

	return;
}