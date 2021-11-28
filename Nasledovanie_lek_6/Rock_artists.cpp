#include"Rock_Grup.h"
#include "Rock_artists.h"

void Rock_artists::set_artist_name(const string t)
{
	name = t;
}

void Rock_artists::set_artist_profession(const string t)
{
	profession = t;
}

void Rock_artists::set_artist_birth_date(const int t)
{
	birth_date = t;
}

string Rock_artists::get_artist_name() const
{
	return name;
}

string Rock_artists::get_artist_profession() const
{
	return profession;
}

int Rock_artists::get_artist_birth_date() const
{
	return birth_date;
}