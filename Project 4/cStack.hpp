/*********************************************************************
** Program name: cStack.hpp for Lab6
** Author: Khoa Phan
** Date: May 14, 2017
** Description: Header file for the cStack.cpp.
*********************************************************************/
#ifndef CSTACK_HPP
#define CSTACK_HPP

#include "creature.hpp"

using namespace std;

class cStack
{
private:
public:
	cStack() { top = nullptr; }
	~cStack();
	void addTop(string);
	void displayList() const;
protected:
	struct ListNode
	{
		string c;
		ListNode *next;
		ListNode(string c1, ListNode *next1 = nullptr)
		{
			c = c1;
			next = next1;
		}
	};
	ListNode *top;
};

#endif // !CSTACK_HPP