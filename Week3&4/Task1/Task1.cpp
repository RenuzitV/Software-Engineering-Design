#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int NUMS = 1;

int main(){
	FILE *s;
	freopen_s(&s, "error.txt", "w", stderr);
	queue <string> q;
	for (int i = 1; i <= NUMS; ++i) {
		string s;
		cout << "enter number " << i << ": ";
		cin >> s;
		int first = 0, sec = 0;
		sscanf_s(s.c_str(), "%*[+-]%d%*[.]%d", &first, &sec);
		double a = strtof(s.c_str(), NULL);
		string ss = to_string(first).c_str() + sec==0?"":to_string(sec);
		if (a == first+sec/pow(10, (int)log10(sec))) q.push(ss);
		else cerr << s << ' ' << ss << endl;
	}
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
