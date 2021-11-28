#include <windows.h>

#include "Rock_artists.h"
#include "Rock_songs.h"
#include "Rock_albums.h"

using namespace std;

bool operator<(const Rock_albums& a, const Rock_albums& b)
{
	return (a.get_album_name() < b.get_album_name());
}

struct info
{
	Rock_Grup name;
	vector<Rock_artists> musicians;
	map <Rock_albums, vector<Rock_songs> > albums;
	vector<Rock_songs> singles;
};

int check_date();
void Song_time_setter(Rock_songs& MySongs);

// ф-ция для удаления ненужных пробелов
void Space_delete(string& name)
{
	int i = 0;
	while (name[i] == ' ')
		name.erase(i, 1);

	for (i; i < name.size(); i++)
	{
		if (i + 1 == name.size())
		{
			if (name[i] == ' ')
				name.erase(i, 1);
			break;
		}
		if (name[i] == ' ' && name[i + 1] == ' ')
		{
			name.erase(i, 1);
			i--;
		}
	}
}

set<string>grups;
void Name_reading(Rock_Grup& MyGrup)
{
	bool input = false;
	while (!input)
	{
		input = true;
		string mygrup_name;
		cout << "Введите название рок-группы: ";
		getline(cin, mygrup_name);
		Space_delete(mygrup_name);
		
		// проверка на повторы 
		auto iter = grups.find(mygrup_name);
		if (iter != grups.end())
		{
			cout << "Уже существует группа с таким названием!\n";
			input = false;
			continue;
		}
		grups.insert(mygrup_name);


		try
		{
			MyGrup.Set_grupname(mygrup_name);
		}
		catch (exception& ex)
		{
			cout << ex.what() << '\n';
			input = false;
			continue;
		}
	}
	
}


void Artists_birth_date_setter(Rock_artists& MyArtists)
{
	cout << "Введите год рождения артиста: ";
	//int date1;
	int date = check_date();
	
	MyArtists.set_artist_birth_date(date);
	cin.ignore();
}
void Artists_profession_setter(Rock_artists& MyArtists)
{
	cout << "Введите его профессию: ";
	string profession;
	getline(cin, profession);
	Space_delete(profession);
	while (profession.empty() || profession.find_first_not_of(' ') == string::npos)
	{
		cout << "Профессии музыкантов не могут быть пустыми или состоять только из пробелов!\n";
		cout << "Введите профессию музыканта: ";
		getline(cin, profession);
	}
	MyArtists.set_artist_profession(profession);
	cout << '\n';
}
void Artists_name_setter(Rock_artists& MyArtists, set <string>& my_artists, int artists_number)
{
	bool input = false;
	string name;
	while (!input)
	{
		input = true;
		int first_size = my_artists.size();
		cout << "Введите имя артиста группы: ";
		getline(cin, name);
		if (name.empty() || name.find_first_not_of(' ') == string::npos)
		{
			cout << "Имена музыкантов не могут быть пустыми или состоять только из пробелов!\n";
			cout << "Введите другое имя: ";
			input = false;
			continue;
		}
		Space_delete(name);
		my_artists.insert(name);
		if (first_size == my_artists.size())
		{
			cout << "Этот музыкант уже есть в группе!\n";
			input = false;
			continue;
		}
	}
	MyArtists.set_artist_name(name);
	
}
set <string> my_artists;
void Artists_setter(Rock_artists& MyArtists, int artists_number, vector<Rock_artists>& musicians)
{
	for (int i = 0; i < artists_number; i++)
	{
		Artists_name_setter(MyArtists, my_artists, artists_number);
		Artists_profession_setter(MyArtists);
		Artists_birth_date_setter(MyArtists);

		musicians.push_back(MyArtists);
	}
	my_artists.clear();
}
void Artists_reading(Rock_artists& MyArtists, vector<Rock_artists>& musicians)
{
	bool input;
	do
	{
		input = true;
		int artists_number;
		cout << "Введите количество артистов в группе: ";
		cin >> artists_number;
		cin.ignore();
		if (artists_number < 2)
		{
			cout << "В группе должно быть не менее двух участников!\n";
			input = false;
			continue;
		}

		Artists_setter(MyArtists, artists_number, musicians);
		

	} while (!input);
}



