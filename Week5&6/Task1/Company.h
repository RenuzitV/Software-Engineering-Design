#pragma once
#include "Employee.h"
#include <vector>

class Company{
	//private vector to store all people of company as an employee
	std::vector<Employee> people;

	//see employee.h for some explainations
	int enterNum(const char* name) {
		std::string snum;
		std::cout << "Enter " << name << ":";
		std::cin >> snum;
		return strtol(snum.c_str(), NULL, 10);
	}

	void trim(std::string* s) {
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

public :
	//default constructor and destructor
	Company();
	~Company();
	//overloaded functions to find a specific employee
	Employee* findEmployee(std::string first, std::string last);
	Employee* findEmployee(std::string first);
	Employee* findEmployee(int ID);
	Employee* findEmployee();

	//see company.cpp for explainations
	void findShowEmployee();
	void makeNewEmployee();
	void showEmployees();	
	void deleteEmployee();
	void deleteEmployee(Employee* E);
};

