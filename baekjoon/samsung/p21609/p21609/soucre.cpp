#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef struct point{
	int r, c;
} point;

int n, m, grid[20][20][2], score, cur;
vector<point> group, temp;

#define next (cur ? 0 : 1)

bool compare(point a, point b){
	if (a.r < b.r)
		return true;
	else if (a.r == b.r && a.c < b.c)
		return true;
	return false;
}

void print_group(vector<point> g){
	for (point p : g){
		cout << '(' << p.r << ',' << p.c << ')' << endl;
	}
}

void print_grid(){
	cout << '\n';
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << grid[i][j][cur] << ' ';
		cout << '\n';
	}
}

inline bool in_grid(point p){
	return !(p.r < 0 || p.c < 0 || p.r == n || p.c == n);
}

bool visit[20][20];
void find_group(point p, int color){
	int r = p.r, c = p.c;
	
	if (visit[r][c] || grid[r][c][cur] < 0 || (grid[r][c][cur] > 0 && color != grid[r][c][cur]))
		return;

	visit[r][c] = true;
	temp.push_back(p);

	if (in_grid({ r-1, c })) find_group({ r-1, c }, color);
	if (in_grid({ r, c-1 })) find_group({ r, c-1 }, color);
	if (in_grid({ r+1, c })) find_group({ r+1, c }, color);
	if (in_grid({ r, c+1 })) find_group({ r, c+1 }, color);	

	return;
}

bool in_group(point p){
	for (point g : group){
		if (g.r == p.r && g.c == p.c)
			return true;
	}
	return false;
}

point stand(vector<point> v){
	for (point p : v){
		if (grid[p.r][p.c][cur] != 0)
			return p;
	}
}

int rainbow(vector<point> v){
	int num = 0;
	for (point p : v){
		if (grid[p.r][p.c][cur] == 0)
			num++;
	}
	return num;
}

bool find_bigger_group(){
	point st_group, st_temp;
	int g_rainbow, t_rainbow;
	group.clear();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (grid[i][j][cur] < 1 || in_group({ i, j }))
				continue;
			temp.clear();
			memset(visit, false, sizeof(visit));
			find_group({ i, j }, grid[i][j][cur]);
			sort(temp.begin(), temp.end(), compare);
			if (group.size() < temp.size())
				group = temp;
			else if (group.size() == temp.size()){
				g_rainbow = rainbow(group);
				t_rainbow = rainbow(temp);
				if (g_rainbow < t_rainbow)
					group = temp;
				else if (g_rainbow == t_rainbow){
					st_group = stand(group);
					st_temp = stand(temp);
					if (st_group.r < st_temp.r)
						group = temp;
					else if (st_group.r == st_temp.r){
						if (st_group.c < st_temp.c)
							group = temp;
					}
				}
			}
		}
	}

	return group.size() > 1;
}

void remove_and_score(){
	for (point p : group){
		grid[p.r][p.c][cur] = -2;
	}
	score += group.size() * group.size();
}

inline bool is_empty(point p){
	return grid[p.r][p.c][cur] < -1;
}

void gravity(){
	int r, c;
	for (int j = 0; j < n; j++){
		for (int i = n-1; i > -1; i--){			
			if (grid[i][j][cur] > -1){
				r = i, c = j;
				while (in_grid({ r+1, c }) && grid[r+1][c][cur] == -2){
					grid[r+1][c][cur] = grid[r][c][cur];
					grid[r][c][cur] = -2;
					r++;
				}
			}
		}
	}
}

void rotate(){
	int nt = next;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			grid[n-1-j][i][nt] = grid[i][j][cur];
		}
	}
	cur = nt;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> grid[i][j][cur];
		}
	}

	while (find_bigger_group()){
		remove_and_score();
		gravity();
		rotate();
		gravity();
	}

	cout << score;

	return 0;
}