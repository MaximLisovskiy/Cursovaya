#pragma once
#include "Person.h"

Person::Person()
{}

Person::Person(string fullName, string gender, string phoneNumber, int day, int month, int year, int height, int weight)
{
    this->fullName = fullName;
    this->gender = gender;
    this->phoneNumber = phoneNumber;
    this->day = day;
    this->month = month;
    this->year = year;
    this->height = height;
    this->weight = weight;
}
