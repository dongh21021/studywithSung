#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool wellMatched(const string& formula);
int main(void) {
	int num;
	string formula;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> formula;
		if (wellMatched(formula))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

bool wellMatched(const string& formula) {
	const string opening("([{"), closing(")]}");   //opening()????
	stack<char> openStack;

	for (int i = 0; i < formula.size(); i++) {
		if (opening.find(formula[i]) != -1)   //여는 괄호라면
			openStack.push(formula[i]);
		else {  //여는 괄호가 아니라면
			if (openStack.empty()) return false;
			if (opening.find(openStack.top()) != closing.find(formula[i])) //짝이 안 맞으면
				return false;
			openStack.pop();
		}
	}
	return openStack.empty();
}