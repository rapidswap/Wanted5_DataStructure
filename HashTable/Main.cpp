#include "SmartHashTable.h"
#include <iostream>


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SmartHashTable table;

	// 키-값 데이터 추가.
	table.Add("Kang", "010-1244-1123");

	// 중복 키 추가 확인.
	if (!table.Add("Kang", "010-234-5552"))
	{
		std::cout << "이미 같은 키가 저장되어 있습니다.\n";
	}
	table.Add("Park", "010-1244-1123");
	table.Add("Lee", "010-1244-1123");
	table.Add("Kim", "010-1244-1123");


	// 출력.
	std::cout << "\n 전체 데이터 \n";
	table.Print();

	// 검색.
	std::string number;
	if (table.Find("Kang", number))
	{
		std::cout << "\n 검색 결과: Kang, " << number << "\n";
	}

	// 삭제.
	if (table.Delete("Lee"))
	{
		std::cout << "Lee 삭제\n";
	}

	//출력.
	std::cout << "\n삭제 후 데이터\n";
	table.Print();
}