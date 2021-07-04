#include <iostream>

using namespace std;

// 백준 11866번 요세푸스 문제 0
void p11866(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k; bool is_trash[1001] = { false, };
	while (true){
		for (int i = 0; i < 1001; i++)
			is_trash[i] = false;
	cin >> n >> k;
	int curr = 0, card_num = n;
	cout << '<';
	while (card_num){
		for (int i = 0; i < k; i++){
			curr++;
			if (curr > n)
				curr = 1;
			while (is_trash[curr]){
				curr++;
				if (curr > n)
					curr = 1;
			}
		}
		is_trash[curr] = true;
		cout << curr;
		card_num--;
		//if (card_num)
			cout << ", ";
		//if (!card_num) cout << curr;
	}
	cout << '>';

	int t;
	cout << "\n계속 실행하려면 0 입력 : ";
	cin >> t;
	if (t)
		break;
	}
	return;
}