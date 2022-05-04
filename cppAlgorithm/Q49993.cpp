// 스킬트리: https://programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(string skill, string tree)
{
    vector<int> indexes;
    int i, idx = 0;
    for (i = 0; i < skill.length(); i++)
        indexes.push_back(tree.find(skill[i]));

    if (find(indexes.begin(), indexes.end(), -1) != indexes.end())
    {
        idx = find(indexes.begin(), indexes.end(), -1) - indexes.begin();
        for (i = idx; i < indexes.size(); i++)
        {
            if (indexes[i] != -1) return false;
        }
    }

    vector<int> sorted;
    if (idx != 0)
    {
        sorted.assign(indexes.begin(), indexes.begin() + idx);
        indexes = sorted;
    }
    else
        sorted = indexes;

    sort(sorted.begin(), sorted.end());
    return(sorted == indexes);
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int i;
    for (i = 0; i < skill_trees.size(); i++)
    {
        if (isValid(skill, skill_trees[i])) answer++;
    }

    return answer;
}