set<string> copy_check;
void Album_songs_set(Rock_songs& MySongs, const int& album_songs_num, const string& album_name, map <Rock_albums, vector<Rock_songs>>& albums, Rock_albums& MyAlbums)
{
	vector<Rock_songs> vec;
	for (int i = 0; i < album_songs_num; i++)
	{
		cout << "\nВведите название песни альбома: ";
		int changes = copy_check.size();
		string song_name;
		getline(cin, song_name);
		Space_delete(song_name);
		if (song_name.empty() || song_name.find_first_not_of(' ') == string::npos)
		{
			cout << "Названия песен не могут быть пустыми или состоять только из пробелов!\n";
			cout << "Введите другое название: ";
			i--;
			continue;
		}

		// проверка на повторы
		copy_check.insert(song_name);
		if (changes == copy_check.size())
		{
			cout << "В альбоме уже есть такая песня!\n";
			i--;
			continue;
		}
		MySongs.set_song_name(song_name);

		/*cout << "Введите год выпуска песни: ";
		int date;
		check_date(date);
		MySongs.set_release_date(date);*/
		MySongs.set_release_date(MyAlbums.get_release_date());
		Song_time_setter(MySongs);

		vec.push_back(MySongs);		
	}
	albums.emplace(MyAlbums, vec);
	copy_check.clear();
}
void Wrong_album_num_of_songs_checker(int& album_songs_num)
{
	while (album_songs_num < 2)
	{
		cout << "Ошибка!В альбоме должно быть больше одной песни!\n";
		cout << "Введите другое количество: ";
		cin >> album_songs_num;
	}
}
void Wrong_album_name_checker(string& album_name)
{
	while (album_name.empty() || album_name.find_first_not_of(' ') == string::npos)
	{
		if (album_name.empty() || album_name.find_first_not_of(' ') == string::npos)
		{
			cout << "Названия альбомов не могут быть пустыми или состоять только из пробелов!\n";
			cout << "Введите другое название: ";
			getline(cin, album_name);
			continue;
		}
	}
	
}
set <string> my_albums_check;
void Albums_and_songs_setter(Rock_albums& MyAlbums, Rock_songs& MySongs, int albums_number, map <Rock_albums, vector<Rock_songs>>& albums)
{
	while (albums_number > 0)
	{
		string album_name;
		cout << "Введите название альбома: ";
		getline(cin, album_name);
		Wrong_album_name_checker(album_name);
		Space_delete(album_name);

		// проверка на повторы 
		auto iter = my_albums_check.find(album_name);
		if (iter != my_albums_check.end())
		{
			cout << "Уже существует альбом с таким названием!\n";
			continue;
		}
		my_albums_check.insert(album_name);
		MyAlbums.set_album_name(album_name);

		cout << "Введите год выпуска альбома: ";
		//int release_date1;
		int release_date=check_date();
		MyAlbums.set_release_date(release_date);

		albums_number--;
		cout << "Введите количество песен альбома: ";
		int album_songs_num;
		cin >> album_songs_num;
		Wrong_album_num_of_songs_checker(album_songs_num);

		cin.ignore();
		
		Album_songs_set(MySongs, album_songs_num, album_name, albums, MyAlbums);
	}
	my_albums_check.clear();
}
void AlbumsxSongs_reading(Rock_albums& MyAlbums, Rock_songs& MySongs, map <Rock_albums, vector<Rock_songs>>& albums)
{
	bool input = false;
	while (!input)
	{
		input = true;
		int albums_number;
		cout << "Введите количество альбомов группы: ";
		cin >> albums_number;
		cin.ignore();
		if (albums_number < 0)
		{
			cout << "Неверное количество альбомов!\n";
			input = false;
			continue;
		}
		

		if (albums_number > 0)
		{
			Albums_and_songs_setter(MyAlbums, MySongs, albums_number, albums);
		}

	} 
}



