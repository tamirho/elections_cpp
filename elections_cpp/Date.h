#pragma once
#include <iostream>
#include "File_Handler.h"

class Date
{
	// A class representing a date.

private:
	int	_day, _month, _year;

    static const int MIN_DAY, MAX_MONTH, MIN_MONTH, MIN_YEAR, MAX_YEAR;
	static const int DAYS_PER_MONTH[13];

public:
	Date();
	Date(std::istream& in);
	Date(int day, int month, int year);
	Date(const Date&);
	~Date();

	void setDate(const Date& other);
	void setDate(int day, int month, int year);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	int getDay() const { return _day; }
	int getMonth() const { return _month; }
	int getYear() const { return _year; }

	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend std::istream& operator>>(std::istream&, Date&);
	
	const Date& operator=(const Date&);

	void load(std::istream& in);

	void save(std::ostream& out) const;

};

