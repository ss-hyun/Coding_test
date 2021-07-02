#include <iostream>

using namespace std;

void p4153(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int seg[3], maxIndex;
	 
	while (true){
		cin >> seg[0] >> seg[1] >> seg[2];
		if (seg[0] == 0 && seg[1] == 0 && seg[2] == 0)
			break;
		maxIndex = 0;
		for (int i = 1; i < 3; i++){
			if (seg[maxIndex] < seg[i])
				maxIndex = i;
		}
		int squ = seg[0] * seg[0] + seg[1] * seg[1] + seg[2] * seg[2];
		if ((squ >> 1) == seg[maxIndex] * seg[maxIndex])
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return;
}