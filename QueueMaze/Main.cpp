#include "Queue.h"
#include <iostream>

// 이동 좌표를 처리하기 위한 클래스.
class Location2D
{
public:
	Location2D(int row = 0, int col = 0)
		:row(row), col(col)
	{

	}

public:
	// 행-Y축.
	int row;
	// 열-X축.
	int col;
};

const int MazeSize = 6;
// 미로.
char maze[MazeSize][MazeSize] =
{
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}
};

// 맵에서 방문을 했느지 확인하기 위한 배열.
bool visited[MazeSize][MazeSize] = {};

// 전달한 미로의 위치가 이동 가능한지 판단하는 함수.
// row - 행 - y 축 | col - 열 - x축 값.
bool IsValidLocation(int row, int col)
{
	// 미로의 범위를 벗어났는지 확인.
	if (row < 0 || row >= MazeSize || col < 0 || col >= MazeSize)
	{
		return false;
	}

	// 이미 방문한 위치인지 확인.
	if (visited[row][col])
	{
		return false;
	}

	// 길이거나 출구인 경우 이동 가능.
	return maze[row][col] == '0' || maze[row][col] == 'x';
}

int main()
{
	int startRow = -1;
	int startCol = -1;

	// 미로 출력 및 시작 위치 탐색.
	for (int row = 0;row < MazeSize;++row)
	{
		for (int col = 0;col < MazeSize;++col)
		{
			// 시작 위치인지 확인.
			if (maze[row][col] == 'e')
			{
				startRow = row;
				startCol = col;
			}

			// 미로 출력.
			std::cout << maze[row][col] << ' ';
		}
		std::cout << "\n";
	}

	// 입구를 찾지 못한 경우 탐색 종료.
	if (startRow == -1 || startCol == 1)
	{
		std::cout << "입구를 못찾음\n";
		return 0;
	}

	// 탐색을 위한 큐
	Queue<Location2D> locationQueue;

	locationQueue.Enqueue(Location2D(startRow, startCol));

	visited[startRow][startCol] = true;

	// 상하좌우 이동에 사용할 오프셋 값 (방향 데이터로 활용함).
	int rowOffset[] = { -1,1,0,0 };
	int colOffset[] = { 0,0,-1,1 };

	// 출력 정렬 목적으로 변수 선언.
	int printCount = 0;

	// 큐에 저장된 탐색 가능한 위치가 있으면 반복 수행.
	while (!locationQueue.IsEmpty())
	{
		// 탐색을 위해서 저장된 가장 최근의 위치 꺼냄.
		Location2D current;
		locationQueue.Dequeue(current);

		// 행과 열 구하기.
		int row = current.row;
		int col = current.col;

		// 현재 탐색한 위치 출력.
		std::cout << "(" << row << ", " << col << ") ";
		++printCount;

		// 한 줄에 출력한 수가 10개면 다음 줄로 넘김.
		if (printCount == 10)
		{
			printCount = 0;
			std::cout << "\n";
		}

		if (maze[row][col] == 'x')
		{
			std::cout << "\n 미로 탐색 성공 \n";
			return 0;
		}

		if (maze[row][col] != 'e')
		{
			maze[row][col] = '.';
		}

		// 현재 위치에서 상하좌우의 이동 가능한 위치를 스택에 저장.
		for (int ix = 0;ix < 4;++ix)
		{
			int nextRow = row + rowOffset[ix];
			int nextCol = col + colOffset[ix];

			// 다음 좌표가 가능한지 확인.
			if (IsValidLocation(nextRow, nextCol))
			{
				// 이동 가능한 위치는 스택에 추가.
				Location2D nextLocation(nextRow, nextCol);

				// 스택에 추가.
				if (locationQueue.Enqueue(nextLocation))
				{
					visited[nextRow][nextCol] = true;
				}
			}
		}
	}

	// 탐색 실패.
	std::cout << "\n 미로 탐색 실패 \n";
}