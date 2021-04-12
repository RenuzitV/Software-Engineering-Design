#include "Company.h"
#include <string>
#include <vector>

Company::Company() {

}

Company::~Company(){

}

//finds and show a specific employee
void Company::findShowEmployee() {
	//check findEmployee()
	Employee* E = Company::findEmployee();
	if (E) {
		E->show();
	}
	else {
		std::cout << "No such Employee" << std::endl;
	}
}

//main function to find a specific employee
Employee* Company::findEmployee() {
	std::string name;
	Employee* E;
	//input for employee name or id
	std::cout << "enter name or id:";
	//because of getline, we have to ignore any endlines from the buffer
	std::cin.ignore();
	getline(std::cin, name);
	trim(&name); //trim to clean string
	int id = strtol(name.c_str(), NULL, 10); //checks if user puts in id instead of name
	
	//if its an id find employee based on the id
	if (id) {
		E = findEmployee(id);
	}

	else {
		//checks if its just the first name or also the last name
		int sep = name.find_first_of(' ');
		//if we cant find any whitespace, find with the only first name
		if (sep == std::string::npos) E = findEmployee(name);
		else {
			//seperate the first and last name, and find it
			std::string first, last;
			//resize the strings
			first.resize(sep);
			last.resize(name.size() - sep - 1);
			 
			//copies the first and last into their respective strings and trim them
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

//runs through the entire company, find and returns the first employee with matching name
Employee* Company::findEmployee(std::string first, std::string last) {
	for (std::vector<Employee>::iterator E = this->people.begin(); E != this->people.end(); ++E) {
		if (E->firstName() == first && E->lastName() == last) {
			return &*E;
		}
	}
	//returns null pointer
	return NULL;
}

//runs through the entire company, find and returns the first employee with matching name
Employee* Company::findEmployee(std::string first) {
	for (std::vector<Employee>::iterator E = this->people.begin(); E != this->people.end(); ++E) {
		if (E->firstName() == first) {
			return &*E;
		}
	}
	//returns null pointer
	return NULL;
}

//finds first employee with matching ID
Employee* Company::findEmployee(int ID) {
	for (std::vector<Employee>::iterator E = this->people.begin(); E != this->people.end(); ++E) {
		if (E->showID() == ID) {
			return &*E;
		}
	}
	return NULL;
}

//pushes a new employee into people and let the user enter information
void Company::makeNewEmployee() {
	people.push_back(*new Employee());
	if (!people.back().enter()) deleteEmployee(&people.back());
}

//shows all employeess in the company
void Company::showEmployees() {
	if (people.size() > 1) std::cout << "There are" << people.size() << " people in this company\n";
	else std::cout << "There is" << 1 << " person in this company\n";
	for (Employee E : people) {
		E.show();
	}
}

//finds and delete an employee
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

//parameterized deleteEmployee
void Company::deleteEmployee(Employee* E) {
	if (E) {
		std::cout << "Employee " << E->firstName() << ' ' << E->lastName() << " deleted" << std::endl;
		people.erase(next(people.begin(), E - &*people.begin()));
	}
	else {
		std::cout << "No such Employee" << std::endl;
	}
}
