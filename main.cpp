#include "DoubleLinkedList.h"
#include <cstdio>

int main()
{
	DoubleLinkedList ddl;
	ddl.push_back(2);
	ddl.push_back(3);
	ddl.push_back(4);
	ddl.push_front(1);
	ddl.push_front(6);

	ddl.search();
	//ddl.search_reverse();

	ddl.pop_back();
	ddl.pop_back();
	ddl.pop_front();

	ddl.search();

	printf("size() %d\n", ddl.size());
	printf("front() %d\n", ddl.front());
	printf("back() %d\n", ddl.back());

	//ddl.erase(1);
	//ddl.search();

	//ddl.erase(0);
	//ddl.search();
}