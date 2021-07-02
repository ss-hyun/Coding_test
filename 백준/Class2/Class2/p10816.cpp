#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 백준 10816번 숫자 카드 2
struct node{
	int n;
	int amount;
	int left;
	int right;
};
void p10816(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	vector<node> tree;

	// 이진 트리 이용하여 search (class2 1920 수 찾기++)
	cin >> n;
	tree.resize(n + 1);
	int i, temp, curr, size = 0; // size : dummy node (0) 제외한 node 수
	tree[0] = { INT_MIN, 0,  -1, -1 };
	for (i = 0; i < n; i++){
		cin >> temp;
		curr = 0;
		while (true){
			if (tree[curr].n == temp){
				tree[curr].amount++;
				break;
			}
			else if (tree[curr].n > temp){
				if (tree[curr].left == -1){
					tree[++size] = { temp, 1, -1, -1 };
					tree[curr].left = size;
					break;
				}
				curr = tree[curr].left;
			}
			else{
				if (tree[curr].right == -1){
					tree[++size] = { temp, 1, -1, -1 };
					tree[curr].right = size;
					break;
				}
				curr = tree[curr].right;
			}
		}
	}

	cin >> m;
	for (i = 0; i < m; i++){
		cin >> temp;
		curr = 0;
		while (true){
			if (tree[curr].n == temp){
				cout << tree[curr].amount << ' ';
				break;
			}
			else if (tree[curr].n>temp){
				if (tree[curr].left == -1){
					cout << 0 << ' ';
					break;
				}
				curr = tree[curr].left;
			}
			else{
				if (tree[curr].right == -1){
					cout << 0 << ' ';
					break;
				}
				curr = tree[curr].right;
			}
		}
	}

	return;
}