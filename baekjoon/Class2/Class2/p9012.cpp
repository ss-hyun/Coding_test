#include <iostream>

using namespace std;

// 백준 9012번 괄호
void p9012(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	char str[51];
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> str;
		int j = 0, vps = 0;
		while (str[j] != '\0'){
			if (str[j] == '(')
				vps++;
			else
				vps--;
			if (vps < 0)
				break;
			j++;
		}
		if (vps != 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}


	return;
}