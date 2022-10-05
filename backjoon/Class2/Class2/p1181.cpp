#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 백준 1181번 단어 정렬
bool compare(string a, string b){
	if (a.size() < b.size())
		return true;
	else if (a.size() == b.size()){
		int i = 0;
		while (i < a.size()){
			if (a[i] > b[i])
				return false;
			else if (a[i] < b[i])
				return true;
			i++;
		}
	}
	return false;
}

void p1181(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<string> str;
	string temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		str.push_back(temp);
	}
	sort(str.begin(), str.end(), compare);

	cout << str[0] << endl;
	for (int i = 1; i < n;i ++){
		if (!compare(str[i - 1], str[i]))
			continue;
		cout << str[i] << endl;
	}

	return;
}