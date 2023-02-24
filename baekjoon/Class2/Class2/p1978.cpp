#include <iostream>

using namespace std;

// 백준 1978번 소수 찾기
void p1978(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool not_prime[1001] = { false, };

	not_prime[1] = true;
	for (int i = 2; i < 1001; i++){
		if (not_prime[i] == false){
			int times = 2;
			while (i*times < 1001){
				not_prime[i*times] = true;
				times++;
			}
		}
	}
	 
	int n, ans = 0;

	cin >> n;
	for (int i = 0, temp; i < n; i++){
		cin >> temp;
		if (!not_prime[temp])
			ans++;
	}
	cout << ans << '\n';

	return;
}