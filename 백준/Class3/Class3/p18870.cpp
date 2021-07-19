// 백준 18870번 좌표 압축
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MAP_SIZE 0x100000
#define HASH_MASK 0x1ffff
#define HASH_TERM 0x20000

int num[1000000], num_list[1000000], hash_map[MAP_SIZE][2];
bool is_fill[MAP_SIZE];
// unordered_map<int, int> coordinates(1000000);

int insert_key(int num){
	int hash_value = HASH_MASK & num;
	int cnt = 1;
	
	while (is_fill[hash_value]){
		cnt++;
		if (cnt > MAP_SIZE)
			return -1;	// insert key fail : map is full
		if (hash_map[hash_value][0] == num)
			return 0;	// insert key fail : num already exists
		hash_value += HASH_TERM;
		if (hash_value > MAP_SIZE){
			hash_value++;
			hash_value &= HASH_MASK;
		}
	}

	hash_map[hash_value][0] = num;
	is_fill[hash_value] = true;
	
	return 1;	// insert key success
}

int find_key_location(int num){
	int hash_value = HASH_MASK & num;
	int cnt = 1;

	while (hash_map[hash_value][0] != num){
		cnt++;
		if (cnt > MAP_SIZE)
			return -1;	// find key fail : does not exist in map
		hash_value += HASH_TERM;
		if (hash_value > MAP_SIZE){
			hash_value++;
			hash_value &= HASH_MASK;
		}
	}
	
	return hash_value;	// find key success
}

void p18870(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, cnt = 0, i;

	cin >> n;
	
	for (i = 0; i < n; i++){
		cin >> num[i];
		/*
		if (coordinates.find(num[i]) == coordinates.end()){
			coordinates[num[i]];
			num_list[cnt] = num[i];
			cnt++;
		}
		*/
	}

	for (i = 0; i < n; i++){
		if (insert_key(num[i])){
			num_list[cnt] = num[i];
			cnt++;
		}
	}

	sort(num_list, num_list + cnt);

	for (i = 0; i < cnt; i++){
		// coordinates[num_list[i]] = i;
		hash_map[find_key_location(num_list[i])][1] = i;
	}

	for (i = 0; i < n; i++){
		num[i] = hash_map[find_key_location(num[i])][1];
	}

	for (i = 0; i < n; i++){
		// cout << coordinates[num[i]] << ' ';
		cout << num[i] << ' ';
	}

	return;
}