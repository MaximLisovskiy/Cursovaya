#pragma once
#include "Person.h"
class Artist : public Person
{
	private:
		string genre;
		int speeches;

	public:
		Artist();
		Artist(string genre, int speeches, string fullName, string gender, string phoneNumber, 
				int day, int month, int year, int height, int weight);

		void ChangePhoneNumber(string _phoneNumber);
		void addspeech();
		void ChangeGenre(string genre);
		bool isHeightOver200cm();

		friend std::string to_string(Artist const& self);

		string getgenre() const { return genre; }
		int getspeeches() const { return speeches; }
		

		void setgenre(string genre)  { this->genre =genre; }
		void setspeeches(int speeches)  {  this->speeches = speeches; }
		
};
