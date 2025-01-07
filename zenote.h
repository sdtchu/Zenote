#ifndef ZENOTE_H
#define ZENOTE_H

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <cstdlib>

using namespace std;
class zenote;
class zFile;
class tester;

const string PATH = "znf/";

class zenote {
public:
	friend class zFile;
  zenote() {
		m_filename = "test";
		m_author = "Kreemy";
		m_content = "";
	}
	zenote(string filename, string author) {
		m_filename = filename;
		m_author = author;
		m_content = "";
	}
	~zenote() {
		m_filename = "";
		m_author = "";
		m_content = "";
	}
	
	void setFilename (string name); // set file name
	void setAuthor(string author); // set Author
	void write(string testCont=""); // basically set content
	string getFilename() { return m_filename; }
	string getAuthor() { return m_author; }
	string getContent() { return m_content; } 
	void clearContent();
private:
	string m_filename;
	string m_content;
	string m_author;
};

class zFile { // only saves as a .zn file
public:
	friend class zenote;
	zFile() {
		zenote zn;
		m_zn.setFilename(zn.getFilename());
		m_zn.setAuthor(zn.getAuthor());
		m_zn.write(zn.getContent());
	}
	~zFile() {
		m_zn.setFilename("");
		m_zn.setAuthor("");
		m_zn.clearContent();
	}	
	void setZn(zenote zn) {
		m_zn.setFilename(zn.getFilename());
		m_zn.setAuthor(zn.getAuthor());
		m_zn.write(zn.getContent());
	}	
	string writeToFile() {
		string toWrite = m_zn.getFilename();
		toWrite += ".zn"; // adds .zn suffix
		string fullPath = PATH + toWrite;
		
		// should open/create file
		ofstream file(fullPath);
		if (!file)
			cerr << "Error: Creation or open error" << endl;

		// puts content into file
		file << m_zn.getContent() << endl;
		cout << m_zn.getContent() << endl;

		file.flush();
		// close file	
		file.close();

		cout << "File saved in " << fullPath << endl;
		return toWrite;
	}

	void initZn(bool test=false) {
		string setFn = "";
		const char* username = getenv("USER"); // get user name
		string str(username);
		m_zn.setAuthor(username);
		if (test) {
			cout << "Enter your filename: ";
			cin >> setFn;
			cout << endl;	
			m_zn.setFilename(setFn);
		} else {
			m_zn.setFilename("test");
		}
		m_zn.write();
		writeToFile();
	}	
private:
	zenote m_zn;
};



#endif
