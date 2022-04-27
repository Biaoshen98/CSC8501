#pragma once
#include "Collatz.h"
#include <iostream>
#include <fstream>
string tryPassword(string password, int len, unsigned char start, unsigned char stop) {

	unsigned int starts[1024], stops[1024];
	

	for (int i = 0; i < len; i++) {
		starts[i] = start;
		stops[i] = stop;
	}
	string ps(len, 0);
	while (1) {
		for (int i = 0; i < len; i++) {
			ps[i] = starts[i];
		}
		if (password == ctz.get(ps)) {
			return ps;
		}
		else {
			if (!memcmp(starts, stops, sizeof(starts)))
				break;
			for (int i = 0; i < len; i++) {
				if (starts[i] != stops[i]) {
					for (int j = 0; j < i; j++) {
						starts[j] = start;
					}
					starts[i]++;
					break;
				}
			}
		}
	}
	return string();
}
void StrengthAnalysis() {
	string enpassword;
	ifstream ifs("passwordtest.txt");
	auto start = time(0);
	int passwordlen;
	int j = 0;
	for (auto i = 0; i < 10000; i++) {
		passwordlen = i / 100 + 1;
		if (i % 100 == 0) {
			j = j + 1;
			double p = j * 0.5;
			cout << "len " << passwordlen << " and " << "100 password decrypted! total time cost is " << (time(0) - start) <<". This len passwords have 100% decrypted. Total have succeed decrypted "<< p <<"%" << endl;
			start = time(0);
		}
		ifs >> enpassword;
		string passwd = tryPassword(enpassword, passwordlen, (unsigned char)'a', (unsigned char)'z');
		cout << passwd << endl;
	}
	for (auto i = 10000; i < 20000; i++) {
		passwordlen = (i / 100 - 100 + 1);
		if (i % 100 == 0) {
			j = j + 1;
			double p = j * 0.5+50;
			cout << "len " << passwordlen << " and " << "100 password decrypted! total time cost is " << (time(0) - start) << ". This len passwords have 100% decrypted. Total  have succeed decrypted " << p << "%" << endl;
			start = time(0);
		}
		passwordlen = i / 100 + 1;
		ifs >> enpassword;
		string passwd = tryPassword(enpassword, passwordlen, (unsigned char)1, (unsigned char)255);
	}
	return;
}