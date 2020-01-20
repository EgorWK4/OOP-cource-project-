#pragma once

using namespace System;

#include "Command.h"
#include "Game.h"
#include "FileDB.h"

public ref class ListGamesCommand : Command
{
public:
	String^ getHelpMessage() override
	{
		return "print all games";
	}
	String^ getCommandName() override
	{
		return "printGames";
	}

	void execute() override
	{
		auto games = FileDB::GetDataFromFile<Game^>();

		for each (Game^ game in games)
		{
			Console::WriteLine("Game ¹{0}:" +
				"\n\tfirst team: {1}" +
				"\n\tsecond team: {2}" +
				"\n\tis finished: {3}" +
				"\n\tfirst team score: {4}" + 
				"\n\tsecond team score: {5}",
				game->id, game->firstTeam->name, game->secondTeam->name, 
				game->isFinished, game->firstScore, game->secondScore);
		}
	}
};