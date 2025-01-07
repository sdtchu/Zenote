#include "zenote.h"

class tester {
public:
	friend class zenote;
	friend class zFile;

	bool zenoteConstructorTest() {
		bool result = true;
		zenote zn;
		result = (zn.getFilename() == "test") && (zn.getAuthor() == "Kreemy")
						&& (zn.getContent() == "");

		return result;
	}

	bool zenoteOvldConstructorTest() {
		 bool result = true;
		 zenote zn("zenote", "seth");
		 result = (zn.getFilename() == "zenote") && (zn.getAuthor() == "seth")
		 && (zn.getContent() == "");
		 return result;
	}

	bool writeTest() {
		bool result = true;
		zenote zn;
		zn.write();
		result = (zn.getContent() != "");
		cout << zn.getContent() << endl;
		char confirm = 'n';
		cout << "Confirm correct entry ('y' or 'n'): ";
		cin >> confirm;

		if (confirm == 'y')
			return result;
		else
			return false;
	}

	bool writeToFileTest() {
		bool result = true;
		zenote zn;
		zn.write();
		zFile zf;
		zf.setZn(zn);
		string file = zn.getFilename();
		file += ".zn";
		if(zf.writeToFile() == file) {
			return result;
		}
		return false;
	}
};

int main() {
	tester test;

	if (test.zenoteConstructorTest())
		cout << "Constructor Test Passed" << endl;	
	else
		cout << "Constructor Test Failed" << endl;	

	if (test.zenoteOvldConstructorTest())
		cout << "Overloaded Constructor Test Passed" << endl;
	else
		cout << "Overloaded Constructor Test Failed" << endl;
	if (test.writeTest())
		cout << "Write Test Passed" << endl;
	else
		cout << "Write Test Failed" << endl;
	if (test.writeToFileTest())
		cout << "Write To File Test Passed" << endl;
	else
		cout << "Write To File Test Failed" << endl;

  return 0;
}
