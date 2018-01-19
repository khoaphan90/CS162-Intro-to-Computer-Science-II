/*********************************************************************
** Program name: people.hpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Header file for the People class.
*********************************************************************/

#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <string>

using namespace std;

enum Person { STUDENT, INSTRUCTOR };

class People
{
private:
public:
	People();
	virtual ~People() {};
	void setName();
	void setAge();
	string getName() const;
	int getAge() const;
	virtual void do_work(int) = 0;
	virtual double getAttribute() = 0;
	virtual void printInfo(int) = 0;
	virtual Person returnType() = 0;
protected:
	string name;
	int age;
};

#endif // !PEOPLE_HPP