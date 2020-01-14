#include <iostream>
#include <string>
#include "Client.h"

Client::Client(void) :fname(""), lname(""), email(""), 
	passwd("") { }
Client::Client(Client const &c) : fname(c.fname), 
	lname(c.lname), email(c.email), passwd(c.passwd) { }
Client::Client(string &fname, string &lname, string &email, string &passwd) : fname(fname), 
	lname(lname), email(email), passwd(passwd) { }

string Client::getEmail() const {
	return email;
}

string Client::getFname() const {
	return fname;
}

string Client::getLname() const {
	return lname;
}

string Client::getPasswd() const {
	return passwd;
}

void Client::setEmail(const string& email) {
	this->email = email;
}

void Client::setLname(const string& lname) {
	this->lname = lname;
}

void Client::setFname(const string& fname) {
	this->fname = fname;
}

void Client::setPasswd(const string& passwd) {
	this->passwd = passwd;
}

bool Client::verifyPasswd(string passwd) {
	return this->passwd == passwd;
}

istream &operator>>(istream& stream, Client& c) {
	
	if (stream.bad()) {
		return stream;
	}

	string fname, lname, email, passwd;
	getline(stream, fname);
	getline(stream, lname);
	getline(stream, email);
	getline(stream, passwd);
	c.setFname(fname);
	c.setLname(lname);
	c.setEmail(email);
	c.setPasswd(passwd);
	return stream;
}