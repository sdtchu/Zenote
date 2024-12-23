#ifndef ZENOTE_H
#define ZENOTE_H

#include <iostream>
#include <time.h>
#include <string>
using namespace std;

class zenote {
	public:
    zenote() {
      setFilename("test");
      setDate();
      setAuthor("Kreemy");
      m_content = "";
    }
    zenote(string filename, string author) {
      setFilename(filename);
      setAuthor(author);
      setDate();
      m_content = "";
    }
		// set file name
    void setFilename (string name);
    // set date
    void setDate();
    // set Author
    void setAuthor(string author);
    string getFilename() { return m_filename; }
    tm getDate() { return m_date; }
    string getAuthor() { return m_author; }
    string write();
	private:
    // filename
    string m_filename;
    // content
    string m_content;
    // date made
    tm m_date;
    // Author (get user)
    string m_author;
};

#endif
