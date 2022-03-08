// [2019 īī�� �ܿ� ���Ͻ�] ũ���� �����̱� ����: https://programmers.co.kr/learn/courses/30/lessons/64061
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    /*
    * [Idea]
    * board�� 2���� int ����, move�� 1���� int ����
    * �����̱�: 1�� idx�� ���� �ִ� ���� 2�� idx(move[idx]-1)�� ���� basket�� �ְ� �ش� idx�� 0���� �ٲ�
    * basket: 1���� int ����
    * ���� ������: basket�� ����(int y)�� �ְ��� �Ҷ� 
    *              if basket�� ������ idx�� ���ڰ� y�� ������: �ش� ���ڸ� erase�ϰ� answer+=2
    *              else : basket.push_back(y)
    */
    vector<int> basket = { 0 }; int answer = 0;
    int i, y;
    // �����̱�
    for (int x : moves)
    {
        y = 0;
        //���� y = x-1��° column�� 0�� �ƴ� ù int <- row���� �˻�
        for (i = 0; i < board.size(); i++) if (board[i][x - 1] != 0)
        {
            y = board[i][x - 1]; board[i][x - 1] = 0;
            break;
        }
        // basket�� �ֱ�
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