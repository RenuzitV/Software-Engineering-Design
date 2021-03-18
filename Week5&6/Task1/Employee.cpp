#include "Employee.h"
#include <iostream>

//default constructor
Employee::Employee() {
	first = last = "";
	id = -1;
	birth = *new dob();
}

//parameterized constructor
Employee::Employee(std::string first, std::string last, int id, dob birth) {
	this->first = first;
	this->last = last;
	this->id = id;
	this->birth = birth;
}

//detructor
Employee::~Employee() {
	//std::cout << "Employee " << first << ' ' << last << " deleted" << std::endl;
}

//enter information for a this employee
bool Employee::enter() {
	std::cout << "Enter first name : ";
	std::cin >> this->first;
	std::cout << "Enter last name : ";
	std::cin >> this->last;
	trim(&first);
	trim(&last);
	this->id = enterNum("ID");
	if (this->id == 0) {
		std::cout << "invalid ID" << std::endl;
		return false;
	}

	this->birth.date = enterNum("date");
	if (1 >= this->birth.date && this->birth.date >= 31) {
		std::cout << "invalid number" << std::endl;
		return false;
	}

	if (!enterMonth()) {
		std::cout << "invalid month" << std::endl;
		return false;
	}

	this->birth.year = enterNum("year");
	std::cout << std::endl;
	return true;
}

//show employee's information
void Employee::show() {
	std::cout << first << ' ' << last << "'s informations :" << std::endl;
	std::cout << "Date of birth : " << birth.date << '\\' << birth.month << '\\' << birth.year << std::endl;
	std::cout << "Identification number : " << id << std::endl << std::endl;
}

//for use with other functions
std::string Employee::firstName() {
	return first;
}

std::string Employee::lastName() {
	return last;
}

int Employee::showID() {
	return id;
}