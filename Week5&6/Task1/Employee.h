#pragma once
#include <iostream>
#include <string>

const std::string MONTHS[12] = { "january", "february", "march", "arpil", "may", "june", "july", "august", "september", "october", "november", "december" };

class Employee{
private:

	class dob {
	public:
		int date, month, year;
		dob() {
			date = month = year = 0;
		}
	};
	std::string first, last;
	int id;
	dob birth;

	int enterNum(const char* name) {
		std::string snum;
		std::cout << "Enter " << name << ":";
		std::cin >> snum;
		return strtol(snum.c_str(), NULL, 10);
	}

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
	Employee(std::string first, std::string last, int id, dob birth);
	~Employee();
	bool enter();
	void show();
	std::string firstName();
	std::string lastName();
	int showID();
};

