#include "Team.h"
#include "FileDB.h"

void Team::Initialize(System::String^ row)
{
	array<String^>^ parts = row->Split(';');
	if (parts->Length != 3)
	{
		throw gcnew Exception("incorrect row");
	}

	id = Convert::ToInt32(parts[0]);
	name = parts[1];
	sportId = Convert::ToInt32(parts[2]);
	sport = FileDB::GetEntityById<KindOfSport^>(sportId);
}

System::String^ Team::GetFileName()
{
	return "teams.txt";
}

System::String^ Team::GetFileStr()
{
	return Convert::ToString(id) + ";" +
		name + ";" +
		Convert::ToString(sportId);
}

int Team::GetId()
{
	return id;
}

void Team::SetId(int newId)
{
	if (newId <= 0)
	{
		throw gcnew Exception("incorrect new id");
	}

	id = newId;
}
