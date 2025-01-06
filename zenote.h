#ifndef ZENOTE_H
#define ZENOTE_H

#include <iostream>
#include <time.h>
#include <string>
using namespace std;
class zenote;
class zFile;
class tester;

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

		cout << toWrite << endl;
		return toWrite;
	}	
private:
	zenote m_zn;
};



#endif
