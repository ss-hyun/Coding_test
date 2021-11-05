// 백준 11053 후위 표기식
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

void p1918() {
	int i, j;
	char exp[101];
	vector<char> op_stack;
	
	cin >> exp;

	for (i = 0, j = 0; exp[i] != '\0'; j++) {
		if (isalpha(exp[j])) {
			exp[i++] = exp[j];
			continue;
		}
		if (op_stack.empty())
			op_stack.push_back(exp[j]);
		else {
			switch (exp[j]) {
			case '+':
			case '-':
				while (op_stack.back() != '(') {
					exp[i++] = op_stack.back();
					op_stack.pop_back();
					if (op_stack.empty())
						break;
				}
				op_stack.push_back(exp[j]);
				break;
			case '*':
			case '/':
				while (op_stack.back() == '*' || op_stack.back() == '/') {
					exp[i++] = op_stack.back();
					op_stack.pop_back();
					if (op_stack.empty())
						break;
				}
				op_stack.push_back(exp[j]);
				break;
			case '(':
				op_stack.push_back(exp[j]);
				break;
			case ')':
				while (op_stack.back() != '(') {
					exp[i++] = op_stack.back();
					op_stack.pop_back();
				}
				op_stack.pop_back();
				break;
			case '\0':
				while (!op_stack.empty()) {
					exp[i++] = op_stack.back();
					op_stack.pop_back();
				}
				exp[i] = '\0';
			}
		}
	}

	cout << exp << '\n';
	
	return;
}
