// [2019 카카오 겨울 인턴십] 크레인 인형뽑기 게임: https://programmers.co.kr/learn/courses/30/lessons/64061
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    /*
    * [Idea]
    * board는 2차원 int 벡터, move는 1차원 int 벡터
    * 인형뽑기: 1차 idx가 높이 있는 것의 2차 idx(move[idx]-1)를 꺼내 basket에 넣고 해당 idx를 0으로 바꿈
    * basket: 1차원 int 벡터
    * 인형 터지기: basket에 인형(int y)을 넣고자 할때 
    *              if basket의 마지막 idx의 숫자가 y와 같으면: 해당 숫자를 erase하고 answer+=2
    *              else : basket.push_back(y)
    */
    vector<int> basket = { 0 }; int answer = 0;
    int i, y;
    // 인형뽑기
    for (int x : moves)
    {
        y = 0;
        //인형 y = x-1번째 column의 0이 아닌 첫 int <- row마다 검사
        for (i = 0; i < board.size(); i++) if (board[i][x - 1] != 0)
        {
            y = board[i][x - 1]; board[i][x - 1] = 0;
            break;
        }
        // basket에 넣기
        if (basket[basket.size() - 1] == y && y != 0)
        {
            if (basket.size() == 1) basket[0] = 0;
            else basket.erase(basket.end() - 1);
            answer += 2;
        }
        else basket.push_back(y);
    }
    return answer;
}