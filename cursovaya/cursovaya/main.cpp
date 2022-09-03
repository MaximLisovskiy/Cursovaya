#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Doctor.h"
#include "Artist.h"


using namespace std;

void greetings();
void actionsMain(const int role);
void addArtist();
void addDoctor();
void seeInfo(const int role);
void deletePerson(int role, int id);
bool comparseDoctors(Doctor* x, Doctor* y);
void printDoctorsByPrice();
void printArtistbygenre();
void addspeechesforall();

vector<Doctor*> doctors;
vector<Artist*> artist;

int main()
{
   
    int choise = 0; // выбор, навигация по меню
    int whoAmI = 0; // кто я? переключение между жоктором и актером 
    bool actions_main = false,  delete_person = false, consult = false;
    greetings(); // вызов начального меню
    while (true) 
    {
        cin >> choise;
        if (delete_person) 
        {
            deletePerson(whoAmI, choise);
            delete_person = false;
            continue;
        }
        else if (consult)
        {
            doctors[choise]->consult();
            consult = false;
            actionsMain(whoAmI);
            continue;
        }
        else if (choise == 0) 
        {
            actions_main = false;
            whoAmI = 0;
            greetings();
            continue;
        }
        else if (choise == 9) 
        { 
            break; 
        }
        if (whoAmI == 0) 
        {
            actions_main = true; // стартовое меню
            whoAmI = choise;
            actionsMain(choise);
        }
        else 
        {
            if (whoAmI == 1) 
            {
                if (choise == 1) 
                { 
                    seeInfo(whoAmI); 
                }
                if (choise == 2) 
                {
                    delete_person = true;
                    cout << "Enter ID to delete: ";
                    continue;
                }
                if (choise == 5) 
                { 
                    printDoctorsByPrice(); 
                }
                if (choise == 6) 
                {
                    consult = true;
                    cout << "Enter ID of Doctor for consult: ";
                    continue;
                }
                if (choise == 3) 
                { 
                    addDoctor(); 
                }
            }
            else if (whoAmI == 2) 
            {
                if (choise == 1)
                {
                    seeInfo(whoAmI);
                }
                if (choise == 5)
                {
                    printArtistbygenre();
                }
                if (choise == 2)
                {
                    delete_person = true;
                    cout << "Enter ID to delete: ";
                    continue;
                }
                if (choise == 3) 
                { 
                    addArtist(); 
                }
                if (choise == 6)
                {
                    addspeechesforall();
                }
            }
        }
    }
    return 0;
}

bool comparseDoctors(Doctor* x, Doctor* y) // функция сортировки докторов по стоимости посещения
{
    return (x->getTax() < y->getTax());
}

void greetings() 
{
    cout << "Please select Action..." << endl;
    cout << "1 - Select Doctors" << endl;
    cout << "2 - Select Actors" << endl;
    cout << "9 - Exit" << endl;
}

void actionsMain(const int role) 
{
    string actor;
    if (role == 1) 
    {
        actor = "Doctor(s)";
    }

    else if (role == 2) 
    {
        actor = "Artist(s)";
    }
    cout << "Please select Action..." << endl;
    cout << "0 - To main menu" << endl;
    cout << "1 - See Info about " << actor << endl;
    cout << "2 - Delete " << actor << endl;
    cout << "3 - Add " << actor << endl;
    if (role == 1) 
    {
        cout << "5 - Get " << actor << " list by consult price" << endl;
        cout << "6 - Get consultation" << endl;
    }
    else if (role == 2) 
    {
        cout << "5 - Get " << actor << " genre type " << endl;
        cout << "6 - Add speeches for all " << endl;
    }
    cout << "9 - Exit" << endl;
}



