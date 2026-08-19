#include <iostream>
#include <cstdint>
#include <cassert>
#include <algorithm>

// 배열 클래스
template<typename T,size_t size>
class Array
{
public:

	// 배열 연산자 오버로딩.
	T& operator[](size_t index)
	{
		assert(index < size && "index shuold be less than size.");
		return data[index];
	}

	const T& operator[](size_t index) const
	{
		assert(index < size && "index shuold be less than size.");
		return data[index];
	}

	T* begin()
	{
		// 배열의 시작 주소 반환.
		return data;
	}

	T* end()
	{
		return data + size;
	}


	T* Data() { return data; }
	const T* Data() const { return data; }

	size_t Length() const { return size; }

private:
	T data[size]{};
};

int main()
{
	// Array 객체 생성.
	Array<int,5> intArray;
	//std::fill(intArray.Data(), intArray.Data() + intArray.Length(), 20);
	std::fill(intArray.begin(), intArray.end(), 100);

	// 범위 기반 루프.
	for (const int& value : intArray)
	{
		std::cout << value << ' ';
	}

	//intArray[0] = 10;
	//intArray[5] = 30;
	//int intNumber = intArray[0];

	// 정적 배열.
	const uint32_t size = 5;
	int array[size] = {};
	array[0] = 10;
	array[1] = 20;

	int number = array[0];
	
	// 동적 배열(힙에 할당되는 배열)
	uint32_t dSize = 10;
	int* dArray = new int[dSize] {};
	
	delete[] dArray;
}

