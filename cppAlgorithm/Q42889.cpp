// [2019 īī��] ������: https://programmers.co.kr/learn/courses/30/lessons/42889
// ��� ��: pair, make_pair�� dictionary�� ������ ������ vector���� ���� �� �ִ�.
// �Ʒ��� ���� Ŭ������ ���� ���� compare���ָ� �ڵ�� �� ��������� pair�� ���ϴ� �ͺ��� 2�� ���� ó���ȴ�.
// �� ������ Ǯ �� ������ ��: ���������� ������ ������ ���� ��� �ش� ���������� �������� 0���� �����Ѵٴ� ��.
//                            ���� �������� ���� ���������� �ִٸ�, ���� ��ȣ�� ���������� ���� ������ �Ѵٴ� ��.
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
// pair, make_pair�� �̿��� Ǯ��

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