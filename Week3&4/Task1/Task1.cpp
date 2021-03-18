#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int NUMS = 10;

int main(){
	FILE *s;
	freopen_s(&s, "error.txt", "w", stderr);
	queue <string> q;
	for (int i = 1; i <= NUMS; ++i) {
		string s;
		cout << "enter number " << i << ": ";
		cin >> s;
		long a = strtol(s.c_str(), NULL, 10);
		string ss = to_string(a);
		if (ss == s) q.push(ss);
		else cerr << s << endl;
	}
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
