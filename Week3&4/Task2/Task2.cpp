#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int n1 = 11, n2 = 13, n3 = 9;
const char ar1[n1] = { 0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F };
const int ar2[n2] = { 23, 36, 10, 00, 127, 256, 873, 365, 1024, 3425, 5096, 231, 943 };
const double ar3[n3] = { 34.25, 9e15, 3e-09, 935.23, -634.23, 345.92, -254.76, 8.9e5, 436.34e10 };

int main(){
	ofstream outfile1("file1.hex", ios::binary | ios::out),
		outfile2("file2.hex", ios::binary | ios::out),
		outfile3("file3.hex", ios::binary | ios::out);
	
	for (int i = 0; i < n1; ++i) {
		outfile1 << ar1[i];
	}
	
	for (int i = 0; i < n2; ++i) {
		outfile2.put(ar2[i]);
		//int num = ar2[i];
		//do{
		//	outfile2.put(num % (1 << 8));
		//	num /= (1 << 8);
		//}while(num)
	}
	
	outfile3.write((char*)&ar3, sizeof(ar3));
	outfile1.close();
	outfile2.close();
	outfile3.close();
}