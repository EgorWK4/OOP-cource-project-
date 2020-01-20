#include "Player.h"
#include "FileDB.h"

void Player::Initialize(System::String^ row)
{
	array<String^>^ parts = row->Split(';');

	id = Convert::ToInt32(parts[0]);
	firstName = parts[1];
	secondName = parts[2];
	teamId = Convert::ToInt32(parts[3]);
	age = Convert::ToInt32(parts[4]);
	experience = Convert::ToInt32(parts[5]);

	team = FileDB::GetEntityById<Team^>(teamId);
}

System::String^ Player::GetFileName()
{
	return "players.txt";
}

System::String^ Player::GetFileStr()
{
	return Convert::ToString(id) + ";" +
		firstName + ";" +
		secondName + ";" +
		Convert::ToString(teamId) + ";" +
		Convert::ToString(age) + ";" +
		Convert::ToString(experience);
}

int Player::GetId()
{
	return id;
}

void Player::SetId(int newId)
{
	if (newId <= 0)
	{
		throw gcnew Exception("incorrect new id");
	}

	id = newId;
}
