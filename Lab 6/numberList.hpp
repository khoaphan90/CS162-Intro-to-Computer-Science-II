/*********************************************************************
** Program name: numberList.hpp for Lab6
** Author: Khoa Phan
** Date: May 14, 2017
** Description: Header file for the numberList.cpp.
*********************************************************************/

#include <iostream>

using namespace std;

class NumberList
{
private:
public:
	NumberList() { head = nullptr; }
	~NumberList();
	void addHead();
	void addTail();
	void removeHead();
	void removeTail();
	void displayList() const;
	void reverseList();
	void dispHead();
	void dispTail();
protected:
	struct ListNode
	{
		int value;
		ListNode *next;
		ListNode(int value1, ListNode *next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};
	ListNode *head;
	ListNode *tail;
};