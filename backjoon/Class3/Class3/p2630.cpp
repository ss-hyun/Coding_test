// 백준 2630번 색종이 만들기
#include <iostream>

using namespace std;
int pnum[3]; // 0 : white, 1 : blue, 2: none
bool paper[128][128];

// 현재 정사각형의 색(white = 0, blue = 1)을 return, 색이 다르면 2를 return
int color(int raw, int col, int size){
	if (size == 1)
		return paper[raw][col];
	int p[3] = { 0, }, x[4];
	size /= 2;
	x[0] = color(raw, col, size);
	x[1] = color(raw, col + size, size);
	x[2] = color(raw + size, col, size);
	x[3] = color(raw + size, col + size, size);
	for (int i = 0; i < 4; i++){
		p[x[i]]++;
	}
	if (p[0] == 4)
		return 0;
	else if (p[1] == 4)
		return 1;
	else{
		pnum[0] += p[0];
		pnum[1] += p[1];
		return 2;
	}
}

void p2630(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> paper[i][j];
		}
	}

	pnum[color(0, 0, n)]++;

	cout << pnum[0] << '\n' << pnum[1];
	
	return;
}