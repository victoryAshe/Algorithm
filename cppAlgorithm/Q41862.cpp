// 체육복: https://programmers.co.kr/learn/courses/30/lessons/42862
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size(), i;
    vector<int>::iterator p;

    for (i = 0; i < lost.size(); i++)
    {
        p = find(reserve.begin(), reserve.end(), lost[i]);
        if (p != reserve.end())
        {
            reserve.erase(p); lost[i] = 0; answer++;
        }
    }
    sort(lost.begin(), lost.end()); sort(reserve.begin(), reserve.end());

    for (i = 0; i < lost.size(); i++)
    {
        if (lost[i] == 0) continue;

        p = find(reserve.begin(), reserve.end(), lost[i] - 1);
        if (p != reserve.end())
        {
            reserve.erase(p); answer++;
            continue;
        }

        p = find(reserve.begin(), reserve.end(), lost[i] + 1);
        if (p != reserve.end())
        {
            reserve.erase(p); answer++;
        }
    }
    return answer;
}

/*
* [다른 사람 풀이]
* 
#include <vector>

using namespace std;
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}

*/