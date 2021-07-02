#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 백준 10814번 나이순 정렬
struct member{
	int age;
	string name;
};
struct member2{
	int age;
	int order;
	string name;
};

bool compare1(member a, member b){
	return a.age < b.age;
}

bool compare2(member2 a, member2 b){
	if (a.age == b.age)
		return a.order < b.order;
	return a.age < b.age;
}

void p10814(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; vector<member> baekjoon; vector<member2> baekjoon2;
	cin >> n;
	baekjoon.resize(n);
	baekjoon2.resize(n);
	int temp; string tmp;
	for (int i = 0; i < n; i++){
		cin >> temp >> tmp;
		baekjoon[i] = { temp, tmp };
		baekjoon2[i] = { temp, i, tmp };
	}
	
	// version 1
	stable_sort(baekjoon.begin(), baekjoon.end(), compare1);

	// version 2
	sort(baekjoon2.begin(), baekjoon2.end(), compare2);

	for (int i = 0; i < n; i++){
		//cout << baekjoon[i].age << ' ' << baekjoon[i].name << '\n';
		cout << baekjoon2[i].age << ' ' << baekjoon2[i].name << '\n';
	}

	return;
}