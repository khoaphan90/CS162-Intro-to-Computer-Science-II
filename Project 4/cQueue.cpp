/*********************************************************************
** Program name: queue.cpp for Lab6
** Author: Khoa Phan
** Date: May 14, 2017
** Description: This file contains the functions that manipulate and 
** manage the queue for the Queue class.
*********************************************************************/

#include <iostream>
#include "cQueue.hpp"
#include "cStack.hpp"
#include "validation.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** cQueue::cQueue
** Default constructor that sets the front and back nodes to nullptr
*********************************************************************/

cQueue::cQueue()
{
	front = nullptr;
	back = nullptr;
}

/*********************************************************************
** cQueue::~cQueue
** Destructor function that deallocates the entire list.
*********************************************************************/
cQueue::~cQueue()
{
	QueueNode *garbage = front;
	while (front != nullptr)
	{
		// deallocate memory created by creature
		delete garbage->c;
		// takes all nodes and deletes that node
		front = front->next;
		garbage->next = nullptr;
		delete garbage;
	}
}

/*********************************************************************
** cQueue::addBack
** Function that adds integer to the back of the queue.
*********************************************************************/
void cQueue::addBack(Creature* c)
{
	QueueNode *temp = new QueueNode(c);
	if (isEmpty())
	{
		front = temp;
		back = front;
	}
	else
	{
		back->next = new QueueNode(c);
		back = back->next;
	}
	delete temp;
}

/*********************************************************************
** cQueue::getFront
** Function that returns value of integer at the front of the queue.
*********************************************************************/
Creature* cQueue::getFront()
{
	return front->c;
}

/*********************************************************************
** cQueue::removeFront
** Function that removes the front value from the queue and moves
** the node to the new front.
*********************************************************************/
void cQueue::removeFront()
{
	QueueNode *temp = nullptr;
	if (isEmpty())
		return;
	else
	{
		temp = front;
		cout << temp->c->getName() << " has been "
			<< "defeated and sent to the pile!" << endl;
		front = front->next;
		delete temp->c;
		delete temp;
	}
}

/*********************************************************************
** cQueue::moveFrontToBack
** Function that removes the front value from the queue and moves
** the node to the new front.
*********************************************************************/
void cQueue::moveFrontToBack()
{
	if (front->next != nullptr)
	{
		front->c->restore();
		addBack(front->c);
		front = front->next;
	}
	else
	{
		front = front;
		front->prev = nullptr;
		front->next = nullptr;
	}
}


/*********************************************************************
** cQueue::isEmpty
** Function that checks if queue is empty
*********************************************************************/
bool cQueue::isEmpty()
{
	// check to see if front value exist
	if (front == nullptr)
		return true;
	else
		return false;
}

string cQueue::getName()
{
	return front->c->getName();
}

void cQueue::clear()
{
	while (!isEmpty())
		removeFront();
}