int check_date()
{
	int date;
	cin >> date;
	while (date < 1800 || date >2021)
	{
		cout << "Неверная дата!\n";
		cout << "Введите другой год: ";
		cin.ignore();
		cin >> date;
	}
	
	return date;
}
void Song_time_setter(Rock_songs&  MySongs)
{
	bool input = false;
	while (!input)
	{
		input = true;
		cout << "Введите сколько длится песня в минутах и секундах(пример хх.хх): ";
		double time;
		cin >> time;
		if (time - int(time) > 0.59 || time < 0)
		{
			cout << "Неправильное время!\n";
			input = false;
			continue;
		}
		MySongs.set_time(time);
	}
	cin.ignore();
}
set<string> singles_copy_check;
void Single_setter(Rock_songs& MySongs, const int& single_num, vector<Rock_songs>& singles)
{
	for (int i = 0; i < single_num; i++)
	{
		cout << "\nВведите название песни-сингла: ";
		int changes = singles_copy_check.size();
		string single_Name;
		getline(cin, single_Name);
		Space_delete(single_Name);
		if (single_Name.empty() || single_Name.find_first_not_of(' ') == string::npos)
		{
			cout << "Названия песен не могут быть пустыми или состоять только из пробелов!\n";
			cout << "Введите другое название: ";
			i--;
			continue;
		}

		singles_copy_check.insert(single_Name);
		if (changes == singles_copy_check.size())
		{
			cout << "Эта песня уже выпускалась как сингл!\n";
			i--;
			continue;
		}

		MySongs.set_song_name(single_Name);

		cout << "Введите год выпуска песни: ";
		//int date1;
		int date=check_date();
		MySongs.set_release_date(date);
		Song_time_setter(MySongs);

		singles.push_back(MySongs);
	}
	singles_copy_check.clear();
}
void Wrong_single_num_checker(int& single_num)
{
	while (single_num < 0)
	{
		cout << "Количество синглов не может быть отрицательным!\n";
		cout << "Введите другое количество: ";
		cin >> single_num;
	}
}
void Single_songs_reading(Rock_songs& MySongs, vector<Rock_songs>& singles)
{
	cout << "Введите количество песен-синглов: ";
	int single_num;
	cin >> single_num;
	cin.ignore();
	Wrong_single_num_checker(single_num);
	

	if (single_num > 0)
		Single_setter(MySongs, single_num, singles);
}


void Output(info grup);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool input = false;
	int num;
	while (!input)
	{
		input = true;
		cout << "Введите количество групп: ";
		cin >> num;
		if (num < 1)
		{
			cout << "Неверное количество!";
			input = false;
			continue;
		}
	}
	cin.ignore();
	vector<info> grups(num);

	vector<Rock_artists> musicians;
	map <Rock_albums, vector<Rock_songs> > albums;
	vector<Rock_songs> singles;

	for (int i = 0; i < num; i++)
	{
		info myinfo;
		Rock_Grup MyGrup;
		Name_reading(MyGrup);
		myinfo.name = MyGrup;

		Rock_artists MyArtists;
		Artists_reading(MyArtists, musicians);
		myinfo.musicians = musicians;
		musicians.clear();

		Rock_albums MyAlbums;
		Rock_songs MySongs;
		AlbumsxSongs_reading(MyAlbums, MySongs, albums);
		myinfo.albums = albums;

		Single_songs_reading(MySongs, singles);
		myinfo.singles = singles;

		grups.push_back(myinfo);
	}

	cout << "\n" << "Вы успешно заполнили данные о рок-группе!\n\n";

	cout << "Вывод данных:\n";
	cout << "Введите название группы: ";
	string grup_name;
	getline(cin, grup_name);
	Space_delete(grup_name);
	int i = 0;
	bool find = false;
	while (i < num + 1)
	{
		if (grup_name == grups[i].name.Get_grupname())
		{
			find = true;
			Output(grups[i]);
			break;
		}
		i++;
	}
	if (!find)
		cout << "Нет информации о такой группе!\n";
}



