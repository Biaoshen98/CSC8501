#pragma once
#include <iostream>
#include <string>
using namespace std;
class Collatz {
public:
	Collatz(unsigned char ch = 0) {
		for (int i = 1; i < 1024; i++) {
			chs[i] = get(i);
		}
	}
	virtual int get(unsigned int ch, int offset = 0) {
		int result = 0;
		unsigned int c = ch + offset;
		while (c != 1) {
			if (c % 2 == 0)
				c /= 2;
			else
				c = c * 3 + 1;
			result++;
		}
		return result;
	}
	virtual string get(string str) {
		int offset = 0;
		string result;
		for (unsigned int i = 0; i < str.size(); i++) {
			char c = str[i];
			offset = chs[(unsigned char)c + offset];
			char buf[10];
			snprintf(buf, 10, "%d", offset);
			result += buf;
		}
		return result;
	}
protected:
	int chs[1024];
};

class CollatzEx : Collatz {
public:
	int get(unsigned char ch, int offset) {
		int result = 0;
		unsigned int c = ch + offset;
		while (c != 1) {
			if (c % 2 == 0)
				c /= 2;
			else
				c = c * 3 + 1;
			result++;
		}
		return result;
	}
};

class GeneratePassword {
public:
	GeneratePassword() {
		srand((unsigned)time(0));
		for (int i = 0; i < sizeof(buff); i++) {
			buff[i] = rand() % 26 + 'a';
		}
		return;
	}
	virtual string generate(int len) {
		string str(len, '0');
		for (int i = 0; i < len; i++) {
			str[i] = buff[rand() % 10];
		}
		return str;
	}
private:
	char buff[10];
};

class GeneratePasswordEx : GeneratePassword {
public:
	GeneratePasswordEx(){}
	virtual string generate(int len) {
		string str(len, '0');
		memset(&str[0], 0, len);
		for (int i = 0; i < len; i++) {
			char c = rand() % 256;
			while (!isCValid(str, c))
				c = rand() % 256;
			str[i] = c;
		}
		return str;
	}
private:
	int isCValid(string str, char c) {
		if (c == 0)
			return 0;
		for (unsigned int i = 0; i < str.size(); i++) {
			if (c == str[i])
				return 0;
		}
		return 1;
	}
};
Collatz ctz;
