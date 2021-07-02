#include <iostream>
#include <string>

using namespace std;

void p1259(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	
	int num; string snum; bool flag;
	while (true){
		flag = true;
		cin >> num;
		if (!num)
			break;
		snum = to_string(num);
		for (int i = 0; i <= snum.size() / 2; i++){
			if (snum[i] != snum[snum.size() - i - 1]){
				cout << "no\n";
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "yes\n";
	}

	return;
}