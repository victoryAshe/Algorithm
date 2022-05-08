// 2018 카카오_ [1차] 프렌즈4블록: https://programmers.co.kr/learn/courses/30/lessons/17679
// 아직 못 풀었음
#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> blocks(m, vector<bool>(n, false));
    int i, j;
    while(true)
    {
        // 삭제될 블록이 있는지 확인하여 체크
        for (i = 0; i < m-1; i++)
        {
            for (j = 0; j < n-1; j++)
            {
                if (isdigit(board[i][j])) continue;
                if (board[i][j] == board[i][j + 1]
                    && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1])
                {
                    blocks[i][j] = true;  blocks[i][j + 1] = true;
                    blocks[i + 1][j] = true; blocks[i + 1][j + 1] = true;
                }
            }
        }

        // TODO: 블록 삭제 및 이동
    }

    return answer;
}