﻿#include <Windows.h>
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
	case 11399:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p11399();
		break;
	case 1927:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1927();
		break;
	case 11279:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p11279();
		break;
	case 2630:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p2630();
		break;
	case 1931:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1931();
		break;
	case 7576:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p7576();
		break;
	case 11724:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p11724();
		break;
	case 18870:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p18870();
		break;
	case 7662:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p7662();
		break;
	default:
		cout << problem << "은 없는 문제입니다.\n";
		break;
	}

	system("pause");

	return 0;
}