#pragma once
#include <atomic>
#include "Collatz.h"
#include <fstream>
#include <iostream>
void Creat() {
	GeneratePasswordEx gex;
	GeneratePassword ge;
	char** password = (char**)malloc(20000 * sizeof(char*));
	if (NULL == password) {
		cout << "failed" << endl;
		return;
	}
	for (int i = 0; i < 20000; i++) {
		password[i] = (char*)malloc(128);
		if (NULL == password[i]) {
			cout << "failed" << endl;
			return;
		}
	}
	for (int i = 0; i < 10000; i++) {
		int len = i / 100 + 1;
		memcpy(password[i], ge.generate(len).c_str(), len);
	}
	for (int i = 10000; i < 20000; i++) {
		int len = i / 100 -100+ 1;
		memcpy(password[i], gex.generate(len).c_str(), len);
	}
	ofstream ofs("passwordtest.txt");
	for (int i = 0; i < 10000; i ++) {
		string str(i / 100 + 1, 0);
		memcpy(&str[0], password[i], i / 100 + 1);
		ofs << ctz.get(str) << endl;
	}
	for (int i = 10000; i < 20000; i++) {
		string str(i / 100 -100+ 1, 0);
		memcpy(&str[0], password[i], i / 100 - 100 + 1);
		ofs << ctz.get(str) << endl;
	}
	ofs.close();
	for (int i = 0; i < 20000; i++) {
		free(password[i]);
	}
	free(password);
	cout << "Creat Password Document Succeed. Will return to the menu." << endl;
}