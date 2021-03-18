#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	if (argc != 3) {
		cout << "expected 3 arguments, got " << argc << endl;
		exit(-1);
	}
	if (strlen(argv[1]) != 8 && strlen(argv[2]) != 8) {
		cout << "length of bits not exactly 8" << endl;
		exit(-2);
	}
	bool kt = false;
	for (int i = 1; i < argc; ++i) {
		for (int j = 0; j < strlen(argv[i]); ++j) {
			if (argv[i][j] != '0' && argv[i][j] != '1') {
				kt = true;
				break;
			}
		}
		if (kt) break;
	}
	if (kt) {
		cout << "invalid format";
		exit(-3);
	}

	cout << "0x" << argv[1] << endl << "0x" << argv[2] << endl << "sum : " << strtol(argv[1], NULL, 2) + strtol(argv[2], NULL, 2);
}