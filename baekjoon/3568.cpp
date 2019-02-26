#include<iostream>
#include<string>
using namespace std;

int main() {
	freopen("./input/3568.txt", "r", stdin);

	while (!cin.eof()) {
		string initType;
		cin >> initType;
		if(cin.eof()) break;

		char delimiter;
		string var;
		do {
			cin >> var;
			delimiter = var.at(var.size() - 1);
			var.pop_back();

			cout << initType;

			char charAt;
			int varLength = var.size();
			for (int i = 0; i<varLength; i++) {
				charAt = var.at(var.size() - 1);
				bool isType = true;
				switch (charAt) {
				default:
					isType = false;
					cout << " " << var;
					break;
				case '&':
				case '*':
					cout << charAt;
					var.pop_back();
					break;
				case ']':
					cout << "[]";
					var.pop_back();
					var.pop_back();
					break;
				}

				if (!isType) break;
			}
			cout << ";" << endl;
			var.clear();
		} while (delimiter != ';');
		initType.clear();
	}
	return 0;
}