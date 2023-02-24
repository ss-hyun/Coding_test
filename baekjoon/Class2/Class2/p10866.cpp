#include <iostream>
#include <string>

using namespace std;

// 백준 10866번 덱
void p10866(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, deque[10000], size = 0, st = 0, en = 0, num;
	string temp;
	cin >> n;
	while (n--){
		cin >> temp;
		if (temp == "push_front"){
			cin >> num;
			if (--st < 0)
				st = 9999;
			deque[st] = num;
			size++;
		}
		else if (temp == "push_back"){
			cin >> num;
			deque[en] = num;
			size++;
			if (++en>9999)
				en = 0;
		}
		else if (temp == "pop_front"){
			if (size == 0)
				cout << -1 << '\n';
			else{
				cout << deque[st] << '\n';
				if (++st > 9999)
					st = 0;
				size--;
			}
		}
		else if (temp == "pop_back"){
			if (size == 0)
				cout << -1 << '\n';
			else{
				if (--en < 0)
					en = 9999;
				cout << deque[en] << '\n';
				size--;
			}
		}
		else if (temp == "size")
			cout << size << '\n';
		else if (temp == "empty"){
			if (size)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (temp == "front"){
			if (size)
				cout << deque[st] << '\n';
			else
				cout << -1 << '\n';
		}
		else if (temp == "back"){
			if (size){
				num = en - 1;
				if (num < 0)
					num = 9999;
				cout << deque[num] << '\n';
			}
			else
				cout << -1 << '\n';
		}
	}

	return;
}