// 백준 1931번 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct schedule{
	int start;
	int end;
};

bool compare(schedule a, schedule b){
	if (a.start < b.start)
		return true;
	else if (a.start == b.start){
		if (a.end < b.end)
			return true;
	}
	return false;
}

void p1931(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, s, e;
	vector<schedule> meeting_time;
	pair<int, int> mt2[100000];

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s >> e;
		meeting_time.push_back({ s, e });
		mt2[i] = { e, s };
	}
	sort(meeting_time.begin(), meeting_time.end(), compare);
	sort(mt2, mt2 + n);

	int max_meeting = 1, t_index = 0;
	for (int i = 1; i < n; i++){
		if (meeting_time[t_index].start != meeting_time[i].start){
			if (meeting_time[t_index].end <= meeting_time[i].start){
				max_meeting++;
				t_index = i;
			}
			else{
				if (meeting_time[t_index].end > meeting_time[i].end)
					t_index = i;
			}
		}
		else if (meeting_time[t_index].start == meeting_time[t_index].end){
			max_meeting++;
			t_index = i;
		}
	}

	int max2 = 0, before_end = 0;
	for (int i = 0; i < n; i++){
		if (mt2[i].second >= before_end){
			before_end = mt2[i].first;
			max2++;
		}
	}


	cout << max_meeting << endl;
	cout << max2;

	return;
}