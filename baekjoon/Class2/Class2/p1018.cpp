#include <iostream>

using namespace std;
 
// 백준 1018번 체스판 다시 칠하기
void p1018(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	// 주어진 보드의 왼쪽 위 모서리가 white로 시작할 때 기준으로 체스판 제작
	// 자신부터 위/아래로 8칸으로 체스판 제작 기준 다시 칠해야 하는 보드 개수
	int w_change[50][50];

	cin >> n >> m;
	char tmp;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> tmp;
			// 자신을 다시 칠해야 하는지
			if ((i+j)%2==0)
				w_change[i][j] = tmp != 'W' ? 1 : 0;
			else
				w_change[i][j] = tmp != 'B' ? 1 : 0;
		}
	}

	// 행 기준 다시 칠해야 하는 보드 개수 update
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m - 7; j++){
			for (int k = 1; k < 8; k++){
				w_change[i][j] += w_change[i][j + k];
			}
		}
	}

	// 행 + 열 합산 다시 칠해야 하는 보드 개수 update
	for (int j = 0; j < m - 7; j++){
		for (int i = 0; i < n - 7; i++){
			for (int k = 1; k < 8; k++){
				w_change[i][j] += w_change[i + k][j];
			}
		}
	}

	// 다시 칠해야 하는 보드의 최소 개수 search
	int min = 100000, temp;
	for (int i = 0; i < n - 7; i++){
		for (int j = 0; j < m - 7; j++){
			// 보드에서 8*8 체스판의 반인 32개 이상을 다시 칠해야 한다면
			// 기준 색을 검은색으로 하여 칠하는 것이 더 적은 수의 보드를 칠한다.
			if (w_change[i][j]>32)
				w_change[i][j] = 64 - w_change[i][j];
			if (min>w_change[i][j])
				min = w_change[i][j];
		}
	}

	cout << min;

	return;
}