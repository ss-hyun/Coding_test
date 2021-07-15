#include <iostream>
#include <algorithm>

using namespace std;

int Answer, cal[2][200000];

void diet(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T, test_case, i, j, n, k; // A : cal[0], B : cal[1]

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		// test_case 입력
		cin >> n >> k;
		for (i = 0; i < 2; i++){
			for (int j = 0; j < n; j++){
				cin >> cal[i][j];
			}
		}

		sort(cal[0], cal[0] + n);
		sort(cal[1], cal[1] + n);

		for (i = 0; i < k; i++){
			if (Answer < cal[0][i] + cal[1][k - 1 - i])
				Answer = cal[0][i] + cal[1][k - 1 - i];
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return;
}