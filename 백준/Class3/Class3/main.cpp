#include <Windows.h>
#include <iostream>
#include "class3_problem_list.h"

using namespace std;

int main(){

	cout << "실행시킬 문제 번호 입력 : ";

	int problem;
	cin >> problem;

	switch (problem){
	case 1012:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1012();
		break;
	case 1074:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1074();
		break;
	case 1463:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1463();
		break;
	case 1620:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1620();
		break;
	case 1697:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1697();
		break;
	case 1764:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1764();
	case 9095:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p9095();
		break;
	case 11723:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p11723();
		break;
	case 2606:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p2606();
		break;
	case 11726:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p11726();
		break;
	default:
		cout << problem << "은 없는 문제입니다.\n";
		break;
	}

	system("pause");

	return 0;
}