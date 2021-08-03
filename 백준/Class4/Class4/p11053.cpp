// 백준 11053 가장 긴 증가하는 부분 수열
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

namespace s11053{
	int a_size[1001];
	vector<int> sub_a[1001];

	void new_a(int a){
		int i = 0, loc = 0, size = 0;
		while (!sub_a[i].empty()){
			if (sub_a[i].back() < a){
				sub_a[i].push_back(a);
				a_size[i]++;
				continue;
			}
			if (size){
				if (size < a_size[i] && sub_a[i][size - 1] <= sub_a[loc][size - 1])
					loc = i;
			}
			else
				loc = i;
			while (sub_a[loc][size] < a)
				size++;
			i++;
		}
		sub_a[i].resize(size + 1);
		a_size[i] = size + 1;
		for (int j = 0; j < size; j++)
			sub_a[i][j] = sub_a[loc][j];
		sub_a[i][size] = a;
		return;
	}

	int max_size(){
		int i, max = 0;
		for (i = 0; !sub_a[i].empty(); i++){
			if (a_size[i] > max)
				max = a_size[i];
		}
		return max;
	}
}

using namespace s11053;

void p11053(){
	int n, i, a;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &a);
		new_a(a);
	}
	
	printf("%d", max_size());

	return;
}