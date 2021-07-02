#include <iostream>

using namespace std;

// 백준 2164번 카드 2
void p2164(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 
	int n; bool is_trash[500001] = { false, };

	cin >> n;
	int curr = 1, card_num = n;
	while (card_num != 1){
		is_trash[curr] = true;
		card_num--;
		for (int i = 2; i > 0;){
			if (++curr > n)
				curr -= n;
			if (!is_trash[curr])
				i--;
		}
	}
	cout << curr << '\n';

	return;
}