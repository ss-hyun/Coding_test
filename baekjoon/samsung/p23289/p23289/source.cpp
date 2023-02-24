#include <iostream>
#include <vector>
#include <memory.h>

typedef struct heater{
	int dirc, r, c;
} heater;
typedef struct grid{
	int r, c;
} check, change, loc;

using namespace std;

int row, col, k, w, room[20][20][2], chocolate, cur, heat[20][20];
bool wall[20][20][4];
vector<heater> heaters;
vector<check> checks;

#define R 0
#define L 1
#define U 2
#define D 3
#define N 4
change wind_dirc[5] = {
	{ 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 0 }
};
int wind_exp[4][3] = {
	{ U, D, N }, { U, D, N }, { L, R, N }, { R, L, N }
};

#define next (cur ? 0 : 1)

inline bool in_room(loc l){
	return l.r > -1 && l.c > -1 && l.r < row && l.c < col;
}

inline loc add(loc l1, loc l2){
	loc l;
	l.r = l1.r + l2.r;
	l.c = l1.c + l2.c;
	return l;
}

void print_temp(int stat){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			cout << room[i][j][stat] << ' ';
		}
		cout << '\n';
	}
}

bool check_temp(){
	//cout << '\n';
	for (check c : checks){
		//cout << room[c.r][c.c][cur] << ' ';
		if (room[c.r][c.c][cur] < k)
			return false;
	}
	//cout << '\n';
	return true;
}

void cal_change(loc l1, loc l2){
	int *t1 = &room[l1.r][l1.c][cur], *t2 = &room[l2.r][l2.c][cur], *tmp;
	if (*t1 < *t2){
		tmp = t1; t1 = t2; t2 = tmp;
	}

	int c = (*t1 - *t2) / 4, nt = cur ? -1 : 1;
	*(t1 + nt) += -c;
	*(t2 + nt) += c;
}

void change_temp(){
	int nt = next;
	loc l1, l2;
	
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			for (int d = 0; d < 4; d++){
				if (d % 2 == 0){
					l1.r = i; l1.c = j;
					l2 = add(l1, wind_dirc[d]);
					if (in_room(l2) && !wall[i][j][d])
						cal_change(l1, l2);
				}
			}
		}
	}
	//print_temp(cur);
	//print_temp(nt);

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			room[i][j][nt] += room[i][j][cur];
			room[i][j][cur] = 0;
			if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
				room[i][j][nt] += room[i][j][nt] ? -1 : 0;
		}
	}
	
	cur = nt;
}

bool is_change[20][20];
void work_heater(loc l, int d, int temp){
	if (!in_room(l) || is_change[l.r][l.c] || temp == 0)
		return;

	is_change[l.r][l.c] = true;
	heat[l.r][l.c] += temp;

	loc t, nxt;
	for (int i = 0; i < 3; i++){
		if (wind_exp[d][i] == N || !wall[l.r][l.c][wind_exp[d][i]]){
			t = add(l, wind_dirc[wind_exp[d][i]]);
			nxt = add(t, wind_dirc[d]);
			if (in_room(nxt) && !wall[t.r][t.c][d]){
				work_heater(nxt, d, temp - 1);
			}
		}
	}

	return;
}
void work_heaters(){
	for (heater h : heaters){
		memset(is_change, false, sizeof(is_change));
		work_heater(add({ h.r, h.c }, wind_dirc[h.dirc]), h.dirc, 5);
		//print_temp();
	}
}

void heatting(){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			room[i][j][cur] += heat[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int tmp;
	cin >> row >> col >> k;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			cin >> tmp;
			if (tmp == 5)
				checks.push_back({ i, j });
			else if (tmp > 0)
				heaters.push_back({ tmp-1, i, j });
		}
	}

	int x, y;
	cin >> w;
	for (int i = 0; i < w; i++){
		cin >> x >> y >> tmp;
		if (tmp == 0){
			wall[x-1][y-1][U] = true;
			wall[x-2][y-1][D] = true;
		}
		else{
			wall[x-1][y-1][R] = true;
			wall[x-1][y][L] = true;
		}
	}

	work_heaters();
	while (true){
		heatting();
		change_temp();
		//print_temp(cur);
		chocolate++;
		if (chocolate > 100 || check_temp())
			break;
	}
	
	//print_temp(cur);
	cout << chocolate;

	return 0;
}