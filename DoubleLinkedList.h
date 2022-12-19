#pragma once

class DoubleLinkedList
{
private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;

		Node(int _data)
			:data(_data)
		{
			prev = nullptr;
			next = nullptr;
		}
	};

public:
	void push_front(int data);
	void push_back(int data);
	void pop_front();
	void pop_back();
	void erase(int pos);
	int size() const;
	int front() const;
	int back() const;
	
	void search() const;
	void search_reverse() const;

	bool setHead(Node* node);

	DoubleLinkedList() = default;
	~DoubleLinkedList();

private:
	int _size = 0;
	Node* _head = nullptr;
	Node* _tail = nullptr;
};