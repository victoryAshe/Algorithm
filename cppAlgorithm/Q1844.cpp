// 게임 맵 최단거리: https://programmers.co.kr/learn/courses/30/lessons/1844
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

bool checkRight(vector<vector<int>> maps, int x, int y)
{
	if (x >= maps[0].size() - 1) return false;

	if (maps[y][x + 1] == 1) return true;
	return false;
}

bool checkDown(vector<vector<int>> maps, int x, int y)
{
	if (y >= maps.size() - 1) return false;

	if (maps[y + 1][x] == 1) return true;
	return false;
}

bool checkUp(vector<vector<int>> maps, int x, int y)
{
	if (y <= 0) return false;

	if (maps[y-1][x] == 1) return true;
	return false;
}

bool checkLeft(vector<vector<int>> maps, int x, int y)
{
	if (x <= 0) return false;

	if (maps[y][x - 1] == 1) return true;
	return false;
}

class Point
{
public:
	int x, y;
	Point(int x, int y)
	{
		this->x = x; this->y = y;
	}
};

int solution(vector<vector<int>> maps)
{
	int answer = 0;

	if (maps[maps.size() - 1][maps[0].size() - 2] == 0
		&& maps[maps.size() - 2][maps[0].size() - 1] == 0)
	{
		answer = -1; return answer;
	}

	int roadNum = 0; // 건널 수 있는 칸의 갯수
	for (int i = 0; i <= maps.size(); i++)
	{
		roadNum += count(maps[i].begin(), maps[i].end(), 1);
	}
	vector<vector<bool>> checked(maps.size(), vector<bool>(maps[0].size(), false));
	vector<vector<int>> distances(maps.size(), vector<int>(maps[0].size()));

	int endX = maps[0].size() - 1, endY = maps.size() - 1;
	int x = 0, y = 0;  int distance = 0;
	while (distances[endY][endX] == 0)
	{
		distance++;

	}

	return answer;
}

int main()
{
	vector<vector<int>> maps = { {1,0,1,1,1}, {1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} };
	int answer = solution(maps);
	cout << answer << endl;
	return 0;
}