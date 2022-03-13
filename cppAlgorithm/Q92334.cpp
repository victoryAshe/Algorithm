// [2022 카카오] 신고 결과 받기: https://programmers.co.kr/learn/courses/30/lessons/92334
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id, vector<string> report, int k) {
    vector<int> answer(id.size()); int K, i;
    map<string, vector<string>> history;
    map<string, vector<string>>::iterator p; string reporter, target = "", targetA;
    vector<string> stopped;
    sort(report.begin(), report.end());
    // 신고 목록 작성
    for (string x : report)
    {
        stringstream ss(x); ss >> reporter; ss >> targetA;

        if (history.find(reporter) != history.end())
        {
            if (targetA == target) continue;
            target = targetA;
            history[reporter].push_back(target);
        }
        else
        {
            target = targetA;
            history[reporter] = { target };
        }
    }

    // ID 당 신고 수 적립
    for (string x : id)
    {
        K = 0;
        for (string y : id)
            if (find(history[y].begin(), history[y].end(), x) != history[y].end())
                K++;

        if (K >= k) stopped.push_back(x);
    }

    for (i = 0; i < id.size(); i++)
    {
        if (history.find(id[i]) != history.end())
        {
            for (string y : stopped)
                if (find(history[id[i]].begin(), history[id[i]].end(), y) != history[id[i]].end())
                    answer[i] += 1;
        }
    }
    return answer;
}