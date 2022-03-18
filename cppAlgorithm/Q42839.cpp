// 소수 찾기: https://programmers.co.kr/learn/courses/30/lessons/42839
// 아직 못 풀었음!
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> added;
void DFS(vector<char> ch, int n, int i, string x)
{
    if (i >= ch.size()) return;
    if (n >= ch.size())
    {
        //return;
        string s = ""; for (int j = 0; j < i + 1; j++) s += ch[j];
        DFS(ch, 0, i + 1, s);
    }

    x += ch[n];
    cout << stoi(x) << " ";
    if (find(added.begin(), added.end(), stoi(x)) == added.end())
        added.push_back(stoi(x));
    DFS(ch, n + 1, i, x);

}

int solution(string numbers) {
    int answer = 0, i; vector<char> ch; 
    for (i = 0; i < numbers.size(); i++) ch.push_back(numbers[i]);
    DFS(ch, 0, 0, "");

    for (int x : added)
    {
        if (x < 2) continue;
        for (i = 2; i < x / 2; i++) if (x % i == 0) break;
        if (i >= x / 2) answer++;
    }

    return answer;
}