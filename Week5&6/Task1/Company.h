#pragma once
#include "Employee.h"
#include <vector>

class Company{
	std::vector<Employee> people;

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
	Company();
	~Company();
	Employee* findEmployee(std::string first, std::string last);
	Employee* findEmployee(std::string first);
	Employee* findEmployee(int ID);
	Employee* findEmployee();
	void findShowEmployee();
	void makeNewEmployee();
	void showEmployees();	
	void deleteEmployee();
};

