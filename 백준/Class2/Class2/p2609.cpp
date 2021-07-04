#include <iostream>
#include <cmath>

using namespace std;

// 백준 2609번 최대공약수와 최소공배수
void p2609(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b, i;
	cin >> a >> b;
	// a와 b 소인수 분해
	// 각 index에 대해 소인수분해 시 그 index의 인수를 몇 개 가지고 있는지 저장
	int a_prime_fac[10001] = { 0, }, b_prime_fac[10001] = { 0, };
	for (i = 2; i<=(a>b ? a : b); i++){
		if (a == 1 && b == 1)
			break;
		while (a%i == 0){
			a /= i;
			a_prime_fac[i]++;
		}
		while (b%i == 0){
			b /= i;
			b_prime_fac[i]++;
		}
	}

	int mul = 1, div = 1;	// mul : 최대공배수, div : 최대공약수
	for (int j = 2; j < i; j++){
		if (a_prime_fac[j] && b_prime_fac[j]){
			mul *= (int)pow((float)j, (float)a_prime_fac[j]>b_prime_fac[j] ? a_prime_fac[j] : b_prime_fac[j]);
			div *= (int)pow((float)j, (float)a_prime_fac[j]<b_prime_fac[j] ? a_prime_fac[j] : b_prime_fac[j]);
		}
		else if (a_prime_fac[j]){
			mul *= (int)pow((float)j, (float)a_prime_fac[j]);
		}
		else if (b_prime_fac[j]){
			mul *= (int)pow((float)j, (float)b_prime_fac[j]);
		}
	}
	cout << div << '\n' << mul << '\n';

	return;
}