void addArtist() 
{
    string fullName, gender, phoneNumber, genre = "";
    int day, month, year, height, weight, speeches = 0;
    cout << "Please Enter Full Name: ";
    cin >> fullName;
    cout << "Please Enter Gender: ";
    cin >> gender;
    cout << "Please Enter Phone Number: ";
    cin >> phoneNumber;
    cout << "Please Enter Genre: ";
    cin >> genre;
    cout << "Please Enter Speeches: ";
    cin >> speeches;
    cout << "Please Enter Day of Birth: ";
    cin >> day;
    cout << "Please Enter Month of Birth: ";
    cin >> month;
    cout << "Please Enter Year of Birth: ";
    cin >> year;
    cout << "Please Enter Height: ";
    cin >> height;
    cout << "Please Enter Weight: ";
    cin >> weight;
    artist.push_back(new Artist( genre, speeches, fullName,  gender,  phoneNumber, day,  month,  year,  height, weight));
    cout << "Success" << endl;
    actionsMain(2);
}
void addDoctor() 
{
    string fullName, gender, phoneNumber, specialization, category, degree = "";
    int day, month, year, height, weight, patients, salary = 0;
    cout << "Please Enter Full Name: ";
    cin >> fullName;
    cout << "Please Enter Gender: ";
    cin >> gender;
    cout << "Please Enter Phone Number: ";
    cin >> phoneNumber;
    cout << "Please Enter Specialization: ";
    cin >> specialization;
    cout << "Please Enter Category: ";
    cin >> category;
    cout << "Please Enter Degree: ";
    cin >> degree;
    cout << "Please Enter Day of Birth: ";
    cin >> day;
    cout << "Please Enter Month of Birth: ";
    cin >> month;
    cout << "Please Enter Year of Birth: ";
    cin >> year;
    cout << "Please Enter Height: ";
    cin >> height;
    cout << "Please Enter Weight: ";
    cin >> weight;
    cout << "Please Enter Patients: ";
    cin >> patients;
    cout << "Please Enter Salary: ";
    cin >> salary;
    doctors.push_back(new Doctor(specialization,  category,  degree,  patients,  salary, fullName,  gender,  phoneNumber,  day,  month,  year, height,  weight));
    cout << "Success" << endl;
    actionsMain(1);
}

void seeInfo(const int role) // вывод информации про всех докторов/артистов с помощью перегруженной функции to_string
{
    if (role == 2)
    {
        for (unsigned int i = 0; i < artist.size(); i++)
        {
            cout << "Id :" << i << endl;
            cout << to_string(*artist[i]) << endl;
        }
        cout << "0 - To main menu" << endl;
    }

    if (role == 1)
    {
        for (unsigned int i = 0; i < doctors.size(); i++)
        {
            cout << "Id :" << i << endl;
            cout << to_string(*doctors[i]) << endl;
        }
        cout << "0 - To main menu" << endl;
    }
}

void deletePerson(int role, int id) 
{
    if (role == 1) 
    {
        doctors.erase(doctors.begin() + id);
    }
    else if (role == 2)
    {
        artist.erase(artist.begin() + id);
    }
    actionsMain(role);
}

void printDoctorsByPrice() 
{
    string input = "";
    cout << "Please enter specialisation" << endl;
    cin >> input;
    vector<Doctor*> sortDoctors = doctors;
    sort(sortDoctors.begin(), sortDoctors.end(), comparseDoctors);
    for (int i = 0; i < sortDoctors.size(); i++) 
    {
        if (sortDoctors[i]->getspecialization() == input)
        {
            auto x = find(doctors.begin(), doctors.end(), sortDoctors[i]);
            cout << "Id :" << x - doctors.begin() << endl;
            cout << to_string(*sortDoctors[i]) << endl;
        }
    }
    actionsMain(1);
}

void printArtistbygenre()
{
    string input = "";
    cout << "Please enter genre" << endl;
    cin >> input;
    for (int i = 0; i < artist.size(); i++)
    {
        if (artist[i]->getgenre() == input)
        {
            cout << "Id :" << i << endl;
            cout << to_string(*artist[i]) << endl;
        }
    }
    actionsMain(2);
}

void addspeechesforall()
{
    for (int i = 0; i < artist.size(); i++)
    {
        artist[i]->addspeech();
    }
    actionsMain(2);
}

  
