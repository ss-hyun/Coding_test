#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 10000000, size = queue1.size();
    long long sum = 0, temp = 0;

    queue1.insert(queue1.end(), queue2.begin(), queue2.end());
    for (long long e : queue1)
        sum += e;

    if (sum % 2)
        return -1;

    sum /= 2;
    int s, e, tmp, x2size = 2 * size, ss, ee;
    for (s = 0, e = 0; e < x2size; e++) {
        temp += queue1[e];
        while (temp > sum) {
            temp -= queue1[s];
            s++;
        }
        if (temp == sum) {
            tmp = s % size + (s / size != e / size ? e % size + 1 : (e % size == size - 1 ? 0 : e % size + size + 1));
            //cout << s << ' ' << e << ' ' << tmp << endl;
            if (answer > tmp) answer = tmp;
            ee = (s - 1) % x2size;
            ss = (e + 1) % x2size;
            tmp = ss % size + (ss / size != ee / size ? ee % size + 1 : (ee % size == size - 1 ? 0 : ee % size + size + 1));
            //cout << ss << ' ' << ee << ' ' << tmp << endl;
            if (answer > tmp) answer = tmp;
            if (answer == 0) break;
        }
    }

    if (answer == 10000000)
        return -1;

    return answer;
}