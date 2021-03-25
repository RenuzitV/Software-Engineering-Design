#include "Employee.h"
#include <iostream>

//default constructor
Employee::Employee() {
	first = last = "";
	id = -1;
	birth = *new dob();
	gender = 1; //gender, 1 is male
	rate = 1; //hour rate of pay
	stdh = 0; //std work hour
	ovth = 0; //overtime work hour
}

//parameterized constructor
Employee::Employee(std::string first, std::string last, int id, dob birth, int gender, int rate, int stdh, int ovth) {
	this->first = first;
	this->last = last;
	this->id = id;
	this->birth = birth;
	this->gender = gender;
	this->rate = rate;
	this->stdh = stdh;
	this->ovth = ovth;
}

//detructor
Employee::~Employee() {
	//std::cout << "Employee " << first << ' ' << last << " deleted" << std::endl;
}

//enter information for a this employee
bool Employee::enter() {

	//enter name
	std::cout << "Enter first name : ";
	std::cin >> this->first;
	std::cout << "Enter last name : ";
	std::cin >> this->last;
	trim(&first);
	trim(&last);

	//enter ID
	this->id = enterNum("ID");
	if (this->id == 0) {
		std::cout << "invalid ID" << std::endl;
		return false;
	}

	//enter date
	this->birth.date = enterNum("date");
	if (1 >= this->birth.date && this->birth.date >= 31) {
		std::cout << "invalid number" << std::endl;
		return false;
	}

	//enter month
	if (!enterMonth()) {
		std::cout << "invalid month" << std::endl;
		return false;
	}

	//enter year
	this->birth.year = enterNum("year");
	std::cout << std::endl;
	return true;

	//enter gender
	this->birth.date = enterNum("date");
	if (1 >= this->birth.date && this->birth.date >= 31) {
		std::cout << "invalid number" << std::endl;
		return false;
	}

	//enter rate
	this->rate = enterNum("rate");

	//enter std hour 
	this->stdh = enterNum("standard working hour");

	//enter overtime hour
	this->ovth= enterNum("overtime working hour");

}

//show employee's information
void Employee::show() {
	std::cout << first << ' ' << last << "'s informations :" << std::endl;
	std::cout << "Date of birth : " << birth.date << '\\' << birth.month << '\\' << birth.year << std::endl;
	std::cout << "Identification number : " << id << std::endl << std::endl;
	
}

double Employee::payslip() {
	return stdh * rate + ovth * rate * 2;
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