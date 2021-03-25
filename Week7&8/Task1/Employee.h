#pragma once
#include <iostream>
#include <string>

//string of months
const std::string MONTHS[12] = { "january", "february", "march", "arpil", "may", "june", "july", "august", "september", "october", "november", "december" };

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
	std::string first, last; //name
	int id; //ID
	dob birth; //BOD
	bool gender; //gender, 1 is male
	double rate; //hour rate of pay
	double stdh; //std work hour
	double ovth; //overtime work hour

	//private function to enter a number from a string
	double enterNum(const char* name) {
		std::string snum;
		std::cout << "Enter " << name << ":";
		std::cin >> snum;
		return strtof(snum.c_str(), NULL);
	}

	//private function to enter month via name or number
	//constructor and parameterized equivelant
	bool enterMonth() {
		std::cout << "Enter month :";
		std::string month;
		std::cin >> month;
		trim(&month);
		int test = strtol(month.c_str(), NULL, 10);
		if (test) return birth.month = test;
		for (char& c : month) c = tolower(c);
		for (int i = 0; i < 12; ++i) {
			if (month == MONTHS[i]) {
				return birth.month = i + 1; 
			}
		}
		return birth.month = strtol(month.c_str(), NULL, 10);
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
	Employee();
	Employee(std::string first, std::string last, int id, dob birth, int gender, int rate, int stdh, int ovth);
	//destructor
	~Employee();
	//see employee.cpp for more infomation
	bool enter();
	void show();
	std::string firstName();
	std::string lastName();
	int showID();
	double payslip();
};

