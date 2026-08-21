#include "Queue.h"
#include <iostream>
int main()
{
	// 큐의 크기.
	const int count = 5;

	// 큐 객체 생성.
	Queue<int, count> queue;

	// 큐에 데이터 추가.
	for (int ix = 0;ix < count + 1;++ix)
	{
		queue.Enqueue(ix + 1);
	}

	queue.Print();

	// 맨 앞에 데이터 읽기.
	int firstValue = 0;
	if (queue.Front(firstValue))
	{
		std::cout << "첫 번째 데이터: " << firstValue << "\n";
	}

	// 데이터 출력.
	int outValue = 0;
	if (queue.Dequeue(outValue))
	{
		std::cout << "출력된 데이터: " << outValue << "\n";
	}

	queue.Print();

}