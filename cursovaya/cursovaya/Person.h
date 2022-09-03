#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person();
	Person(string fullName, string gender, string phoneNumber, int day, int month, int year, int height, int weight);
private:
	string fullName;
	string gender;
	string phoneNumber;
	int day, month, year;
	int height;
	int weight;

public:
	string getfullName() const { return fullName; }
	string getgender() const { return gender; }
	string getphoneNumber() const { return phoneNumber; }
	int getday() const { return day; }
	int  getmonth() const { return month; }
	int getyear() const { return year;}
	int getheight() const{return height;}
	int getweight() const{return weight;}


	void setfullName(string fullName){this->fullName = fullName;}
	void setgender(string gender) {this->gender = gender;}
	void setphoneNumber(string phoneNumber) {this->phoneNumber = phoneNumber;}
	void setday(int day) {this->day = day;}
	void setmonth(int month) {this->month = month;}
	void setyear(int year) {this->year = year;}
	void setheight(int height) {this->height = height;}
	void setweight(int weight) {this->weight = weight;}

	bool isheightOver200cm() const;
	bool isphoneNumberBegin0();

};