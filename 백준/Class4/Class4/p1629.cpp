// 백준 1629번 곱셈
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void p1629(){
	long long a, b, c, i, ans = 1, r[32];
	int j;
	
	scanf("%lld %lld %lld", &a, &b, &c);

	i = 1, j = 0;
	r[j] = a % c;
	while (i < b){
		i <<= 1, j++;
		r[j] = r[j - 1] * r[j - 1] % c;
	}

	while (b){
		while (b < i)
			i >>= 1, j--;
		while (b >= i)
			b -= i, ans = ans * r[j] % c ;
	}

	printf("%lld", ans);

	return;
}