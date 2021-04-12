#pragma once
#include <iostream>
#include <string>

//string of months
const std::string MONTHS[12] = { "January", "February", "March", "Arpil", "May", "June", "July", "August", "September", "October", "November", "December" };

//declaring employee class and private functions and variables
class Employee{
private:

	//class for date of birth
	class dob {
	public:
		int date, month, year;
		dob() {
			date = month = year = 0;
		}
	};
	
	//private variables
	std::string first, last;
	int id;
	dob birth;

	//private function to enter a number from a string
	int enterNum(const char* name) {
		std::string snum;
		std::cout << "Enter " << name << ":";
		std::cin >> snum;
		return strtol(snum.c_str(), NULL, 10);
	}

	//private function to enter month via name or number
	bool enterMonth() {
		std::cout << "Enter month :";
		std::string month;
		std::cin >> month;
		trim(&month);
		birth.month = strtol(month.c_str(), NULL, 10);
		if (1 <= birth.month && birth.month <= 12) return true;
		for (int i = 0; i < 12; ++i) {
			if (month == MONTHS[i]) {
				return birth.month = i + 1; 
			}
		}
		birth.month = strtol(month.c_str(), NULL, 10);
		return 1 <= birth.month && birth.month <= 12;
	}

	//private function to trim a string
	void trim(std::string *s) {
		while (s->size() > 0 && isspace(s->front())) {
			s->erase(0);
		}
		while (s->size() > 0 && isspace(s->back())) {
			s->erase(s->back());
		}
		for (char& c : *s) {
			c = tolower(c);
		}
		(*s)[0] = toupper((*s)[0]);
	}

public:
	//constructor and parameterized equivelant
	Employee();
	Employee(std::string first, std::string last, int id, dob birth);
	//destructor
	~Employee();
	//see employee.cpp for more infomation
	bool enter();
	void show();
	std::string firstName();
	std::string lastName();
	int showID();
};

