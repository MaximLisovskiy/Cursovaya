#pragma once
#include "Doctor.h"

Doctor::Doctor(string specialization, string category, string degree, int patients, int salary,
    string fullName, string gender, string phoneNumber, int day, int month, int year,
    int height, int weight) :
    Person(fullName, gender, phoneNumber, day, month, year, height, weight)
{
    this->specialization = specialization;
    this->patients = patients;
    this->salary = salary;
    this->category = category;
    this->degree = degree;
}

int Doctor::getTax() const // стоимость консультации
{
    if (degree == "A")
    {
        return 2.5 * this->salary ;
    }
    if (degree == "B")
    {
        return 2 * this->salary;
    }
    if (degree == "C")
    {
        return 1.5 * this->salary;
    }
    int tax =  (this->salary) * 1 ; // формула для врача
    return tax;
}

string to_string(Doctor const& self) 
{
    return "FullName: " + self.getfullName() + "\nGender: " + self.getgender() + "\nPhone Number: " + self.getphoneNumber() + "\nSpecialization: " + self.getspecialization() + "\nCategory: " + self.getcategory() + "\nDegree: " + self.getdegree() + "\nDay: " + to_string(self.getday()) + "\nMonth: " + to_string(self.getmonth()) + "\nYear: " + to_string(self.getyear()) + "\nHeight: " + to_string(self.getheight()) + "\nWeight: " + to_string(self.getweight())  + "\nPatients: " + to_string(self.getpatients()) + "\nSalary : " + to_string(self.getsalary());
}



void Doctor::consult()
{
    this->patients++;
}