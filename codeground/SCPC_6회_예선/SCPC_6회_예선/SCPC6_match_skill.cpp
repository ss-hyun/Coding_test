#include <iostream>
#include <algorithm>

using namespace std;

namespace s_match_skill{
	int Answer;

}

using namespace s_match_skill;

void match_skill(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T, test_case, n, A[200000], B[200000], i;
	

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cout << "Case #" << test_case + 1 << '\n';

		cin >> n;
		for (i = 0; i < n; i++)
			cin >> A[i];
		for (i = 0; i < n; i++)
			cin >> B[i];

		sort(A, A + n);
		sort(B, B + n);  

		Answer = 0;
		
		// Print the answer to standard output(screen).
		cout << Answer << endl;
	}

}