// 소수 만들기: https://programmers.co.kr/learn/courses/30/lessons/12977
#include <vector>
#include <algorithm>
using namespace std;

bool check(int num)
{
    int x;
    for (x = 2; x < num / 2; x++) if (num % x == 0) return false;
    return true;
}

int solution(vector<int> nums) {
    int answer = 0, i, j, k, N = nums.size();
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++)
            for (k = j + 1; k < N; k++)
                if (check(nums[i] + nums[j] + nums[k])) answer++;

    return answer;
}