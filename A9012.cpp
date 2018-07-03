#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool isVps(const string& formula);
int main(void) {
	int n;
	string formula;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> formula;
		if (isVps(formula))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

bool isVps(const string& formula) {
	stack<char> openStack;

	for (int i = 0; i < formula.size(); i++) {
		if (formula[i] == '(')
			openStack.push(formula[i]);
		else if (formula[i] == ')') {
			if (openStack.empty()) return false;
			openStack.pop();
		}
	}
	return openStack.empty();
}