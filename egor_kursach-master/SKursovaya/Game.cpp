#include "Game.h"
#include "FileDB.h"

void Game::Initialize(System::String^ row)
{
	array<String^>^ parts = row->Split(';');

	if (parts->Length != 6)
	{
		throw gcnew Exception("incorrect row\nrow: " + row);
	}

	id = Convert::ToInt32(parts[0]);
	firstTeamId = Convert::ToInt32(parts[1]);
	secondTeamId = Convert::ToInt32(parts[2]);
	isFinished = parts[3] == "1";
	firstScore = Convert::ToInt32(parts[4]);
	secondScore = Convert::ToInt32(parts[5]);

	firstTeam = FileDB::GetEntityById<Team^>(firstTeamId);
	secondTeam = FileDB::GetEntityById<Team^>(secondTeamId);
}

System::String^ Game::GetFileName()
{
	return "games.txt";
}

System::String^ Game::GetFileStr()
{
	String^ res = Convert::ToString(id) + ";";
	res += Convert::ToString(firstTeamId) + ";";
	res += Convert::ToString(secondTeamId) + ";";
	res += (isFinished ? "1" : "0") + ";";
	res += Convert::ToString(firstScore) + ";";
	res += Convert::ToString(secondScore);

	return res;
}

int Game::GetId()
{
	return id;
}

void Game::SetId(int newId)
{
	if (newId <= 0)
	{
		throw gcnew Exception("incorrect new id");
	}

	id = newId;
}

bool Game::operator<(Game^ other)
{
	return firstScore < other->firstScore && secondScore < other->secondScore;
}

bool Game::operator>(Game^ other)
{
	return firstScore > other->firstScore && secondScore > other->secondScore;
}

Game::Game()
{
	warnings = gcnew List<Warning^>();
}