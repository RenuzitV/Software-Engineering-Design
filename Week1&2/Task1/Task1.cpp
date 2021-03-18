#include <iostream>

using namespace std;

const int MAXNUM = 3;

bool check(char c) {
	return (isdigit(c) || ('A' <= c && c <= 'F'));
}

int main(int argc, const char *argv[]){
	if (argc < 2 || argc > MAXNUM + 1) {
		cout << "invalid number of arguments, expected 2 to " << MAXNUM+1 << ", got " << argc;
		exit(-1);
	}
	for (int i = 1; i < argc; ++i) {
		if ((argv[i][0] != '0' && tolower(argv[i][1]) != 'x') || (strlen(argv[i]) != 4)) {
			cout << "invalid format" << endl;
		}
		else {
			if (check(argv[i][2]) && check(argv[i][3])){
				cout << argv[i] << endl;
			}
			else {
				cout << "invalid format" << endl;
			}
		}
	}
}