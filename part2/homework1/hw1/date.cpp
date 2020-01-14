#include "date.h"

date::date() : day(0), month(0), year(0) { }

date::date(int day, int month, int year)  : day(day), month(month), year(year) { }

int date::compareTo(date another_date) {
	if (year > another_date.year) { // comparing years firstly
		return 1;
	} else {
		if (year < another_date.year) {
			return -1;
		}
		else {
			if (month > another_date.month) { // then months
				return 1;
			} else {
				if (month < another_date.month) {
					return -1;
				}
				else {
					if (day > another_date.day) { // and days
						return 1;
					} else {
						if (day < another_date.day) {
							return -1;
						}
						else {
							return 0;
						}
					}
				}
			}
		}
	}
}

ostream &operator<< (ostream &stream, date d) {
	stream << d.month << '/' << d.day << '/' << d.year; // MM/DD/YYYY
	return stream;
}