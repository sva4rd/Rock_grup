#pragma once
#include"Rock_Grup.h"

class Rock_songs :
	public Rock_Grup
{
protected:
	string song_name;
	int release_date;
	double time;
public:
	void set_song_name(const string t);
	void set_release_date(const int t);
	void set_time(const double t);

	string get_song_name() const;
	int get_release_date() const;
	double get_time() const;

};