// 백준 1764번 듣보잡
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;


void p1764() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);   

  int n, m;
  cin >> n >> m;

  string temp;
  unordered_set<string> n_listen;
  for(int i=0; i<n; i++){
    cin >> temp;
    n_listen.insert(temp);
  }
  vector<string> n_see;
  for(int i=0; i<m; i++){
    cin >> temp;
    n_see.push_back(temp);
  }
  sort(n_see.begin(),n_see.end());
  vector<int> check;
  for(int i=0; i<m; i++){
    if(n_listen.find(n_see[i])!=n_listen.end())
      check.push_back(i);
  }

  cout << check.size() << '\n';
  for(int i : check){
    cout << n_see[i] << '\n';
  }

  return;
}
