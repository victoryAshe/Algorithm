// 2019 카카오_튜플: https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> sets;
    vector<int> set;
    int i, j;
    string num = "";
    for (i = 1; i < s.length() - 1; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            if (s[i] == '}')
            {
                set.push_back(stoi(num));
                num = "";
                sets.push_back(set);
                set.clear();
            }
            if (s[i] == ',' && num != "")
            {
                set.push_back(stoi(num));
                num = "";
            }
            continue;
        }
        num += s[i];

    }

    sort(sets.begin(), sets.end(), compare);

    set.clear();
    answer.push_back(sets[0][0]);
    for (i = 1; i < sets.size(); i++)
    {
        set = sets[i - 1];
        for (j = 0; j < sets[i].size(); j++)
        {
            if (find(set.begin(), set.end(), sets[i][j]) == set.end())
                answer.push_back(sets[i][j]);
        }
    }

    return answer;
}