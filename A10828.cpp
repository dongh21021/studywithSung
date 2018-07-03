#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> s;
int doInst(const string& ins);
int main(void) {
	int n;
	string ins;
	int ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ins;
		ans = doInst(ins);

		if (ans != -2)
			cout << ans << endl;
	}
}

int doInst(const string& ins) {
	int pushNum;
	int topNum;
	if (ins.substr(0, 4) == "push") {
		cin >> pushNum;
		s.push(pushNum);
		return -2;
	}
	else if (ins == "pop") {
		if (s.empty()) return -1;
		else {
			topNum = s.top();
			s.pop();
			return topNum;
		}
	}
	else if (ins == "size") {
		return s.size();
	}
	else if (ins == "empty") {
		return s.empty();
	}
	else if (ins == "top") {
		if (s.empty()) return -1;
		else return s.top();
	}
}