#include "Company.h"
#include <string>

using namespace std;

int main(){
	Company company;
	int token = 0;
	do {
		cout << "Enter 1 for new Employee, 2 for search employee, 3 to show all Employees, 4 to delete an Employee, -1 to exit: ";
		string temp;
		cin >> temp;
		token = strtol(temp.c_str(), NULL, 10);
		switch (token) {
		case -1:{
			exit(0);
			break;
		}
		case 1: {
			company.makeNewEmployee();
			break;
		}
		case 2: {
			company.findShowEmployee();
			break;
		}
		case 3: {
			company.showEmployees();
			break;
		}
		case 4: {
			company.deleteEmployee();
			break;
		}
		default: {
			cout << "wrong input" << endl;
			break;
		}
		}
	} while (token != -1);
}