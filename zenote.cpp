#include "zenote.h"

void zenote::setFilename(string name) {
	m_filename = name;
}

void zenote::setAuthor(string author) {
	m_author = author;
}
void zenote::write(string testCont) {
	string content = testCont; // testCont is "" if no param passed
	if (content == "") { // if not testing
		cout << ">>";
		// continuous keyboard entry until vim quit motion, however, only saves most recent entry i guess
		while((getline(cin, content)) && (content != ":q")) {
			cout << ">>";
		}
	}
	m_content = content;	
}

void zenote::clearContent() {
	m_content = "";
}
