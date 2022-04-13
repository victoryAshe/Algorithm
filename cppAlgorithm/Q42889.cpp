// [2019 카카오] 실패율: https://programmers.co.kr/learn/courses/30/lessons/42889
// 배운 것: pair, make_pair로 dictionary와 유사한 형태의 vector형을 만들 수 있다.
// 아래와 같이 클래스를 새로 만들어서 compare해주면 코드는 더 길어지지만 pair를 비교하는 것보다 2배 빨리 처리된다.
// 이 문제를 풀 때 주의할 점: 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0으로 정의한다는 점.
//                            만약 실패율이 같은 스테이지가 있다면, 작은 번호의 스테이지가 먼저 오도록 한다는 점.
#include <vector>
#include <algorithm>
using namespace std;

class Fail {
public:
    int stage; float fail;
    Fail(int stage, float fail) {
        this->stage = stage;
        this->fail = fail;
    }
    bool operator>(const Fail& f) const {
        if (this->fail == f.fail) return this->stage < f.stage;
        return this->fail > f.fail;
    }
};
bool compare(Fail a, Fail b) { return a > b; }

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer; int i;
    float fail, challenge = stages.size();
    vector<Fail> fails;
    for (i = 1; i <= N; i++)
    {
        fail = count(stages.begin(), stages.end(), i);
        if (challenge == 0) fails.push_back(Fail(i, 0));
        else fails.push_back(Fail(i, fail / challenge));
        challenge -= fail;
    }
    sort(fails.begin(), fails.end(), compare);
    for (i = 0; i < fails.size(); i++) answer.push_back(fails[i].stage);
    return answer;
}
/*
*
// pair, make_pair를 이용한 풀이

#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int,float>&a, const pair<int, float>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second; 
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer; int i;
    float fail, challenge = stages.size();
    vector<pair<int, float>> fails;
    for (i = 1; i <= N; i++)
    {
        fail = count(stages.begin(), stages.end(), i);
        if (challenge == 0) fails.push_back(make_pair(i, 0));
        else fails.push_back(make_pair(i, fail / challenge));
        challenge -= fail;
    }
    sort(fails.begin(), fails.end(), compare);
    vector<pair<int, float>>::iterator p = fails.begin();
    for (p = fails.begin(); p != fails.end(); p++) answer.push_back(p->first);
    return answer;
}
*/