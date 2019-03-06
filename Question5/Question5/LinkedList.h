#pragma once
#include"Node.h"
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insertStart(int value);
	void insertEnd(int value);
	void insertPos(int value, int pos);
	void deleteStart();
	void deleteEnd();
	void deletePos(int pos);
	void display();
	int search();
	void reverse(int k);
	Node * swap(Node * head, int k);
	bool multipleOfK(Node * head, int k);

private:
	Node * Head;
	Node * Tail;
};

