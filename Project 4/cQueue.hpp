/*********************************************************************
** Program name : queue.hpp for Lab 7
** Author : Khoa Phan
** Date : May 16, 2017
** Description : Header file for queue.cpp
********************************************************************/

#ifndef CQUEUE_HPP
#define CQUEUE_HPP

#include "creature.hpp"

class cQueue
{
public:
	cQueue();
	~cQueue();
	void addBack(Creature*);
	void clear();
	Creature* getFront();
	void removeFront();
	void moveFrontToBack();
	bool isEmpty();
	string getName();
protected:
	struct QueueNode
	{
		Creature* c;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(Creature* value1, QueueNode *next1 = nullptr)
		{
			c = value1;
			next = next1;
		}
	};
	QueueNode* front;
	QueueNode* back;
};


#endif // 
