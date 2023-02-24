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

namespace s11053_dp{
	int A[1000], dp[1000], *N;

	int dp_max(){
		int max = 0, i, j;

		for (i = 0; i < *N; i++){
			dp[i] = 1;
			for (j = i - 1; j > -1; j--){
				if (A[j] < A[i] && dp[j] >= dp[i])
					dp[i] = dp[j] + 1;
			}
			if (max < dp[i])
				max = dp[i];
		}

		return max;
	}
}

using namespace s11053_dp;

void p11053(){
	int n, i, a;
	N = &n;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &a);
		new_a(a);
		A[i] = a;
	}
	
	printf("%d\n", max_size());
	printf("%d", dp_max());

	return;
}