// 22-1 자료구조 도전과제 - 미로찾기
#include <iostream>
#include <stack>
using namespace std;

struct Location2D 
{
	int row, col;
	Location2D(int r = 0, int c = 0) { row = r; col = c; }

	// 위치 p가 자신의 이웃인지 검사
	bool isNeighbor(Location2D& p)
	{
		return((row == p.row && (col == p.col - 1 || col == p.col + 1)))
			|| (col == p.col && (row == p.row - 1 || row == p.row + 1));
	}

	// 연산자 오버로딩: 위치 p가 자신과 같은 위치인지를 검사
	bool operator==(Location2D& p) { return row == p.row && col == p.col; }
};

const int MAZE_SIZE = 10; // 미로 맵 크기 고정
char map[MAZE_SIZE][MAZE_SIZE] =
{
	{'1','1','1','1','1','1','1','1','1','1'},
	{'0','0','0','0','1','0','0','0','0','1'},
	{'1','0','0','0','1','0','0','0','0','1'},
	{'1','0','1','1','1','0','0','1','0','1'},
	{'1','0','0','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','0','0','0','1','0','x'},
	{'1','1','1','1','1','1','1','1','1','1'}
};

// (r,c)가 갈 수 있는 위치인지 검사: (r,c)가 배열 안에 있고, 값이 '0' || 'x'
bool isValidLoc(int r, int c){
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

void main()
{
	//위치 스택 객체 생성
	stack<Location2D> locStack; 
	
	// 입구
	Location2D entry(1, 0);
	locStack.push(entry);


	//스택이 비어있지 않는 동안
	while (!locStack.empty())
	{
		Location2D here = locStack.top(); // 현재 위치: 스택 상단 객체 복사
		locStack.pop(); // 스택에서 상단 객체 삭제

		int r = here.row, c = here.col;
		cout << "(" << r << ", " << c << ") "<< endl;
		if (map[r][c] == 'x') // 출구이면: 탐색 성공 -> 종료
		{
			cout << "미로 탐색 성공" << endl;
			return;
		}
		else
		{
			map[r][c] = '.'; // 출구가 아니면: 현재 위치를 지나옴 처리 -> '.'
			if (isValidLoc(r - 1, c))locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c))locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1))locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1))locStack.push(Location2D(r, c + 1));
		}
	}
	cout << " 미로 탐색 실패" << endl;
}