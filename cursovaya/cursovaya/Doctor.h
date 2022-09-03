#pragma once
#include "Person.h"
class Doctor : public Person
{
private:
	string specialization; // специализация
	string category; // категория
	string degree; // степень
	int patients;
	int salary;
public:
	Doctor();
	Doctor(string specialization, string category, string degree, int patients, int salary,
		string fullName, string gender, string phoneNumber, int day, int month, int year,
		int height, int weight);

	int getTax() const;
	void consult();
	friend std::string to_string(Doctor const& self);

	string getspecialization() const { return specialization; }
	string getcategory() const { return category; }
	string getdegree() const { return degree; }
	int getpatients() const { return patients; }
	int getsalary() const { return salary; }
	

	void setSpecialization(string specialization) { this->specialization = specialization; }
	void setcategory(string category) { this->category = category; }
	void setdegree(string degree) { this->degree = degree; }
	void setpatienst(int patients) { this->patients = patients; }
	void setsalary(int salary) { this->salary = salary; }
	
};