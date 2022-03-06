// K¹øÂ° ¼ö: https://programmers.co.kr/learn/courses/30/lessons/42748
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer; vector<int> temp; int i;

    for (auto a : commands)
    {
        temp.clear();
        temp.assign(array.begin() + a[0] - 1, array.begin() + a[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[a[2] - 1]);
    }

    return answer;
}