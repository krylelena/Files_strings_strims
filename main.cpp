#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	string str;
	int flag = 1, i;
	try {
		ifstream fin("File.txt", ios::in);
		if (!fin)
			throw exception("���� �� ��������.");
		while (!fin.eof()) {
			getline(fin, str, '.');
			for (i = 0; str[i] == '\n' || str[i] == ' '; i++);
			if (str[i] == '-') {
				cout << str << "." << endl;
				flag = 0;
			}
		}
		if (flag)
			cout << "�����������, ������������� � ���� ���." << endl;
		fin.close();
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}