#include "Date.h"
#include <string>
using namespace std;

Date::Date(void) : month(0), day(0), year(0), hour(0), 
	minute(0), second(0) { }

Date::Date(int month, int day, int year, int hour, int minute, int second) :
	month(month), day(day), year(year), hour(hour), minute(minute), second(second) { }

void Date::setMonth(int& month) {
	this->month = month;
}

void Date::setDay(int& day) {
	this->day = day;
}

void Date::setYear(int& year) {
	this->year = year;
}

void Date::setHour(int& hour) {
	this->hour = hour;
}

void Date::setMinute(int& minute) {
	this->minute = minute;
}

void Date::setSecond(int& second) {
	this->second = second;
}

int Date::getMonth(void) const {
	return month;
}

int Date::getDay(void) const {
	return day;
}

int Date::getYear(void) const {
	return year;
}

int Date::getHour(void) const {
	return hour;
}

int Date::getMinute(void) const {
	return minute;
}

int Date::getSecond(void) const {
	return second;
}

bool Date::operator== (const Date &rhs) {

	// comparing step by step

	return month == rhs.month && day == rhs.day && year == rhs.year &&
		hour == rhs.hour && minute == rhs.minute && second == rhs.second;
}

bool Date::operator< (const Date &rhs) {
	// comparing step by step
	if (year < rhs.year) {
		return true;
	} else if (year > rhs.year) {
		return false;
	} else if (month < rhs.month) {
		return true;
	} else if (month > rhs.month) {
		return false;
	} else if (day < rhs.day) {
		return true;
	} else if (day > rhs.day) {
		return false;
	} else if (hour < rhs.hour) {
		return true;
	} else if (hour > rhs.hour) {
		return false;
	} else if (minute < rhs.minute) {
		return true;
	} else if (minute > rhs.minute) {
		return false;
	} else if (second < rhs.second) {
		return true;
	}
	return false;
}

ostream &operator<<(ostream& stream, const Date& date) {

	if (date.getMonth() < 10) {
		stream << '0';
	}
	stream << date.getMonth() << '/';

	if (date.getDay() < 10) {
		stream << '0';
	}
	stream << date.getDay() << '/';
	
	stream << date.getYear() << ' ';

	if (date.getHour() < 10) {
		stream << '0';
	}
	stream << date.getHour() << ':'; 
	
	if (date.getMinute() < 10) {
		stream << '0';
	}
	stream << date.getMinute() << ':';
	
	if (date.getSecond() < 10) {
		stream << '0';
	}
	stream << date.getSecond();

	return stream;
}

istream &operator>>(istream& stream, Date& date) {

	if (stream.bad()) {
		return stream;
	}

	// parsing date from string successively

	string string_date;
	getline(stream, string_date);

	int month, day, year, hour, minute, second;
	int index;

	index = string_date.find_first_of("/", 0);
	month = atoi(string_date.substr(0, index).c_str());

	day = atoi(string_date.substr(index + 1, string_date.find_first_of("/", index + 1)).c_str());

	index = string_date.find_first_of("/", index + 1);
	year = atoi(string_date.substr(index + 1, string_date.find_first_of(" ", index + 1)).c_str());

	index = string_date.find_first_of(" ", index + 1);
	hour = atoi(string_date.substr(index + 1, string_date.find_first_of(":", index + 1)).c_str());

	index = string_date.find_first_of(":", index + 1);
	minute = atoi(string_date.substr(index + 1, string_date.find_first_of(":", index + 1)).c_str());

	index = string_date.find_first_of(":", index + 1);
	second = atoi(string_date.substr(index + 1, string_date.length()).c_str());

	// creating the object
	date = Date(month, day, year, hour, minute, second);

	return stream;
}
