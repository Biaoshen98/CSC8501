#pragma once
#include "Collatz.h"
#include <iostream>
#include <fstream>
using namespace std;
void CheckUserPassword() {
	string user;
	string password;
	string enpassword;
	enpassword = ctz.get(password);
	ifstream ifs;
	ifs.open("password.txt");
	if (!ifs.is_open()) {
		cout << "read fail.Press 1 to return menu" << endl;
		string input;
		cin >> input;
		if (input == "1") {
			return;
		}
	}
	string str;
	cout << "please input your username" << endl;
	cout << "username:" << user << endl;
	cin >> user;
	while (ifs >> str >> password) {
		if (user == str)
			enpassword = password;
	}
	if (enpassword.size() == 0) {
		cout << "None User" << endl;
		return;
	}
	cout << "please input your password" << endl;
	cin >> password;
	if (enpassword == ctz.get(password)) {
		cout << "success. Press 1 to return menu" << endl;
		ifs.close();
		string input;
		cin >> input;
		if (input == "1") {
			return;
		}
	}
	else {
		cout << "failure, you have second chance to input password" << endl;
		cout << "please input your password" << endl;
		cin >> password;
		if (enpassword == ctz.get(password)) {
			cout << "success. Press 1 to return menu" << endl;
			ifs.close();
			string input;
			cin >> input;
			if (input == "1") {
				return;
			}
		}
		else {
			cout << "failure, you have thrid chance to input password" << endl;
			cout << "please input your password" << endl;
			cin >> password;
			if (enpassword == ctz.get(password)) {
				cout << "success. Press 1 to return menu" << endl;
				ifs.close();
				string input;
				cin >> input;
				if (input == "1") {
					return;
				}
			}
			else {
				cout << "failure, you have no chance to input password. Press 1 to return menu" << endl;
				ifs.close();
				string input;
				cin >> input;
				if (input == "1") {
					return;
				}
			}
		}
	}
}