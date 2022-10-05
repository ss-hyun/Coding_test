#include <iostream>
#include <cmath>

using namespace std;

// 백준 1074번 Z
void p1074(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, r, c, visit = 0;
	cin >> n >> r >> c;
	n = (int)pow((float)2, (float)n);
	for (; r != 0 || c != 0;){
		n >>= 1;
		if (r < n){
			if (c < n){	// area 1
				continue;
			}
			else{				// area 2
				visit += n * n;
				c -= n;
			}
		}
		else{
			if (c < n){	// area 3
				visit += 2 * n * n;
				r -= n;
			}
			else{				// area 4
				visit += 3 * n * n;
				r -= n; c -= n;
			}
		}
	}
	cout << visit;

	return;
}