#include <iostream>
#include <string>
#include <Windows.h>
#include "problem_function_list.h"

using namespace std;

int main(){

	cout << "실행시킬 문제 이름 입력 : ";

	string problem;
	cin >> problem;

	if (problem == "diet"){
		cout << problem << " 실행\n";
		diet();
	}
	else if (problem == "match skill"){
		cout << problem << " 실행\n";
		match_skill();
	}

	system("pause");

	return 0;
}