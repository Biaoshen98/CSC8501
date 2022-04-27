#pragma once
#include "Collatz.h"
#include <iostream>
#include <fstream>
using namespace std;
void InputUserPasswd() {
	cout << "please input your username" << endl;
	string user;
	cin >> user;
	string password;
	string enpassword;
	cout << "please input your password" << endl;
	cin >> password;
	cout << "username: " << user << endl;
	cout << "password: " << password << endl;
	enpassword = ctz.get(password);
	cout << "encrypted password:" << ctz.get(password) << endl;
	ofstream ofs("password.txt", ios::app);
	ofs << user << " " << enpassword << endl;
	cout << "Creat New User. Press 1 to return menu" << endl;
	string input;
	cin >> input;
	if (input == "1") {
		return;
	}
}