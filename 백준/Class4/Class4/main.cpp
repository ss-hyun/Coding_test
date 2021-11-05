#include <Windows.h>
#include <iostream>
#include "class4_problem_list.h"

using namespace std;

int main(){
	cout << "실행시킬 문제 번호 입력 : ";

	int problem;
	cin >> problem;

	switch (problem){
	case 1629:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1629();
		break;
	case 1149:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1149();
		break;
	case 15650:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p15650();
		break;
	case 15654:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p15654();
		break;
	case 11725:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p11725();
		break;
	case 11053:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p11053();
		break;
	case 1167:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1167();
		break;
	case 1753:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1753();
		break;
	case 1932:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1932();
		break;
	case 1865:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1865();
		break;
	case 1918:
		cout << problem << "번 문제 솔루션 실행 시작\n";
		p1918();
		break;
	default:
		cout << problem << "은 없는 문제입니다.\n";
		break;
	}

	system("pause");

	return 0;
}