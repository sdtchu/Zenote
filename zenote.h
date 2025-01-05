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
  void write(); // basically set content
  string getFilename() { return m_filename; }
	string getAuthor() { return m_author; }
	string getContent() { return m_content; } 

private:
	// filename
	string m_filename;
	// content
	string m_content;
	// date made
	// tm m_date;
	// Author (get user)
	string m_author;
};

#endif
