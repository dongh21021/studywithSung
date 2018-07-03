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
		if (opening.find(formula[i]) != -1)   //���� ��ȣ���
			openStack.push(formula[i]);
		else {  //���� ��ȣ�� �ƴ϶��
			if (openStack.empty()) return false;
			if (opening.find(openStack.top()) != closing.find(formula[i])) //¦�� �� ������
				return false;
			openStack.pop();
		}
	}
	return openStack.empty();
}