// 행렬의 곱셈: https://programmers.co.kr/learn/courses/30/lessons/12949
// 행렬의 계산 방법: https://mathbang.net/562
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    int i, j, x;
    for (i = 0; i < arr1.size(); i++)
    {
        for (j = 0; j < arr2[0].size(); j++)
        {
            int elem = 0;
            for (x = 0; x < arr1[0].size(); x++)
                elem += arr1[i][x] * arr2[x][j];
            answer[i].push_back(elem);
        }
    }
    return answer;
}