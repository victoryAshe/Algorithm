// ���� ���� �� �����ϱ�: https://programmers.co.kr/learn/courses/30/lessons/12935
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int j = *min_element(arr.begin(), arr.end());
    arr.erase(find(arr.begin(), arr.end(), j));
    return answer.empty() ? vector<int>(1, -1) : answer;;
}