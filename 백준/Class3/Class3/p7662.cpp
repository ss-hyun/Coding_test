// 백준 7662번 이중 우선순위 큐
#include <iostream>

using namespace std;

struct op_list{ char op; int num; };
op_list test[1000000];
int smmh[1000002], last;

void insert(int n){
	int curr = ++last;
	if (curr == 2){
		smmh[curr] = n;
		return;
	}
	if ((curr & 1)&&(smmh[curr-1] > n)){
		smmh[curr] = smmh[curr - 1]; curr--;
	}
	int comp = curr >> 2;
	if (comp){
		comp <<= 1;
		if (n < smmh[comp]){
			smmh[curr] = smmh[comp]; curr = comp;
			while ((comp >>= 2) && (n < smmh[comp <<= 1])){
				smmh[curr] = smmh[comp]; curr = comp;
			}
		}
		else if (n > smmh[++comp]){
			smmh[curr] = smmh[comp]; curr = comp;
			while ((comp >>= 2) && (n > smmh[++(comp <<= 1)])){
				smmh[curr] = smmh[comp]; curr = comp;
			}
		}
	}
	smmh[curr] = n;
	return;
}

void del(bool flag){	// flag : false (최대 삭제), true (최소 삭제)
	int n = smmh[last], del, comp;
	if (flag){
		comp = del = 2;
		while ((comp <<= 1) < last){
			if ((comp + 2 < last) && (smmh[comp] > smmh[comp+2])){
				comp += 2;
			}
			if (n > smmh[comp]){
				smmh[del] = smmh[comp];
				del = comp;
				if (n > smmh[comp + 1]){
					smmh[comp] = smmh[comp + 1];
					smmh[comp + 1] = n;
					n = smmh[comp];
				}
			}
		}
		smmh[del] = n;
	}
	else{
		del = 3;
	}
	last--;
}

void print_curr(){
	cout << "SMMH" << endl;
	for (int j = 2; j <= last; j++){
		cout << smmh[j] << '\t';
		if (j == 3 || j == 7 || j == 15 || j == 31)
			cout << endl;
	}
	cout << endl;
}

void p7662(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, k, i, j;
	
	cin >> t;
	for (i = 0; i < t; i++){
		cin >> k;
		for (j = 0; j < k; j++){
			cin >> test[j].op >> test[j].num;
		}
		last = 1;
		for (j = 0; j < k; j++){
			if (test[j].op != 'D'){
				insert(test[j].num);
			}
			else if (last != 1){
				print_curr();
				del(test[j].num != 1);
				print_curr();
			}
		}
	}

	return;
}