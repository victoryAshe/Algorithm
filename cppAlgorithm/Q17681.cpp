// [카카오 2018 1차] 비밀지도: https://programmers.co.kr/learn/courses/30/lessons/17681
#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    int i, j; string s1, s2;  vector<string> answer;
    for (i = 0; i < arr1.size(); i++)
    {
        s1 = bitset<65>(arr1[i]).to_string();
        s2 = bitset<65>(arr2[i]).to_string();
        s1 = s1.substr(65 - n); s2 = s2.substr(65 - n);
        for (j = 0; j < s1.size(); j++)
        {
            if (s1[j] == s2[j] && s1[j] == '0') s1[j] = ' ';
            else if (s1[j] == '1' || s2[j] == '1') s1[j] = '#';
        }
        answer.push_back(s1);
    }
    return answer;
}