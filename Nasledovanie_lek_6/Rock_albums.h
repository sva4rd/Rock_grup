#pragma once
#include"Rock_Grup.h"

class Rock_albums :
	public Rock_Grup
{
protected:
	string album_name;
	int release_date;
public:
	void set_album_name(const string t);
	void set_release_date(const int t);

	string get_album_name() const;
	int get_release_date() const;
};