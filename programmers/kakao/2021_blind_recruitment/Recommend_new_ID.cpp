#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (char a : new_id) {
        if (a >= 'A' && a <= 'Z')
            a = a - 'A' + 'a';
        else if (a != '-' && a != '_' & a != '.' && !(a >= '0' && a <= '9') && !(a >= 'a' && a <= 'z'))
            continue;
        else if (a == '.'){
            if (answer.back() == '.')
                continue;
        }
        answer.push_back(a);
    }
    
    if (answer.front() == '.')
        answer.erase(0, 1);
    if (answer.back() == '.')
        answer.pop_back();
    
    if (answer.empty())
        answer.push_back('a');
    
    if (answer.length() > 15)
        answer = answer.substr(0, 15);
    if (answer.back() == '.')
        answer.pop_back();
    
    while (answer.length() < 3)
        answer.push_back(answer.back());

    return answer;
}