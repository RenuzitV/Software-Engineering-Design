#include "Company.h"
#include <string>

using namespace std;

int main(){
	//create a company
	Company company;
	//get a token
	int token = 0;
	do {
		cout << "Enter 1 for new Employee, 2 for search employee, 3 to show all Employees, 4 to delete an Employee, -1 to exit: ";
		string temp;
		cin >> temp;
		//error checking on token
		token = strtol(temp.c_str(), NULL, 10);
		switch (token) {
			case -1:{//exit code
				exit(0);
				break;
			}
			case 1: {//make a new employee
				company.makeNewEmployee();
				break;
			}
			case 2: {//find and show an employee
				company.findShowEmployee();
				break;
			}
			case 3: {//show all employees
				company.showEmployees();
				break;
			}
			case 4: {//find and delete a single employee
				company.deleteEmployee();
				break;
			}
			default: {//error check
				cout << "wrong input" << endl;
				break;
			}
		}
	} while (token != -1);
}