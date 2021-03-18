#include "Company.h"
#include <string>
#include <vector>

Company::Company() {

}

Company::~Company(){

}

void Company::findShowEmployee() {
	Employee* E = Company::findEmployee();
	if (E) {
		E->show();
	}
	else {
		std::cout << "No such Employee" << std::endl;
	}
}

Employee* Company::findEmployee() {
	std::string name;
	Employee* E;
	std::cout << "enter name or id:";
	std::cin.ignore();
	getline(std::cin, name);
	trim(&name);
	int id = strtol(name.c_str(), NULL, 10);
	if (id) {
		E = findEmployee(id);
	}
	else {
		int sep = name.find_first_of(' ');
		if (sep == std::string::npos) E = findEmployee(name);
		else {
			std::string first, last;
			first.resize(sep);
			last.resize(name.size() - sep - 1);
			copy(name.begin(), name.begin() + sep, first.begin());
			copy(name.begin() + sep + 1, name.end(), last.begin());
			trim(&first);
			trim(&last);
			E = findEmployee(first, last);
		}
	}
	if (E) return E;
	else return NULL;
}

Employee* Company::findEmployee(std::string first, std::string last) {
	for (std::vector<Employee>::iterator E = this->people.begin(); E != this->people.end(); ++E) {
		if (E->firstName() == first && E->lastName() == last) {
			return &*E;
		}
	}
	return NULL;
}

Employee* Company::findEmployee(std::string first) {
	for (std::vector<Employee>::iterator E = this->people.begin(); E != this->people.end(); ++E) {
		if (E->firstName() == first) {
			return &*E;
		}
	}
	return NULL;
}

Employee* Company::findEmployee(int ID) {
	for (std::vector<Employee>::iterator E = this->people.begin(); E != this->people.end(); ++E) {
		if (E->showID() == ID) {
			return &*E;
		}
	}
	return NULL;
}

void Company::makeNewEmployee() {
	people.push_back(*new Employee());
	people.back().enter();
}


void Company::showEmployees() {
	for (Employee E : people) {
		E.show();
	}
}

void Company::deleteEmployee() {
	Employee* E = Company::findEmployee();
	if (E) {
		std::cout << "Employee " << E->firstName() << ' ' << E->lastName() << " deleted" << std::endl;
		people.erase(next(people.begin(), E - &*people.begin()));
	}
	else {
		std::cout << "No such Employee" << std::endl;
	}
}