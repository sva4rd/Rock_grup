#include"Rock_Grup.h"


void Rock_Grup::Set_grupname(const string name)
{
	if (name.empty() || name.find_first_not_of(' ') == string::npos)
		throw exception("�������� ������ �� ����� ���� ������ ��� �������� �� ��������!");
	grup_name = name;
}

string Rock_Grup::Get_grupname() const
{
	return grup_name;
}