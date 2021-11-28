#pragma once
#include"Rock_Grup.h"

class Rock_artists :
	public Rock_Grup
{
protected:
	string name;
	string profession;
	int birth_date;
public:
	void set_artist_name(const string t);
	void set_artist_profession(const string t);
	void set_artist_birth_date(const int t);
	
	string get_artist_name() const;
	string get_artist_profession() const;
	int get_artist_birth_date() const;
};