void print_artists(vector<Rock_artists>vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout <<"\nИмя: " << vec[i].get_artist_name() << '\n';
		cout << "Профессия: " << vec[i].get_artist_profession() << '\n';
		cout << "Год рождения: " << vec[i].get_artist_birth_date() << '\n';
	}
}

void albums_count(const info&  grup, int& number)
{
	auto iter = grup.albums.begin();
	for (iter; iter != grup.albums.end(); iter++)
		number++;
}

void print_albums(map <Rock_albums, vector<Rock_songs> > albums)
{
	auto i = albums.begin();
	for (i; i != albums.end(); i++)
	{
		cout << '\n';
		cout << "\nНазвание альбома: " << i->first.get_album_name() << '\n';
		//cout << "\nГод выпуска альбома: " << i->first.get_release_date() << '\n\n';

		cout << "\nПесни альбома:\n";
		for (int j = 0; j != i->second.size(); j++)
		{
			cout<<"\nНазвание песни: "<<i->second[j].get_song_name()<< '\n';
			cout<<"\nДлительность: "<<i->second[j].get_time() << '\n';
		}
	} 
}

void print_singles(vector<Rock_songs> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << "Название: " << vec[i].get_song_name() << '\n';
		cout << "Длительность: " << vec[i].get_time() << '\n';
		cout << "Год Выпуска: " << vec[i].get_release_date() << '\n';
		cout << '\n';
	}
}

void Output(info grup)
{
	int command;

	do
	{
		cout << '\n';
		cout << "Введите команду для вывода данных о рок-группе вам нужны?(для просмотра команд введите 1.): ";
		cin >> command;
		cout << '\n';

		if (command == 1)
		{
			cout << "2. Вывести название рок-группы." << '\n';
			cout << "3. Вывести количество музыкантов рок-группы." << '\n';
			cout << "4. Вывести данные музыкантов рок-группы." << '\n';
			cout << "5. Вывести количество альбомов рок-группы." << '\n';
			cout << "6. Вывести данные альбомов рок-группы." << '\n';
			cout << "7. Вывести количество всех синглов рок-группы." << '\n';
			cout << "8.Вывести данные всех синглов рок-группы." << '\n';
			cout << "0. Выход." << '\n';
			cout << "Введите номер команды: ";
			cin >> command;
			cout << '\n';
		}
		switch (command)
		{
		case 2:
		{
			cout << "Название рок-группы: " << grup.name.Get_grupname() << '\n';
			break;
		}

		case 3:
		{
			cout << "Количество музыкантов рок-группы:\n" << grup.musicians.size() << '\n';;
			break;
		}

		case 4:
		{
			cout << "Данные музыкантов рок-группы:\n";
			print_artists(grup.musicians);
			break;
		}

		case 5:
		{
			cout << "Количество альбомов рок-группы: ";
			int number = 0;
			albums_count(grup, number);
			cout << number << '\n';
			break;
		}

		case 6:
		{
			int number=0;
			albums_count(grup, number);
			if (number < 1)
			{
				cout << "У данной рок-группы нет альбомов";
				break;
			}

			cout << "Данные альбомов рок - группы:\n";
			print_albums(grup.albums);
			break;
		}


		case 7:
		{
			cout << "Количество всех синглов рок-группы: " << grup.singles.size() << '\n';;
			break;
		}

		case 8:
		{
			if (grup.singles.size() == 0)
			{
				cout << "Нет синглов у этой группы!";
				break;
			}
			cout << "Данные всех синглов рок-группы:\n";
			print_singles(grup.singles);
			break;
		}

		
		default:
		{
			cout << "Неправильный номер команды" << '\n';
			break;
		}


		case 0: break;


		}


	} while (command != 0);
}