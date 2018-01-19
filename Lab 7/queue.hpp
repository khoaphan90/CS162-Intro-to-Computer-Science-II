/*********************************************************************
** Program name : queue.hpp for Lab 7
** Author : Khoa Phan
** Date : May 16, 2017
** Description : Header file for queue.cpp
********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
public:
	Queue();
	~Queue();
	void addBack(int);
	void getFront() const;
	void removeFront();
	void displayContents() const;
	bool isEmpty() const;
protected:
	struct QueueNode
	{
		int value;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(int value1, QueueNode *next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};
	QueueNode *front;
	QueueNode *back;
};


#endif // 
