#include "zenote.h"

void zenote::setFilename(string name) {
  //set filename
  m_filename = name;
}

// set Author
void zenote::setAuthor(string author) {
  m_author = author;
}

void zenote::write() {
  string content = "";
  cout << ">>";
  getline(cin, content);
	m_content = content;
}

class zFile {
public:
	friend class zenote;
	void writeToFile() {
		string toWrite = zn.m_filename;
		toWrite += ".zn";

		cout << toWrite << endl;
	}
private:
	zenote zn;
};


