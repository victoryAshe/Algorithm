// 스킬트리: https://programmers.co.kr/learn/courses/30/lessons/49993
// 아직 못 풀었음
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool isValid(string skill, string tree)
{
    vector<int> indexes;
    int i;
    for (i = 0; i < skill.length(); i++)
        indexes.push_back(tree.find(skill[i]));
    vector<int> sorted = indexes;
    sort(sorted.begin(), sorted.end());

    return(sorted == indexes);

}


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int i;
    for (i = 0; i < skill_trees.size(); i++)
    {
        if (isValid(skill, skill_trees[i]))
        {
            cout << skill_trees[i] << endl;
            answer++;
        }
    }



    return answer;
}