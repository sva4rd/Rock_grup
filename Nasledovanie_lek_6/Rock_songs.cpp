#include"Rock_artists.h"
#include "Rock_songs.h"

void Rock_songs::set_song_name(const string t)
{
	song_name = t;
}

void Rock_songs::set_release_date(const int t)
{
	release_date = t;
}

void Rock_songs::set_time(const double t)
{
	time = t;
}

string Rock_songs::get_song_name() const
{
	return song_name;
}

int Rock_songs::get_release_date() const
{
	return release_date;
}

double Rock_songs::get_time() const
{
	return time;
}





//void Rock_songs::set_album_songs(const string mysong, const string album_of_song)
//{
//	auto iter = songs.find(mysong);
//	if (iter == songs.end())
//		songs[mysong] = { album_of_song };
//	else
//		iter->second.push_back(album_of_song);
//}
//
//
//int Rock_songs::get_single_songs_number() const
//{
//	int single_number = 0;
//	auto iter = songs.begin();
//	for (iter; iter != songs.end(); ++iter)
//	{
//		auto i = iter->second.begin();
//		for (i; i != iter->second.end(); ++i)
//			if (*i == "<single>")
//				single_number++;
//	}
//	return single_number;
//}
//
//int Rock_songs::get_all_songs_number() const
//{
//	return songs.size();
//}
//
//set<string> Rock_songs::get_all_songs() const
//{
//	set<string> all_songs;
//	auto iter = songs.begin();
//	for (iter; iter != songs.end(); ++iter)
//	{
//		all_songs.insert(iter->first);
//	}
//	return all_songs;
//}
//
//set<string> Rock_songs::get_songs_of_album(const string& name) const
//{
//	set<string> album_songs;
//	auto iter = songs.begin();
//	bool album_finding = false;
//	for (iter; iter != songs.end(); ++iter)
//	{
//		auto vector_iter = iter->second.begin();
//		for (int i=0; i<iter->second.size(); ++i)
//		{
//			if (iter->second[i] == name)
//			{
//				album_songs.insert(iter->first);
//				album_finding = true;
//				break;
//			}
//		}
//	}
//
//	if (!album_finding)
//		throw exception("У данной рок-группы нет такого альбома!");
//	else
//		return album_songs;
//}
//
//set<string> Rock_songs::get_all_single_songs() const
//{
//	if (get_single_songs_number() == 0)
//		throw exception("У этой группы нет песен-синглов!");
//
//	set<string> single_songs;
//	auto iter = songs.begin();
//	
//	for (iter; iter != songs.end(); ++iter)
//	{
//		auto vector_iter = iter->second.begin();
//		for (int i = 0; i < iter->second.size(); ++i)
//		{
//			if (iter->second[i] == "<single>")
//			{
//				single_songs.insert(iter->first);
//				break;
//			}
//		}
//	}
//	
//	return single_songs;
//		
//}
//
//set<string> Rock_songs::get_all_albums_with_song(const string& name) const
//{
//	set<string> albums_with_songs;
//	auto iter = songs.find(name);
//	if (iter == songs.end())
//		throw exception("У данной рок-группы нет такой песни!");
//
//	for (auto i = iter->second.begin(); i != iter->second.end(); ++i)
//	{
//		albums_with_songs.insert(*i);
//	}
//	return albums_with_songs;
//}

//void Rock_songs::single_copy_check(set<string>& singles_add_all)
//{
//	auto iter = songs.begin();
//	for (iter; iter != songs.end(); iter++)
//		singles_add_all.insert(iter->first);
//	all_songs_number = singles_add_all.size();
//}