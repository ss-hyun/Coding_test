#include <iostream>

using namespace std;

// 백준 11050번 이항계수 1
void p11050(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, ans = 1;

	cin >> n >> k;

	if (k > n - k)
		k = n - k;

	int nume = 1;
	while (k != 0){
		ans *= n;
		nume *= k;
		n--; k--;
	}
	ans /= nume;

	cout << ans << endl;

	return;
}