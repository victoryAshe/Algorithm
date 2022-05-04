// 최댓값과 최솟값: https://programmers.co.kr/learn/courses/30/lessons/12939
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss;
    ss.str(s);
    vector<int> nums; int num;
    while (ss >> num) nums.push_back(num);
    sort(nums.begin(), nums.end());
    answer = to_string(nums[0]) + ' ' + to_string(nums[nums.size() - 1]);

    return answer;
}