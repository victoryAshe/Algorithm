// 영어 끝말잇기: https://programmers.co.kr/learn/courses/30/lessons/12981
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int i; int people = 1, turn = 0;
    for(i = 1; i<words.size(); i++)
    {
        people++; 
        if (people > n) { people = 1;  turn++; }

        // 단어가 유효한지 검사
        if (words[i - 1].back() == words[i].front()
            && find(words.begin(), words.begin() + i, words[i]) == words.begin() + i)
            continue;
        else return { people, turn };
    }
    answer = { 0, 0 };
    return answer;
}