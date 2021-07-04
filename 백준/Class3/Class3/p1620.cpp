#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// 백준 1620번 나는야 포켓몬 마스터 이다솜
void p1620(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;

	string temp;
	unordered_map<string, int> s_pokedex;
	vector<string> i_pokedex;
	for (int i = 1; i <= n; i++){
		cin >> temp;
		s_pokedex[temp] = i;
		i_pokedex.push_back(temp);
	}

	int tmp;
	for (int i = 0; i < m; i++){
		cin.get();
		if (((char)cin.peek()) - '9'>0){
			cin >> temp;
			cout << s_pokedex[temp] << '\n';
		}
		else{
			cin >> tmp;
			cout << i_pokedex[tmp - 1] << '\n';
		}
	}

	return;
}