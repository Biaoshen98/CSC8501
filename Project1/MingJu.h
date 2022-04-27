#include "Collatz.h"
#include <iostream>
#include <fstream>
#include "StrengthAnalysis.h"
#include <vector>

int isStrInVec(vector<string> vec, string str) {
	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec[i] == str)
			return i;
	}
	return 0;
}

void Mingyan() {
	string str = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	string words(100, 0);
	vector<string>failed;
	int start = 0;
	string characters;
	characters += ' ';
	for (int i = 0; i < 26; i++) {
		characters += 'a' + i;
	}
	for (int i = 0; i < 26; i++) {
		characters += 'A' + i;
	}
	while (1) {
		string tmp;
		string sub;
		int offset = 0;
		cout << "new round" << endl;
		for (unsigned int i = 0; i < str.size(); i++) {
			sub += str[i];
			if (sub.size() > 100)break;
			cout << i << " sub " << sub << endl;
			cout << i << " tmp " << tmp << endl;
			int subint = atoi(sub.c_str());
			for (unsigned int j = 0; j < characters.size(); j++) {
				int offtmp = ctz.get((unsigned char)characters[j], offset);
				if (offtmp == subint and !isStrInVec(failed, tmp + characters[j])) {
					tmp += characters[j];
					offset = offtmp;
					sub = " ";
					cout << "tmp is :" << tmp << endl;
					continue;
				}
			}
		}
		if (sub.size()) {
			if (!tmp.size()) {
				cout << "decode failed " << endl;
				break;
			}
			failed.push_back(tmp);
			tmp = " ";
			sub = " ";
			offset = 0;
		}
		else {
			cout << tmp << endl;
		}
	}
}

