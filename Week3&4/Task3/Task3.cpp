#include <iostream>
#include <fstream>

using namespace std;

const int n1 = 11, n2 = 13, n3 = 9, width = 15;
typedef double type1;

int main(){
	ifstream infile1("file1.hex", ios::in | ios::binary),
		infile2("file2.hex", ios::in | ios::binary),
		infile3("file3.hex", ios::in | ios::binary);

	cout.setf(ios::showbase);

	cout << "file1:" << endl;
	char res1[n1];
	for (int i = 0; i < n1; ++i) {
		infile1 >> res1[i];
	}

	for (int i = 0; i < n1; ++i) {
		cout.width(width);
		cout << res1[i];
	}

	cout << endl << hex;

	for (int i = 0; i < n1; ++i) {
		cout.width(width);
		cout << (int)res1[i];
	}

	cout << endl << "file2:" << endl << dec;


	char res2[n2];

	for (int i = 0; i < n2; ++i) {
		infile2.get(res2[i]);
	}

	for (int i = 0; i < n2; ++i) {
		cout.width(width);
		cout << (int)res2[i];
	}

	cout << endl << hex;

	for (int i = 0; i < n2; ++i) {
		cout.width(width);
		cout << (int)res2[i];
	}

	cout << endl << "file3:" << endl << dec;

	type1* a = (type1*)malloc(sizeof(type1) * n3);
	infile3.read((char*)a, n3*sizeof(type1));
	for (int i = 0; i < n3; ++i){
		type1* p = a + i;
		type1 res = p ? *p : 0;
		cout.precision(10);
		cout.width(22);
		cout << res;
	}
	cout << endl << hexfloat;
	for (int i = 0; i < n3; ++i) {
		type1* p = a + i;
		type1 res = p ? *p : 0;
		cout.precision(10);
		cout.width(22);
		cout << res;
	}
	infile1.close();
	infile2.close();
	infile3.close();
}