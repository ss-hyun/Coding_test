// 백준 11723번 집합
#include <iostream>
#include <string>

using namespace std;

void p11723(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int m, x; string temp; bool s[21] = { false, };
	cin >> m;
	while (m--){
		cin >> temp;
		if (temp == "add"){
			cin >> x;
			s[x] = true;
		}
		else if (temp == "remove"){
			cin >> x;
			s[x] = false;
		}
		else if (temp == "check"){
			cin >> x;
			if (s[x])
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (temp == "toggle"){
			cin >> x;
			s[x] = 1 - s[x];
		}
		else if (temp == "all"){
			for (int i = 0; i < 21; i++)
				s[i] = true;
		}
		else if (temp == "empty"){
			for (int i = 0; i < 21; i++)
				s[i] = false;
		}
	}

	return;
}