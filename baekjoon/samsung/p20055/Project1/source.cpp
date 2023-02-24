#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

// robot : record robot insert time(cnt) == robot name(number)
// cnt : belt process iteration number
int n, k, tmp, robot[200], cnt;
// belt_A : durability at each index
vector<int>  belt_A;
// pos_robot : robot position index, insert time ascending order
list<int> pos_robot;

int main() {
	// input
	cin >> n >> k;
	belt_A.reserve(2 * n);
	for (int i = 0; i < 2*n; i++) {
		cin >> tmp;
		belt_A.push_back(tmp);
	}


	// up : rasing position index, down : lowering position
	int d_zero = 0, up = 0, down = n - 1;
	while (d_zero < k) { // check number of zero durability
		cnt++;
		// rotate belt
		up = up == 0 ? 2 * n - 1 : up - 1;
		down = down == 0 ? 2 * n - 1 : down - 1;

		// move robot
		list<int>::iterator pos = pos_robot.begin();
		while (pos != pos_robot.end()) {
			int next_idx = (*pos) + 1;
			if (next_idx == 2 * n) next_idx = 0;
			// if, robot can move
			if (*pos != down && belt_A[next_idx] > 0 && robot[next_idx] == 0) {
				belt_A[next_idx]--;
				if (belt_A[next_idx] == 0) d_zero++;
				robot[next_idx] = robot[*pos];
				robot[*pos] = 0;
				*pos = next_idx;
			}
			// if, robot in down position
			if (*pos == down) {
				robot[*pos] = 0;
				pos = pos_robot.erase(pos);
				continue;
			}
			pos++;
		}
		
		// put a robot
		if (belt_A[up]) {
			if (--belt_A[up] == 0) d_zero++;
			pos_robot.push_back(up);
			robot[up] = cnt;
		}
	}

	cout << cnt << '\n';

	return 0;
}