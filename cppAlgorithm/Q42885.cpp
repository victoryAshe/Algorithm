// 탐욕법_구명보트: https://programmers.co.kr/learn/courses/30/lessons/42885
// 아직 못 풀었음
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, i, weight = 0;
    sort(people.begin(), people.end());
    
    for (i = 0; i < people.size(); i++)
    {
        weight += people[i];
        if (weight + people[i + 1] >= limit)
        {
            answer++;
            weight = 0;
            continue;
        }
    }

    return answer;
}