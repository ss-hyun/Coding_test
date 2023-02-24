#include <iostream>

using namespace std;

void p10250(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// version 1
	int t, h, w, n, x, y;
	cin >> t;
	while (t){
		cin >> h >> w >> n;
		y = n%h;
		if (y == 0){
			x = n / h; y = h;
		}
		else 
			x = n / h + 1;
		cout << y * 100 + x << endl;
		t--;
	}

	// version 2
	/*
	int t, h, w, n, x, y;
	cin >> t;
	while (t){
		cin >> h >> w >> n;
        x = n / h;
		y = n - x * h;
		if (y == 0)
			y = h;
		else
			x++;
		cout << y * 100 + x << endl;
		t--;
	}
	*/

	// version 3
	/*
	int t, h, w, n, room;
	cin >> t;
	while (t){
		cin >> h >> w >> n;
		room = n%h * 100;
		if (room == 0){
			room = n / h + h * 100;
		}
		else
			room += n / h + 1;
		cout << room << endl;
		t--;
	}
	*/

	return;
}