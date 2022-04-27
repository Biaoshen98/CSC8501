#pragma once
#include "Collatz.h"
#include <iostream>
#include <fstream>
using namespace std;

void CreatPasswordDocument() {
	GeneratePasswordEx gex;
	GeneratePassword ge;
	static string password[20000];
	for (int i = 0; i < 10000; i++) {
		password[i] = ge.generate(i / 100 + 1);
	}
	for (int i = 10000; i < 20000; i++) {
		password[i] = gex.generate(i / 100 - 100 + 1);
	}
	ofstream ofs("passwordtest.txt");
	for (int i = 0; i < 20000; i++) {
		ofs << ctz.get(password[i]) << endl;
	}
	ofs.close();
	cout << "Creat Password Document Succeed. Press 1 to return menu" << endl;
	string input;
	cin >> input;
	if (input == "1") {
		return;
	}
}