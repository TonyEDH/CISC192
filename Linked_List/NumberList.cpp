#include "NumberList.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	NumberList list;

	list.appendNode(1);
	list.appendNode(3);
	list.appendNode(5);
	list.appendNode(7);
	list.appendNode(9);

	list.printList();

	list.insertNode(0);
	list.insertNode(2);
	list.insertNode(4);
	list.insertNode(6);
	list.insertNode(8);
	list.insertNode(10);
	list.insertNode(-1);
	list.insertNode(11);

	list.printList();

	list.deleteNode(-1);
	list.deleteNode(5);
	list.deleteNode(11);

	list.printList();

	char c;
	cout << "\nPress any key then <ENTER>:" << endl;
	cin >> c;

	return 0;
}

void NumberList::appendNode(int value)
{
	ListNode *newNode;
	ListNode *nodePtr;

	newNode = new ListNode;
	newNode->value = value;
	newNode->next = nullptr;

	if (!head)
	{
		head = newNode;
	}
	else
	{
		nodePtr = head;

		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

void NumberList::insertNode(int value)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = value;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while ((nodePtr != nullptr) && (nodePtr->value < value))
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void NumberList::deleteNode(int value)
{
	ListNode *nodePtr;
	ListNode *previousNode;

	if (!head)
	{
		return;
	}

	if (head->value == value)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while ((nodePtr != nullptr) && (nodePtr->value != value))
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void NumberList::printList() const
{
	ListNode *nodePtr;

	nodePtr = head;
	cout << "\nPrinting..." << endl;

	while (nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}

NumberList::~NumberList()
{
	ListNode *nodePtr;
	ListNode *nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}