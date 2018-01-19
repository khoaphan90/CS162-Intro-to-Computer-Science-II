#include <iostream>
#include "validation.hpp"
#include "numberList.hpp"

using namespace std;

int main()
{
	cout << "*Extra credit Task 1 was done for this lab*"
		<< endl << endl;

	NumberList list;

	bool valid = true;

	while (valid == true)
	{
		int input;
		cout << "Welcome to my linked list!"
			<< endl << endl;
		cout << "Please choose an option." << endl;
		cout << "1. Add a new node to the head;" << endl;
		cout << "2. Add a new node to the tail;" << endl;
		cout << "3. Delete from head;" << endl;
		cout << "4. Delete from tail;" << endl;
		cout << "5. Traverse the list reversely;" << endl;
		cout << "6. Display head value;" << endl;
		cout << "7. Display tail value;" << endl;
		cout << "8. Exit;" << endl;
		cout << "\nEnter option: ";
		input = checkInt();
		cout << endl;

		switch (input)
		{
		case 1:
			list.addHead();
			break;
		case 2:
			list.addTail();
			break;
		case 3:
			list.removeHead();
			break;
		case 4:
			list.removeTail();
			break;
		case 5:
			list.reverseList();
			break;
		case 6:
			list.dispHead();
			break;
		case 7:
			list.dispTail();
			break;
		case 8:
			valid = false;
			break;
		default:
			cout << "Please choose a valid option." << endl;
			break;
		}
	}

	return 0;
}

//void addNodeHead(List *head)
//{
//	//int input;
//	//cout << "Please enter a positive integer." << endl;
//	//input = checkInt();
//
//	//List *nList = nullptr;
//	//head = new List(input, nList);
//	//head->value = input;
//	//head->next = nullptr;
//
//	//cout << "\nYour linked list is: " << head->value << endl << endl;
//}
//
//void addNodeTail()
//{
//	//int input;
//	//cout << "Please enter a positive integer." << endl;
//	//input = checkInt();
//	// set as node tail
//}
//
//void deleteHead()
//{
//	// remove node head
//}
//
//void deleteTail()
//{
//	//remove node tail
//}
//
//void traverseList()
//{
//	// reverse list cout
//}