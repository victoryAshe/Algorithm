// 2018 카카오_ [1차] 프렌즈4블록: https://programmers.co.kr/learn/courses/30/lessons/17679
// 아직 못 풀었음
/*
#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int i, j;
    while (true)
    {
        vector<vector<bool>> blocks(m, vector<bool>(n, false));

        // 삭제될 블록이 있는지 확인하여 체크
        for (i = 0; i < m - 1; i++)
        {
            for (j = 0; j < n - 1; j++)
            {
                if (board[i][j]='X') continue;
                if (board[i][j] == board[i][j + 1]
                    && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1])
                {
                    blocks[i][j] = blocks[i][j + 1] = blocks[i + 1][j] = blocks[i + 1][j + 1] = true;
                }
            }
        }

        int delBlocks = 0;
        for (vector<bool> r : blocks)for (bool x : r) if (x) delBlocks++;
        if (delBlocks == 0) break;
        answer += delBlocks;

        // TODO: 블록 삭제 및 이동
        for (i = m - 1; i >= 0; i--)
        {
            for (j = 0; j < board[i].length(); j++)
            {
                if (blocks[i][j])
                {
                    int target = i;
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (board[k][j] != 'X')
                        {
                            board[target][j] = board[k][j];
                            board[k][j] = 'X';
                            target--;
                        }
                    }
                }
            }
        }
    }


    return answer;
}
*/

// 다른 사람 풀이:  https://yabmoons.tistory.com/567
#include <string>
#include <vector>
using namespace std;

int N, M;

//2*2 block인지를 확인
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

bool Check(int x, int y, vector<string> board)
{
    int i, nx, ny;
    for (i = 0; i < 3; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) return false;
        if (board[x][y] != board[nx][ny]) return false;
    }
    return true;
}

// 블록을 지우는 과정
int Delete_Block(vector<pair<int, int>> V, vector<string>& board)
{
    int Cnt = 0;
    int i, j, x, y, nx, ny;
    for (i = 0; i < V.size(); i++)
    {
        x = V[i].first;
        y = V[i].second;
        if (board[x][y] != '.')
        {
            board[x][y] = '.';
            Cnt++;
        }

        for (j = 0; j < 3; j++)
        {
            nx = x + dx[j];
            ny = y + dy[j];
            if (board[nx][ny] != '.')
            {
                Cnt++;
                board[nx][ny] = '.';
            }
        }
    }
    return Cnt;
}

void Arrange_MAP(vector<string>& board)
{
    int i, j, nx;
    for (i = N - 1; i >= 0; i--)
    {
        for (j = 0; j < M; j++)
        {
            if (board[i][j] == '.') continue;

            nx = i + 1;
            while (nx < N && board[nx][j] == '.') nx++;
            nx--;
            if (nx != i)
            {
                board[nx][j] = board[i][j];
                board[i][j] = '.';
            }
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    N = m;
    M = n;
    int answer = 0;
    bool Flag = true;

    int i, j;
    while (Flag)
    {
        Flag = false;
        vector<pair<int, int>> V;
        vector<vector<bool>> Visit(N, vector<bool>(M, false));
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (board[i][j] == '.') continue;
                if (Check(i, j, board))
                {
                    V.push_back(make_pair(i, j));
                    Flag = true;
                }
            }
        }

        if (Flag)
        {
            answer += Delete_Block(V, board);
            Arrange_MAP(board);
        }
    }
    return answer;
}

