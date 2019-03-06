#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
}


LinkedList::~LinkedList()
{
}

void LinkedList::insertStart(int value)
{
	Node * Temp = new Node;
	Temp->data = value;
	Temp->next = NULL;
	if (Head == NULL)
	{
		Head = Temp;
		Tail = Temp;
	}
	else
	{
		Temp->next = Head;
		Head = Temp;
	}
}

void LinkedList::insertEnd(int value)
{
	Node * Temp = new Node;
	Temp->data = value;
	Temp->next = NULL;
	if (Head == NULL)
	{
		Head = Temp;
		Tail = Temp;
	}
	Tail->next = Temp;
	Tail = Temp;
}

void LinkedList::insertPos(int value, int pos)
{
	Node * Current = new Node;
	Node * Previous = new Node;
	Node * Temp = new Node;
	Current = Head;
	if (Head != NULL && search() >= pos)
	{
		for (int i = 1; i < pos; i++)
		{
			Previous = Current;
			Current = Current->next;
		}
		Temp->data = value;
		Previous->next = Temp;
		Temp->next = Current;
	}
	else
	{
		cout << "Head is NULL! or position: " << pos << " does not exist!" << endl;
	}
}

void LinkedList::deleteStart()
{
	Node * Temp = new Node;
	Temp = Head;
	Head = Head->next;
	delete Temp;
}

void LinkedList::deleteEnd()
{
	Node * Current = new Node;
	Node * Previous = new Node;
	Current = Head;
	while (Current->next != NULL)
	{
		Previous = Current;
		Current = Current->next;
	}
	Tail = Previous;
	Tail->next = NULL;
	delete Current;
}

void LinkedList::deletePos(int pos)
{
	Node * Current = new Node;
	Node * Previous = new Node;
	Current = Head;
	if (Head != NULL && search() >= pos)
	{
		for (int i = 1; i < pos; i++)
		{
			Previous = Current;
			Current = Current->next;
		}
		Previous->next = Current->next;
	}
	else
	{
		cout << "Head is NULL! or position: " << pos << " does not exist!" << endl;
	}
}

void LinkedList::display()
{
	Node * Temp = new Node;
	Temp = Head;
	while (Temp != NULL)
	{
		cout << Temp->data << endl;
		Temp=Temp->next;
	}
}

int LinkedList::search()
{
	Node * Temp = new Node;
	Temp = Head;
	int counter = 0;
	while (Temp != NULL)
	{
		counter++;
		Temp = Temp->next;
	}
	return counter;
}

bool LinkedList::multipleOfK(Node * head, int k)
{
	for (int i = 1;i <= k;i++)
	{
		if (head != NULL)
		{
			head = head->next;
		}
		else
			return false;
	}
	return true;
}

void LinkedList::reverse(int k)
{
	Node * head = Head;
	swap(head, k);
}

Node * LinkedList::swap(Node * head, int k)
{
	Node* Current;
	Node* Previous = NULL;
	Node* Temp = NULL;
	Current = head;
	int Counter = 0;
	if (multipleOfK(head, k) == true)
	{
		while (Current != NULL && Counter < k)
		{
			Temp = Current->next;
			Current->next = Previous;
			Previous = Current;
			Current = Temp;
			Counter++;
		}
		if (Temp != NULL)
			head->next = swap(Temp, k);
	}
	else
		return head;
	Head = Previous;
	return head = Previous;
}