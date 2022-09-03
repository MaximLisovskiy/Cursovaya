    #pragma once
    #include "Artist.h"
	Artist::Artist(string genre, int speeches, string fullName, string gender, string phoneNumber, int day, int month, int year, int height, int weight) :
	Person(fullName, gender, phoneNumber, day, month, year, height, weight)
{
    this->speeches = speeches;
    this->genre = genre;
}

    string to_string(Artist const& self)
    {
        return "\nFullName: " + self.getfullName() + "\nGender: " + self.getgender() + "\nPhone Number: " + self.getphoneNumber() + "\nGenre" + self.getgenre() + "\nSpeeches" + to_string(self.getspeeches()) + "\nDay: " + to_string(self.getday()) + "\nMonth: " + to_string(self.getmonth()) + "\nYear: " + to_string(self.getyear()) + "\nHeight: " + to_string(self.getheight()) + "\nWeight: " + to_string(self.getweight());
    }

    void Artist::ChangePhoneNumber(string _phoneNumber)
    {
        if (_phoneNumber[0] == '0')
        {
            this->setphoneNumber("+38" + _phoneNumber);
        }
        else
        {
            this->setphoneNumber(_phoneNumber);
        }
    }
    void Artist::addspeech()
    {
        this->speeches++;
    }
    void Artist::ChangeGenre(string genre)
    {
        this->genre = genre;
    }
    bool Artist::isHeightOver200cm()
    {
        return this->getheight() > 200;
    }