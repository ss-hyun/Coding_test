#include <string>
#include <vector>

using namespace std;

int search(int idx, int sum, vector<int> numbers, int target) {
    if (idx == numbers.size())
        return sum == target;

    int num = 0;
    num += search(idx + 1, sum + numbers[idx], numbers, target);
    num += search(idx + 1, sum - numbers[idx], numbers, target);

    return num;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = search(0, 0, numbers, target);

    return answer;
}