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

	system("pause");

	return 0;
}