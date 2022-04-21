// 소수 찾기: https://programmers.co.kr/learn/courses/30/lessons/42839
// 아직 못 풀었음!
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> prime;

void DFS(string& numbers, string number, int i, int len)
{
    if (len >= number.size()) return;

    number += numbers[i];
    cout << number << " ";

    int num = stoi(number);
    int j;
    for (j = 0; j < num / 2; j++) if (num % j == 0) break;
    if (j < num / 2 && find(prime.begin(), prime.end(), num) != prime.end())
        prime.push_back(num);

    DFS(numbers, number, i, len + 1);
    DFS(numbers, number, i - 1, len + 1);
}


int solution(string numbers) {

    string number = "";
    sort(numbers.begin(), numbers.end(), greater<char>());
    if (numbers[0] == '0') return 0;

    DFS(numbers, number, 0, 0);
    DFS(numbers, number, numbers.length() - 1, 0);

    for (int i = 0; i < prime.size(); i++) cout << prime[i] << " ";
    return prime.size();
}