#include <string>
#include <vector>

using namespace std;

bool visit_computer[200];

void visit_network(int cur, int n, vector<vector<int>> computers) {
    if (visit_computer[cur])
        return;

    visit_computer[cur] = true;
    for (int i = 0; i < n; i++) {
        if (computers[cur][i])
            visit_network(i, n, computers);
    }

    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!visit_computer[i]) {
            visit_network(i, n, computers);
            answer++;
        }
    }

    return answer;
}