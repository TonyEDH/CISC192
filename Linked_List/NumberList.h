#ifndef NUMBERLIST_H
#define NUMBERLIST_H


class NumberList
{
private:
	struct ListNode
	{
		int value;
		struct ListNode *next;
	};

	ListNode *head;
public:
	NumberList() { head = nullptr; }
	~NumberList();

	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void printList() const;
};


#endif