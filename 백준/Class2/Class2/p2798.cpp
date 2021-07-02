#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
	return a > b;
}

void p2798(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 
	int n, m;
	vector<int> card;

	// input
	cin >> n >> m;
	for (int i = 0, temp; i < n; i++){
		cin >> temp;
		if (temp >= m)
			continue;
		card.push_back(temp);
	}

	// card sorting
	sort(card.begin(), card.end(), compare);

	// card search
	int max = 0;
	for (int i = 0; i < card.size(); i++){
		if (max > card[i] * 3)
			break;
		for (int j = i + 1; j < card.size(); j++){
			if (m > card[i] + card[j]){
				for (int k = j + 1; k < card.size(); k++){
					if (m >= card[i] + card[j] + card[k]){
						if (max < card[i] + card[j] + card[k])
							max = card[i] + card[j] + card[k];
						break;
					}
				}
			}
		}
	}
	

	// output
	cout << max;

	return;
}