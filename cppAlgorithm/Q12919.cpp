// 서울에서 김서방 찾기: https://programmers.co.kr/learn/courses/30/lessons/12919
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

string solution(vector<string> seoul) {
    int index = distance(seoul.begin(), find(seoul.begin(), seoul.end(), "Kim"));
    return "김서방은 " + to_string(index) + "에 있다";
}