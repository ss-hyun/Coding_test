#include <iostream>

using namespace std;

// 백준 1463번 1로 만들기
int min_op_num[1000001];

int re(int x){
	if (x == 0) return -1;
	if (x == 1) return 0;
	int div2, div3;
	return (div2 = re(x / 2) + x % 2 + 1) < (div3 = re(x / 3) + x % 3 + 1) ? div2 : div3;
}

void p1463(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int x;
	cin >> x;

	min_op_num[1] = 0, min_op_num[2] = 1, min_op_num[3] = 1;
	for (int i = 4; i <= x; i++){
		min_op_num[i] = min_op_num[i - 1] + 1;
		if ((i & 0x01) == 0){
			if (min_op_num[i / 2] + 1 < min_op_num[i])
				min_op_num[i] = min_op_num[i / 2] + 1;
		}
		if (i % 3 == 0){
			if (min_op_num[i / 3] + 1 < min_op_num[i])
				min_op_num[i] = min_op_num[i / 3] + 1;
		}
	}

	cout << "solution 1 : DP bottom up\t" << min_op_num[x];
	cout << "\nsolution 2 : recursive\t\t" << re(x);

	return;
}