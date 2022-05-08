// 땅따먹기: https://programmers.co.kr/learn/courses/30/lessons/12913
// 동적 계획법 사용: https://shanepark.tistory.com/183
// 전역 변수로 선언된 2차원 벡터의 초기화 문제로 segmentation fault가 계속 났었다.
//		-> 전역변수의 초기화는 solution에서 하기!

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> memory;

int Max(vector<int> target)
{
	int i; int largest = 0;
	for (i = 0; i < target.size(); i++)
		largest = target[i] < largest ? largest : target[i];
	return largest;
}

void Steps(vector<int> row, int n)
{
	if (n == 0)
		memory[0] = row;
	else
	{
		memory[n][0] = row[0] + Max({ memory[n - 1][1], memory[n - 1][2] ,memory[n - 1][3] });
		memory[n][1] = row[1] + Max({ memory[n - 1][0], memory[n - 1][2] ,memory[n - 1][3] });
		memory[n][2] = row[2] + Max({ memory[n - 1][0], memory[n - 1][1] ,memory[n - 1][3] });
		memory[n][3] = row[3] + Max({ memory[n - 1][0], memory[n - 1][1] ,memory[n - 1][2] });
	}
}

int solution(vector<vector<int> > land)
{
	memory = vector<vector<int>>(land.size(), vector<int>(4, 0));

	int i;
	for (i = 0; i < land.size(); i++)
		Steps(land[i], i);

	return Max(memory[land.size() - 1]);
}
