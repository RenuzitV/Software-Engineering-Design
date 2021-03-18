#include <iostream>

using namespace std;

const int MAXNUM = 200;

enum class colors { red, green, blue };

class MyString {
	char* s;
	int n;
public:
	MyString() {
		s = (char*)malloc(sizeof(char));
		if (s) s[0] = '\0';
		n = 0;
	}
	MyString(string ss) {
		*this = ss;
		n = ss.size();
	}
	MyString operator=(string ss) {
		if (sizeof(s) < ss.size()) {
			char* temp = s;
			s = (char*)realloc(s, sizeof(char) * (ss.size() + 5));
			if (!s) temp = s;
			else free(temp);
		}
		for (int i = 0; i < ss.size(); ++i)
			s[i] = ss[i];
		s[ss.size()] = '\0';
		n = ss.size();
		return *this;
	}
	MyString operator+(MyString ss) {
		return *this + ss.s;
	}
	MyString operator+(char c) {
		s[n] = c;
		s[++n] = '\0';
		return *this;
	}
	MyString operator+=(char c) {
		return *this + c;
	}
	MyString operator+(string ss) {
		for (char c : ss) {
			*this += c;
		}
		return *this;
	}
	MyString operator+=(string ss) {
		return *this + ss;
	}
	int size() {
		return n;
	}
	void show() {
		for (int i = 0; i < n; ++i)
			cout << s[i];
		cout << endl;
	}
};

int main() {
	MyString s;
	for (int i = 0; i < 1e8; ++i) {
		s += '0';
	}
	return 0;
}