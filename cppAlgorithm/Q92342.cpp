// 2022 카카오_ 양궁대회: https://programmers.co.kr/learn/courses/30/lessons/92342
/*
#include <string>
#include <vector>
using namespace std;

struct Pair
{
public:
    int scoreA;
    int scoreB;
    int sub;
    vector<int> infoB;

    Pair(int a, int b, vector<int>info)
    {
        scoreA = a; scoreB = b; infoB = info;
        sub = b - a;
    }
};

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    for (int i = 0; i < info.size(); i++)
    {
        
    }


    return answer;
}
*/

// 다른 사람 풀이: https://velog.io/@ddyy094/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%96%91%EA%B6%81%EB%8C%80%ED%9A%8C-C-%EC%99%84%EC%A0%84%ED%83%90%EC%83%89-2022%EC%B9%B4%EC%B9%B4%EC%98%A4
#include <string>
#include <vector>
using namespace std;

vector<int> answer(1, -1);
int maxDiff = 0;

// 작은 점수에 화살이 더 많이 분포되어있는지를 확인
bool cmp(vector<int> ryan)
{
    // 적은 점수부터 확인
    for (int i = 10; i >= 0; i--)
    {
        if (ryan[i] > answer[i]) return true;
        else if (ryan[i] < answer[i]) return false;
    }
}

// 점수 계산 함수
void calcScore(vector<int> ryan, vector<int> apeach)
{
    int ryanScore = 0;
    int apeachScore = 0;

    for (int i = 0; i < 11; i++)
    {
        if (ryan[i] > apeach[i]) ryanScore += 10 - i;
        else if (apeach[i] > 0) apeachScore += 10 - i;
    }

    int diff = ryanScore - apeachScore;
    if (diff > 0 && maxDiff <= diff)
    {
        if (maxDiff == diff && !cmp(ryan))return;
        maxDiff = diff;
        answer = ryan;
    }
}

// 화살 부여 함수
void solve(int idx, int arrows, vector<int>ryan, vector<int>apeach)
{
    // 분배 끝: 재귀 탈출
    if (idx == 1 || arrows == 0)
    {
        ryan[10] += arrows;
        calcScore(ryan, apeach);
        ryan[10] -= arrows;
        return;
    }

    if (apeach[idx] < arrows)
    {
        ryan[idx] += apeach[idx] + 1;
        solve(idx + 1, arrows - apeach[idx] - 1, ryan, apeach);
        ryan[idx] -= apeach[idx] + 1;
    }
    solve(idx + 1, arrows, ryan, apeach);
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> ryan(11, 0);

    solve(0, n, ryan, info);

    if (answer.empty()) answer.push_back(-1);
    return answer;
}