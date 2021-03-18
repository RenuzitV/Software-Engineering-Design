#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
	if (argc < 2 || argc > 11) {
		cout << "invalid number of arguments" << endl;
		exit(-1);
	}
	float* a = (float*)malloc(sizeof(float) * 10);
	for (int i = 1; i < argc; ++i) {
		if (sscanf_s(argv[i], "%f", a + (i - 1)) == 0){
			cout << "invalid float";
		}
	}
	for (int i = 1; i < argc; ++i) {
		float* p = a + i - 1;
		float res = p?*p:0;
		printf_s("%.5f\n", (a+i-1)?*(a+i-1):0);
	}
}