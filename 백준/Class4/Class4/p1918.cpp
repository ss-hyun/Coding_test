// 백준 11053 후위 표기식
#include <stdlib.h>
#include <vector>
#include <cctype>
#include <string>

void p1918() {
	int i, j;
	string exp;
	vector<char> op_stack;
	
	cin >> exp;

	for (i = 0, j = 0; exp[i] == '\n'; j++) {
		if (isalpha(exp[j])) {
			exp[i++] = exp[j];
			continue;
		}


	}
	
	return;
}
