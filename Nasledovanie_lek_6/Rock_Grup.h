#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

class Rock_Grup
{
protected:
	string grup_name;
public:
	void Set_grupname(const string name);
	string Get_grupname() const;
};