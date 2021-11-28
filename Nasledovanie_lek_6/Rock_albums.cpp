#include"Rock_albums.h"

void Rock_albums::set_album_name(const string t)
{
	album_name = t;
}

void Rock_albums::set_release_date(const int t)
{
	release_date = t;
}



string Rock_albums::get_album_name() const
{
	return album_name;
}

int Rock_albums::get_release_date() const
{
	return release_date;
}

//void Rock_albums::print_albums_name(void print(const string&)) const
//{
//	for (auto i = albums.begin(); i != albums.end(); i++)
//	{
//		print(*i);
//	}
//}