#include "DoubleLinkedList.h"
#include <cstdio>

void DoubleLinkedList::push_front(int data)
{
	Node* newNode = new Node(data);
	bool result = setHead(newNode);

	if (false == result)
	{
		Node* prevHead = _head;
		_head = newNode;
		_head->next = prevHead;
		prevHead->prev = newNode;

		++_size;
	}
}

void DoubleLinkedList::push_back(int data)
{
	Node* newNode = new Node(data);
	bool result = setHead(newNode);

	if (false == result)
	{
		Node* end = _head;

		while (end->next)
		{
			end = end->next;
		}

		end->next = newNode;
		_tail = newNode;
		newNode->prev = end;

		++_size;
	}
}

void DoubleLinkedList::pop_front()
{
	if (0 != _size)
	{
		Node* node = _head;
		_head = _head->next;
		if (nullptr != _head)
		{
			_head->prev = nullptr;
		}		

		--_size;

		delete node;
	}
}

void DoubleLinkedList::pop_back()
{
	if (0 != _size)
	{
		Node* node = _tail;
		_tail = _tail->prev;
		if (nullptr != _tail)
		{
			_tail->next = nullptr;
		}

		--_size;

		delete node;
	}
}

void DoubleLinkedList::erase(int pos)
{
	if (pos < _size)
	{
		Node* target = _head;
		int index = 0;
		while (target) 
		{
			if (pos == index)
			{
				int result = target->data;

				if (_head == target)
				{
					pop_front();
				}
				else if (_tail == target)
				{
					pop_back();
				}
				else
				{
					Node* prev = target->prev;
					Node* next = target->prev;
					prev->next = next;
					next->prev = prev;

					delete target;
				}				
			}
			target = target->next;

			++index;
		}
	}
}

int DoubleLinkedList::size() const
{
	return _size;
}

int DoubleLinkedList::front() const
{
	return _head->data;
}

int DoubleLinkedList::back() const
{
	return _tail->data;
}

bool DoubleLinkedList::setHead(Node* node)
{
	if (_head == nullptr)
	{
		_head = node;
		_tail = node;

		++_size;

		return true;
	}

	return false;
}

void DoubleLinkedList::search() const
{
	if (0 == _size)
	{
		printf("empty\n");

		return;
	}
	Node* current = _head;
	while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\n");
}

void DoubleLinkedList::search_reverse() const
{
	Node* current = _tail;
	while (current)
	{
		printf("%d ", current->data);
		current = current->prev;
	}

	printf("\n");
}

DoubleLinkedList::~DoubleLinkedList()
{
	printf("deleted data: ");
	Node* current = _head;
	while (current)
	{
		printf("%d ", current->data);

		Node* next = current->next;
		delete current;

		current = next;
	}
}