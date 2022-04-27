#include <iostream>
using namespace std;
#include "Inputuserandpassword.h"
#include "CheckuserPassword.h"
//#include "CreatPasswordDocument.h"
#include "StrengthAnalysis.h"
#include "Creat2.h"
#include "MingJu.h"
//#include "Daan.h"
int main() {
	while (1) {
		cout << "////////////////////////////////////////////////" << endl;
		cout << "///please input your choice!                 ///" << endl;
		cout << "///1.input user name and password!           ///" << endl;
		cout << "///2.check user name and password!           ///" << endl;
		cout << "///3.creat analysis password document!       ///" << endl;
		cout << "///4.strength analysis password document!    ///" << endl;
		cout << "///5.decrypted!                              ///" << endl;
		cout << "////////////////////////////////////////////////" << endl;
		string input;
		cin >> input;
		if (input == "1") {
			InputUserPasswd();
		}
		else if (input == "2") {
			CheckUserPassword();
		}
		else if (input == "3") {
			Creat();
		}
		else if (input == "4") {
			StrengthAnalysis();
		}
		else if (input == "5") {
			Mingyan();
		}

	}
}
