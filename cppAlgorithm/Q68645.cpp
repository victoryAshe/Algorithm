// 월간 코드 챌린지 시즌 1_ 삼각 달팽이: https://programmers.co.kr/learn/courses/30/lessons/68645
// 아직 못 풀었음
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle;
    int i, j;
    for (i = 0; i < n; i++) triangle.push_back(vector<int>(i+1));
    int sum = 0;
    for (i = 1; i <= n; i++) sum += i;
    int num = 0; i = 0; j = 0; string dir = "down";
    int dMax = n-1, rMax = n - 1, uMax = 1;
    while (num <= sum)
    {
        num++;
        triangle[i][j] = num;

        if (dir == "down")
        {
            i++;
            if (i > dMax)
            {
                i--; dMax--; 
                dir = "right"; continue;
            }
        }
        if (dir == "right")
        {
            j++;
            if (j > rMax)
            {
                rMax -= 2; i--; j-=2;
                dir = "up"; continue;
            }
        }
        if (dir == "up")
        {
            i--; j--;
            if (i < uMax)
            {
                uMax--; i += 2; j ++;
                dir = "down"; continue;
            }
        }


    }
    /*
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < triangle[i].size(); i++) answer.push_back(triangle[i][j]);
    }
    
    */

    return answer;
}

void main()
{
    vector<int> answer = solution(4);
    int i;
    for (i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    return;
}