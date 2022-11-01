#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> score;

void init() {
    score['R'] = 0;
    score['T'] = 0;
    score['C'] = 0;
    score['F'] = 0;
    score['J'] = 0;
    score['M'] = 0;
    score['A'] = 0;
    score['N'] = 0;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    init();

    char disagree, agree;
    for (int i = 0; i < survey.size(); i++) {
        disagree = survey[i][0];
        agree = survey[i][1];
        if (choices[i] < 4)
            score[disagree] += 4 - choices[i];
        else if (choices[i] > 4)
            score[agree] += choices[i] - 4;
    }

    if (score['R'] < score['T'])
        answer.push_back('T');
    else
        answer.push_back('R');

    if (score['C'] < score['F'])
        answer.push_back('F');
    else
        answer.push_back('C');

    if (score['J'] < score['M'])
        answer.push_back('M');
    else
        answer.push_back('J');

    if (score['A'] < score['N'])
        answer.push_back('N');
    else
        answer.push_back('A');

    return answer;
}