#pragma once

#include "Command.h"
#include "Game.h"
#include "FileDB.h"

using namespace System;

public ref class GoalCommand : Command
{
	Game^ game;

	void addGoal(bool isFirstTeam)
	{
		if (isFirstTeam)
		{
			game->firstScore++;
		}
		else
		{
			game->secondScore++;
		}
		FileDB::Update(game);
	}
public:
	GoalCommand(Game^ game) : game(game)
	{ }

	String^ getHelpMessage() override
	{
		return "write a goal to team score";
	}
	String^ getCommandName() override
	{
		return "goal";
	}

	void execute() override
	{
		Console::WriteLine("Напишите 1 если это первая команда, и напишите 2, если это вторая команда");
		int team = Console::ReadLine() == "1" ? 1 : 2;
		
		addGoal(team == 1);
	}
};